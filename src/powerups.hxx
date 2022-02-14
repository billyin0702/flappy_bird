# pragma once
# include <ge211.hxx>
# include <iostream>

// define the structs
using Block = ge211::Rect<float>;
using Position = ge211::Posn<float>;
using Velocity = ge211::Dims<float>;

// Definitions of Position, Velocity, and Rect

/// struct Position
///   {
///       float x;   // pixel distance from left edge of window
///       float y;   // pixel distance from top edge of window
///   };

///   struct Velocity
///   {
///       float width;   // horizontal rate of change (px/s)
///       float height;  // vertical rate of change (px/s)
///   };

///   struct Block
///   {
///       float x;       // x coordinate of left side of rectangle
///       float y;       // y coordinate of top side of rectangle
///       float width;
///       float height;
///   };

struct Powerup
{
public:
    /// Powerup constructor
    Powerup(Block b, int ind);

    /// return position of power_up
    Block powerup_block() const;

    /// return index of power_up
    int powerup_index() const;

    /// update the position of the power_up
    void update_position(Position);

    /// define the necessary fields for a power_up

private:
    Block block;

    // the index of the powerup determines what powerup each powerup cube will
    // give to the bird
    int index;

};

