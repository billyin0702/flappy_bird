#include "model.hxx"

Model::Model(Game_config const& config)
    :config(config),
    bird(config),
    random_pipe_block(config.min_top_blocks,
                      config.verti_blocks-config.pipes_diff_height-config
                      .min_bottom_blocks),
    random_powerup(0,3),
    drop_powerup_rand(0,1),
    width(0),
    started(false),
    score(0)
    //
    // power_ups will be added accordingly
    //
{
    // initiate the blocks vector here
    // downcast from float to int here
    int vec_size = int(config.screen_dims.width/
            (config.pipe_width + config.distance_between_pipes))+1;
    // needs to do push backs on the vector of pipes
    for (size_t i = 0; i < vec_size; i++){
        // the ratio that can be randomized
        pipes.push_back(Pipe(config));
    }
    remove_pipe_blocks();

}

/// update the bird to fly up
void
Model::flip_bird_up()
{
    // so that the bird won't just leap away into infinity
    if (bird.velocity.height >= config.bird_max_up_vel) {
        bird.up(config.up_vel_max_each);
    }
}

/// removes one pipe's blocks, directly accessing the memory of the pipe to
/// make appropriate changes
// no more temp variables, it doesn't work in C++
void
Model::one_remove_pipe(Pipe &p) {
    int random_value = int(random_pipe_block.next());
    // check to see if the pipe has already been removed
    if (!p.removed) {
        p.removed = true;
        // remove the given blocks
        for (size_t j = 0; j < p.the_pipe.size(); j++) {
            if (random_value == j) {
                for (size_t z = 0; z < config.pipes_diff_height; z++) {
                    p.the_pipe[j+z] = p.the_pipe.back();
                    p.the_pipe.pop_back();
                }
                // drop powerups at random after the first stage
                if (started) {
                    drop_powerup(j*config.pipe_height);
                }
                break;
            }
        }
    }
}

/// remove the randomized blocks on queue
void
Model::remove_pipe_blocks(){
    for (size_t i = 0; i < pipes.size();i++){
        one_remove_pipe(pipes[i]);
    }
}

/// check to see if the bird hits any part of the pipe
bool
Model::bird_hit_pipe(Bird bird1) const{
    for (size_t i = 0; i < pipes.size(); i++){
        for (size_t j = 0; j < pipes[i].the_pipe.size(); j++){
            if (bird1.hits_brick(pipes[i].the_pipe[j])){
                // I cannot do...
                // return bird1.hits_brick(pipes[i].the_pipe[j]) because that
                // will only allow the function to evaluate the first block
                return true;
            }
        }
    }
    return false;
}

/// pipes hit left
bool
Model::pipe_hit_left(Pipe p) const{
    return p.the_pipe[0].x+p.the_pipe[0].width <= 0;
}


/// add a new pipe
void
Model::add_pipe(){
    Pipe pipe = Pipe(config);
    one_remove_pipe(pipe);
    pipes.push_back(pipe);
}


/// add a power_up
void
Model::add_powerup(float value){
    float x_loc = config.screen_dims.width + config.pipe_width/2 - config
            .powerup_dims.width/2;
    float y_loc = value + (config.pipes_diff_height-1)*config.pipe_height/2;
    powerups.push_back(Powerup({x_loc,y_loc,
                                float(config.powerup_dims.width),
                                float(config.powerup_dims.height)},
                               int(random_powerup.next())));
}

/// drop a new_power up
void
Model::drop_powerup(float value){
    if (drop_powerup_rand.next() <= config.powerup_odds){
        add_powerup(value);
    }
}

/// remove powerup
void
Model::remove_powerup(Powerup &pu){
    // will never be empty when called
        pu = powerups.back();
        powerups.pop_back();
}

/// changes the bird according to the powerup
void
Model::bird_hits_powerup(){
    for (size_t i = 0; i < powerups.size(); i++){
        if (bird.powerup_change(powerups[i],config)) {
            // powerup will be removed
            remove_powerup(powerups[i]);
            break;
        }
    }
}

/// on frame logic

void
Model::on_frame(float dt){
    // create an instance of the bird to examine
    Bird bird_temp = bird.next(dt);

    if (!bird.live && started) {
        // if the bird is not live when the pipes started moving already,
        // then the game is over
        throw ge211::Client_logic_error("You have crashed, game over");
    }

    // second, move the pipes
    for (size_t i = 0; i < pipes.size(); i++){
        // the first pipe
        if (!pipes[i].moving && !started){
            pipes[i].moving = true;
            started = true;
        }

        // if pipe is not moving start to move it when the other pipe is
        // a given distance apart
        if (!pipes[i].moving && started &&
                width >= config.distance_between_pipes){
            width = 0;
            pipes[i].moving = true;
        }

        // update the pipes, only once for the entire
        if (pipes[i].moving){
            pipes[i].update_pipe(dt,bird.velocity);
        }

        // test to see if the pipe has hit the left of the screen
        if (pipe_hit_left(pipes[i])){
            // remove the current pipe and add a new pipe
            pipes[i] = pipes.back();
            pipes.pop_back();
            add_pipe();
            score++;
        }
    }
    // update the width after each iteration
    width += bird.velocity.width*dt ;

    // if the bird hits the pipe or the bottom of the screen
    // or the top of the screen more than once
    if (!bird.immunity) {
        if (bird_hit_pipe(bird_temp) ||
            bird.hits_bottom(config) ||
            (bird.hits_top(config) && !bird.top_immunity)) {
            bird.live = false;
        }

        // if the bird hits the top of the screen, reset once
        if (bird.hits_top(config) && bird.top_immunity) {
            bird.reset_bird();
        }
    }
    // test if the bird has hit a power up
    bird_hits_powerup();

    // move the power_ups
    // remove power up if it goes past the screen
    for (size_t i = 0; i < powerups.size(); i++){

        // remove the given powerup if it pass the left side of screen
        if (powerups[i].powerup_block().x + powerups[i].powerup_block()
        .width<= 0) {
            remove_powerup(powerups[i]);
        }

        // update the position of the power up accordingly
        Position update = {powerups[i].powerup_block().x - bird.velocity
                           .width*dt,powerups[i].powerup_block().y};
        powerups[i].update_position(update);
    }


    // lastly, update the bird
    bird = bird.next(dt);
}