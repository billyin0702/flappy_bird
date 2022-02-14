#pragma once


# pragma once
# include <ge211.hxx>
# include "game_config.hxx"
# include <cstdlib>



struct Bird{

    /// constructor
    Bird(Game_config const& config);

    /// set bird live
    void set_bird_live();

    /// top_left of the bird
    Position top_left_bird() const;

    /// velocity of the bird

    /// next position of bird
    Bird next(float dt) const;

    /// change velocity of the bird
    void up(float value);

    /// hits top of the screen?
    bool hits_top(Game_config) const;

    /// hits bottom of the screen?
    bool hits_bottom(Game_config) const;

    /// bird hits brick?
    bool hits_brick(Block block) const;

    /// reset bird to starting point
    void reset_bird();

    /// collide with power_ups? which one?
    int collide_powerup(Powerup, Game_config) const;


    /// find which power-ups the bird has
    bool powerup_change(Powerup, Game_config);



    /// define fields for the bird
    // radius of the bird (it is interpreted as a circle)
    float radius;

    // the center of the bird, will change
    Position center;

    // the initialized position of the bird, used for resetting the bird
    Position initial_center;

    // velocity of the bird (width -> for pipes, height -> for bird)
    Velocity velocity;

    // the initial velocity of the bird as initialized by game_config
    Velocity initial_vel;

    // if the bird is still flying at this stage
    bool live;

    // see if the bird is immune and able to reset when it his the top of the
    // screen
    bool top_immunity;

    // grants the bird full immunity, meaning the "live" field will always be
    // true
    bool immunity;
};