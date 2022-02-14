#include "model.hxx"
#include <catch.hxx>

Game_config const config = Game_config();
float const dt = 1;

TEST_CASE("example test just for the lols")
{
    CHECK( 1 + 1 == 2 );
}


/// functional requirements testing
TEST_CASE("FR 4: Game will end if it hits the bottom of the screen")
{
    Model model(config);

    // start the game first
    model.bird.set_bird_live();

    // move the bird to just above the bottom of the screen
    model.bird.center = {model.bird.center.x,
                         float(config.screen_dims.height-config.bird_radius+1)};

    // one more dt before the bird hits the bottom of the screen
    CHECK(model.bird.live);

    // dt = 1
    // initial velocity downwards = 8 pixels/sec
    model.on_frame(dt);

    // expected position of bird's center {80,493}
    // the radius should be touching the bottom of the screen
    CHECK_FALSE(model.bird.live);
    CHECK(model.bird.hits_bottom(config));
    CHECK_THROWS_AS(model.on_frame(dt),
                    ge211::Client_logic_error);

    // the bird should dead now and it has hit the bottom of the screen

}

TEST_CASE("FR 6: Hits the pipe, the game ends")
{
    Model model(config);

    // start the game first
    model.bird.set_bird_live();

    // move the bird to just below the top of the screen
    // 1. since config.min_top_blocks stated there will always be at least 2
    // blocks just below the top of the screen, move bird there to collide
    // with pipes
    // 2. the pipe is moving at -200 pixels a second, so place it in a place
    // where the bird and the first pipe will collide
    model.bird.center = {float(config.screen_dims.width)-config.bird_velocity
                         .width-config.bird_radius,25};
    // one more dt before the bird hits the bottom of the screen
    CHECK(model.bird.live);
    model.on_frame(dt);

    // has successfully collided with the pipe
    CHECK_FALSE(model.bird.live);
    CHECK(model.bird_hit_pipe(model.bird));
    CHECK_THROWS_AS(model.on_frame(dt),
                    ge211::Client_logic_error);

}

TEST_CASE("FR 7: The on_frame moves the y_position but not the x_position")
{
    Model model(config);

    // start the game first
    model.bird.set_bird_live();

    // one more dt before the bird hits the bottom of the screen
    CHECK(model.bird.live);
    float init_x = model.bird.center.x;
    float init_y = model.bird.center.y;

    // move the bird by one frame, check for variable equivalence
    model.on_frame(dt);

    CHECK(model.bird.center.x == init_x);
    CHECK_FALSE(model.bird.center.y == init_y);

}

TEST_CASE("FR 10: The x_velocity of the bird/pipes should be constant")
{
    Model model(config);

    // set bird to be live first
    model.bird.live = true;

    // the x_velocity should never change before hitting power_ups
    CHECK(model.bird.velocity.width == model.config.bird_velocity.width);

    // move forward by one frame to check equivalence over time
    model.on_frame(dt);

    CHECK(model.bird.velocity.width == model.config.bird_velocity.width);
}

TEST_CASE("FR 11: The powerups")
{
    Model model(config);

    // set bird live
    model.bird.set_bird_live();

    // forcefully collide the bird with powerups
    // default to size increase
    Powerup pu = {{float(config.initial_pos.x),float(config.initial_pos.y),
                   float(config.powerup_dims.width),
                   float(config.powerup_dims.height)},0};
    model.powerups.push_back(pu);

    // make sure the bird has collided with the powerup
    CHECK(model.bird.powerup_change(model.powerups[0],config) <
          config.powerup_num);
    CHECK(model.bird.radius == 1.1* config.bird_radius);

    // continuously collide to see maximum limit
    // the limit should be 200% for size increase
    float value = 1.1;
    for (int i = 0; i < 9; i++) {
        model.bird.powerup_change(model.powerups[0], config);
        if (value < 2) {
            value *= 1.1;
        }
    }

    int check_value = value*config.bird_radius;
    // make sure they are equal
    CHECK(int(model.bird.radius) == check_value);

    // check if maximum has been reached
    // if so, no more change
    model.bird.powerup_change(model.powerups[0], config);
    CHECK(int(model.bird.radius) == check_value);


    // reset the bird and reset the powerups vector
    model.bird = Bird(config);
    model.bird.set_bird_live();
    model.powerups.clear();

    pu = {{float(config.initial_pos.x),float(config.initial_pos.y),
                   float(config.powerup_dims.width),
                   float(config.powerup_dims.height)},1};

    model.powerups.push_back(pu);


    // make sure the bird has collided with the powerup
    CHECK(model.bird.powerup_change(model.powerups[0],config) <
          config.powerup_num);
    CHECK(model.bird.radius == 0.9* config.bird_radius);

    // continuously collide to see maximum limit
    // the limit should be 50% for size decrease
    value = 0.8;
    for (int i = 0; i < 9; i++) {
        model.bird.powerup_change(model.powerups[0], config);
        if (value > 0.5) {
            value *= 0.9;
        }
    }

    check_value = int(value*config.bird_radius);
    // make sure they are equal
    CHECK(int(model.bird.radius) == check_value);

    // check if minimum size has been reached
    // if so, no more change
    model.bird.powerup_change(model.powerups[0], config);
    CHECK(int(model.bird.radius) == check_value);
}

