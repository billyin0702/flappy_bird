#pragma once

#include <ge211.hxx>
#include "pipe.hxx"

struct Model{
    /// constructor for model
    explicit Model(Game_config const& config = Game_config());

    /// functions
    void on_frame(float dt); // the pipes update logic is here

    /// update the bird to fly up instead without acc.
    void flip_bird_up();

    /// removes 1 pipe's blocks
    void one_remove_pipe(Pipe &p);

    /// modify the pipes to remove 2 blocks at random
    void remove_pipe_blocks();

    /// check to see if the bird hit any part of the pipe
    bool bird_hit_pipe(Bird bird) const;

    /// pipe hits the side the screen
    bool pipe_hit_left(Pipe p) const;

    /// adds a new pipe
    void add_pipe();

    /// adds a random powerup, helper for drop_powerup
    /// take the first removed blocks y_value
    void add_powerup(float value);

    /// drop a new random powerup at the center of a pipe
    /// helper for remove_pipe_blocks
    void drop_powerup(float value);

    /// remove powerup from the list
    void remove_powerup(Powerup &pu);

    /// bird hits a powerup?
    void bird_hits_powerup();

    /// variables
    Game_config const config;

    // vector of pipes, each containing a vector of pipe blocks
    std::vector<Pipe> pipes;

    // vector of powerups
    std::vector<Powerup> powerups;

    Bird bird;

    // generates a random number to indicate which blocks in the pipe to remove
    ge211::Random_source<float> random_pipe_block;

    // generates a random number to indicate the type of powerup to drop
    ge211::Random_source<float> random_powerup;

    // generates a random number to indicate whether any powerups will drop
    ge211::Random_source<float> drop_powerup_rand;

    // the amount of distance after a pipe has started moving from its default
    // position
    float width;

    // has the game been started
    bool started;

    // the current score of the player, adds after each pipe has been moved
    // of the screen (indicating the bird has successfully passed through one)
    int score;



};

