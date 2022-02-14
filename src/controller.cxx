
#include "controller.hxx"
#include "model.hxx"

// initiates the model
Controller::Controller(Model& model)
        : model(model),
          view(model),
          start(false)
{ }

// if the input key is 'q' --> quits the game
// if the input key is a space, then move the bird up
void
Controller::on_key(ge211::Key key){
    if (key == ge211::Key::code('q')){
        quit();
    }

    if (key == ge211::Key::code(' ')){
        if (!start) {
            model.bird.set_bird_live();
            start = true;
        }
        model.flip_bird_up();
    }
}

// the same action as a space
void
Controller::on_mouse_up(ge211::Mouse_button btn, ge211::Posn<int>)
{
    if (btn == ge211::Mouse_button::left){
        if (!start) {
            model.bird.set_bird_live();
            start = true;
        }
        model.flip_bird_up();
    }
}


// updates the game accordingly
void
Controller::on_frame(double dt){
    if (start) {
        model.on_frame(dt);
    }
}

// initiate the initial dimensions of the game window
ge211::Dims<int>
Controller::initial_window_dimensions() const{
    return view.initial_window_dimensions();
}

// draw the components
void
Controller::draw(ge211::Sprite_set& sprites){
    view.draw(sprites);
}


