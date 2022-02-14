//
// Created by Bill Yin on 2021/5/25.
//

# pragma once
# include <ge211.hxx>
# include <array>
# include "powerups.hxx"

struct Game_config{
    /// constructor and functions
    Game_config();

    /// General
    ge211::Dims<int> screen_dims; // dimensions of the play screen

    /// bird info
    int bird_radius; // initial radius of the bird

    ge211::Dims<float> bird_velocity; // initial velocity of the bird

    ge211::Posn<int> initial_pos; // initial position of the bird

    float bird_max_up_vel; // the maximum upward velocity allowed for the bird

    // the amount of upward velocity gained by the bird each click
    int up_vel_max_each;


    /// power up info
    int powerup_side;
    ge211::Dims<int> powerup_dims; // dimension of the poewrup cubes

    int powerup_num; // number of powerups varieties

    // percentage of chance a powerup will drop (between 0 and 1)
    float powerup_odds;

    // how much each powerup will scale by
    double powerup0_scale;
    double powerup1_scale;
    double powerup2_scale;

    /// pipes info
    int pipe_width; // the width of the pipes

    // the minimum number of blocks before any blocks are removed
    int min_top_blocks;
    int min_bottom_blocks;

    // the number of blocks that will be removed (the gap in the pipe)
    int pipes_diff_height;
    ge211::Color pipe_color;

    // the distance between each set of pipes
    int distance_between_pipes;

    // the number of blocks that will represent each pipe
    int verti_blocks;
    int pipe_height; // should always be an integer



};
