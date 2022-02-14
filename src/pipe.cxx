
#include "pipe.hxx"

Pipe::Pipe(Game_config const& config)
    :removed(false),
    moving(false)
{
    // fill in the block arrays here, remove 2 randomly in model
    // calculate the number of blocks each pipe has randomly
    float y_init = 0;
    float x_init = config.screen_dims.width;
    float block_height = config.screen_dims.height/config.verti_blocks;

    // pipe initiation is not the problem here, look in model
    for (size_t i = 0; i < config.verti_blocks; i++){
        the_pipe.push_back({x_init,y_init,
                            float(config.pipe_width),block_height});
        y_init += block_height;
    }

}


// update the position of the pipe because the pipes themselves are not moving
void
Pipe::update_pipe(float dt, Velocity bird_vel){
    for (size_t i = 0; i < the_pipe.size(); i++){
        // use birds velocity so the powerups will work
        the_pipe[i].x = the_pipe[i].x - bird_vel.width*dt;
    }
}
