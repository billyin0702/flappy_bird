
# pragma once
# include <ge211.hxx>
# include "bird.hxx"

struct Pipe
{
    /// constructor for pipe
    Pipe(Game_config const& config);

    /// functions
    // update the position of the individual pipe
    void update_pipe(float dt, Velocity bird_vel);

    /// fields for pipe
    std::vector<Block> the_pipe; // the vector containing the pipe blocks

    // whether the pipe has been removed from the "queue", assist in
    // determining whether the pipe has hit the left side of the screen
    bool removed;

    // whether the pipe is currently moving or not
    bool moving;
};
