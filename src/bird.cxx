
# include "bird.hxx"

/// constructs the bird
Bird::Bird(Game_config const& config)
            :radius(config.bird_radius),
            center(config.initial_pos),
            initial_center(config.initial_pos),
            velocity(config.bird_velocity),
            initial_vel(config.bird_velocity),
            live(false),
            top_immunity(true),
            immunity(false)
{}

/// set the bird free
void
Bird:: set_bird_live(){
    live = true;
}


/// returns the top left of the bird
Position
Bird:: top_left_bird() const{
    return {center.x - radius,center.y-radius};
}

/// calculates the next position of the bird, similar to "Ball next"
/// gravity lowers it automatically
Bird
Bird::next(float dt) const{
    Bird result(*this);
    if (live) {
        result.center.y = result.center.y + dt * velocity.height;
        result.velocity.height += initial_vel.height;
    }
    return result;
}

/// changes the velocity of the bird
void
Bird::up(float value){
    velocity.height += value;
}

/// bird hits top of the window or not
bool
Bird::hits_top(Game_config config) const{
    return center.y + radius < 0;
}

/// bird hits bottom of the window or not
bool
Bird::hits_bottom(Game_config config) const{
    return center.y + radius > config.screen_dims.height;
}

/// does the bird hits the given brick?
bool
Bird::hits_brick(Block block) const{
    bool pass_top = !(block.y  > (center.y + radius));
    bool pass_left = !(block.x  > (center.x + radius));
    bool pass_right = !((block.x + block.width) < (center.x - radius));
    bool pass_bottom = !((block.y + block.height) < (center.y - radius));

    return pass_top & pass_left & pass_right & pass_bottom;
}

/// reset the bird to its original settings as specified by config
void
Bird::reset_bird(){
    center = initial_center;
    velocity = initial_vel;
    top_immunity = false;
}

/// collide with power_ups? which one?
// return a index outside of the array so it won't work
int
Bird::collide_powerup(Powerup pu, Game_config gc) const{
    if (hits_brick(pu.powerup_block())){
        return pu.powerup_index();
    }
    return gc.powerup_num+1;
}

/// find the power-up that the bird is going to have
/// power_up 0: increase size by 10%, will stop at 200%
/// power_up 1: decrease size by 10% (low-key op lol), will stop at 50%
/// power_up 2: speed up the bird by 10%, will stop at 200%
bool
Bird::powerup_change(Powerup pu, Game_config config){
    /// the specific power_up and how they manipulate the bird
    int pu_index = collide_powerup(pu,config);
    if (pu_index == 0 && radius <= config.bird_radius*2){
        radius = radius*1.1;
    }

    if (pu_index == 1 && radius >= config.bird_radius*0.5){
        radius = radius*0.9;
    }

    if (pu_index == 2 && velocity.width <= config.bird_velocity.width*2){
        velocity = velocity*1.1 ;
    }
    return pu_index < config.powerup_num;
}

