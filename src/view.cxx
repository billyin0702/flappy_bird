
# include "view.hxx"
# include "model.hxx"

/// initializes the view struct
View::View(const Model& m)
    :model(m),
    bird_sprite("bird.png"),
    // use a vector of blocks inside the array to represent a pipe
    // power_up colors will change
    powerup_sprite0("up.png"),
    powerup_sprite1("down.png"),
    powerup_sprite2("right.png"),
    background("background.png"),
    pipe_sprite({m.config.pipe_width,
                 m.config.screen_dims.height/m.config.verti_blocks},
                 m.config.pipe_color)
{}

/// responsible for drawing
void
View::draw(ge211::Sprite_set& sprites){
    // if the bird's size gets modified, use an adjusted size
    // after inspection, the bird image sprite actually gets added at the center
    // of the circle
    ge211::Posn<int> adjusted =
            {int (model.bird.top_left_bird().x- model.bird.radius),
             int (model.bird.top_left_bird().y-model.bird.radius/5)};
    double bird_scale = model.bird.radius/float(model.config.bird_radius);
    sprites.add_sprite(bird_sprite,adjusted,0,
                       ge211::Transform::scale(bird_scale));



    // add the pipes and the spacing between
    for (size_t i = 0; i < model.pipes.size(); i++) {
        for (size_t j = 0; j < model.pipes[i].the_pipe.size();j++){
            Block curr = model.pipes[i].the_pipe[j];
            ge211::Posn<int> curr_posn = {int(curr.x),int(curr.y)};
            sprites.add_sprite(pipe_sprite,curr_posn);
        }
    }

    // add the background
    sprites.add_sprite(background,{0,0},-1);


    // adding the power_ups
    for (size_t i = 0; i < model.powerups.size(); i++) {
        int powerup_index = model.powerups[i].powerup_index();
        ge211::Posn<int> powerup_posn = {
                (int)model.powerups[i].powerup_block().x,
                (int)model.powerups[i].powerup_block().y};

        if (powerup_index == 0){
            sprites.add_sprite(powerup_sprite0,powerup_posn,1,
                               ge211::Transform::scale(model.config
                               .powerup0_scale));
        }

        if (powerup_index == 1){
            sprites.add_sprite(powerup_sprite1,powerup_posn,1,
                               ge211::Transform::scale(model.config
                               .powerup1_scale));
        }

        if (powerup_index == 2){
            sprites.add_sprite(powerup_sprite2,powerup_posn,1,
                               ge211::Transform::scale(model.config
                                .powerup2_scale));
        }
        // sprites.add_sprite(powerup_sprite_test,powerup_posn);
    }

    // display the score
    ge211::Text_sprite::Builder score_builder(sansfont);
    uint8_t white = 255;
    ge211::Color white_col = {white,white,white};
    score_builder.color(white_col) << model.score;
    score_sprite.reconfigure(score_builder);
    sprites.add_sprite(score_sprite,{29,10},1);

}





/// return the dimensions of the screen
ge211::Dims<int>
View::initial_window_dimensions() const{
    return model.config.screen_dims;
}