TEST_CASE("FR 12: The bird can collide into the top of screen only once")
{
    Model model(config);

    // set bird to be live first
    // set bird x_velocity to be zero to avoid collision with pipe
    model.bird.live = true;
    model.bird.velocity.width = 0;

    // initial checking
    CHECK(model.bird.live);
    CHECK_FALSE(model.bird.hits_top(config));
    CHECK(model.bird.top_immunity);

    // each time bird goes up, velocity adds 200 pixels/sec
    for (size_t i = 0; i < 2; i++){
        model.flip_bird_up();
        model.on_frame(dt);
    }

    // should hit top now
    CHECK(model.bird.hits_top(config));

    // next frame the bird's position should be reset
    // and the bird's top immunity should be taken away
    model.on_frame(dt);
    CHECK(model.bird.center.x == model.config.initial_pos.x);
    CHECK(model.bird.center.y - model.config.bird_velocity.height ==
                                            model.config.initial_pos.y);

    CHECK_FALSE(model.bird.top_immunity);

    // hits the top of the screen again, but this time the game should end
    for (size_t i = 0; i < 3; i++){
        model.flip_bird_up();
        model.on_frame(dt);
    }

    CHECK(model.bird.hits_top(config));
    CHECK_FALSE(model.bird.live);
    CHECK_THROWS_AS(model.on_frame(dt),
                    ge211::Client_logic_error);
}


/// other functional tests
TEST_CASE("Pipes will reset when they hit the left of the screen")
{
    Model model(config);

    // start the game first
    model.bird.set_bird_live();

    // one more dt before the bird hits the bottom of the screen
    CHECK(model.bird.live);

    // set the bird to be immune for testing purposes, so it won't end the game
    // note: please do not exploit this in the real game LOL unless necessary
    model.bird.immunity = true;

    // the x_velocity of the bird/pipe is 200 and screen dims = 900
    // move the pipes for 4 seconds, which places them 100 pixels away from the
    // left side of the screen
    for (size_t i = 0 ; i < 4; i++){
        model.on_frame(dt);
    }

    CHECK_FALSE(model.pipe_hit_left(model.pipes[0])); // leftmost pipe

    // one final update, the pipe should be reset now
    model.on_frame(dt);

    // the first pipe has now been reset to outside the right border
    CHECK_FALSE(model.pipe_hit_left(model.pipes[0]));
    CHECK(model.pipes[0].the_pipe[0].x == 900);

}

TEST_CASE("Bird will move up")
{
    Model model(config);

    // set the bird live
    model.bird.set_bird_live();

    // make sure the initial velocity is downward, > 0
    CHECK(model.bird.velocity.height > 0);

    // bird should now be moving upward, < 0
    // should be the case after one frame as well
    model.flip_bird_up();

    CHECK(model.bird.velocity.height < 0);

    model.on_frame(dt);

    CHECK(model.bird.center.y < config.initial_pos.y);
    CHECK(model.bird.velocity.height < 0);
}

TEST_CASE("Powerup will drop and bird will collide")
{
    Model model(config);

    model.bird.set_bird_live();

    // add a powerup, now there should be a random powerup given a specific
    // y_posn value
    model.add_powerup(config.initial_pos.y);
    CHECK_FALSE(model.powerups.size() == 0);

    // force bird to collide
    // if the value if model.bird.powerup_change is within the size,
    // then it means the bird collided with one powerup
    CHECK(model.bird.powerup_change(model.powerups[0],config) <
                                            config.powerup_num);
}