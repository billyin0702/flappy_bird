# pragma once
# include <ge211.hxx>
# include "view.hxx"

struct Controller : ge211::Abstract_game
{
    explicit Controller(Model&);


    /// functions

    // using the key to give the bird upward momentum
    void on_key(ge211::Key) override;

    // using the mouse to give the bird upward momentum
    void on_mouse_up(ge211::Mouse_button, ge211::Posn<int>) override;

    // updates the game
    void on_frame(double dt) override;

    // draws the window
    ge211::Dims<int> initial_window_dimensions() const override;

    // draws the individual components
    void draw(ge211::Sprite_set&) override;


    /// define the fields
    // creates a model so controller can reference
    Model& model;

    // creates a view to reference
    View view;

    // variable to assess whether the game has started
    // used to freeze the game
    bool start;

};


