# pragma once
# include <ge211.hxx>

struct Model;

struct View{
    /// constructor for view with Model
    explicit View(Model const&);

    // initiates the window with the given dimensions
    ge211::Dims<int> initial_window_dimensions() const;

    // draw the current sprites
    void draw(ge211::Sprite_set&);


    /// fields
    Model const& model;
    ge211::Image_sprite const bird_sprite;

    // the sprites responsible for the image of the powerups
    ge211::Image_sprite const powerup_sprite0;
    ge211::Image_sprite const powerup_sprite1;
    ge211::Image_sprite const powerup_sprite2;

    ge211::Image_sprite const background;

    // related score sprites
    ge211::Text_sprite score_sprite;
    ge211::Font const sansfont{"sans.ttf", 30};

    // will give the rectangles for the pipe bricks
    ge211::Rectangle_sprite const pipe_sprite;


};