# include "game_config.hxx"

/// constructor first
Game_config::Game_config()
    :screen_dims({900,504}),
    bird_radius(20), /// do not change this so the image will work
    bird_velocity{200,8}, // height is going down as it gets larger
    initial_pos{80,screen_dims.height/2},
    bird_max_up_vel(-300),
    up_vel_max_each(-201), // upward so reducing pixels, approaching 0
    powerup_side(25),
    powerup_dims({powerup_side,powerup_side}),
    powerup_num(3),
    powerup_odds(0.2),
    powerup0_scale(0.03),
    powerup1_scale(0.07),
    powerup2_scale(0.06),
    // the pipes will be shifted on and off the screen
    pipe_width(50),
    min_top_blocks(2),
    min_bottom_blocks(2),
    pipes_diff_height(7), // number of bricks removed
    pipe_color{78,176,28 },
    distance_between_pipes(301),
    verti_blocks(24),
    pipe_height(screen_dims.height/verti_blocks)
{}