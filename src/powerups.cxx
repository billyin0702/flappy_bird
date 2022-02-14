
#include "powerups.hxx"

/// constructs the power_up
Powerup::Powerup(Block b, int ind)
    :block(b),
    index(ind)
{}



/// return position of power_up
Block
Powerup::powerup_block() const{
    return block;
}


/// return index of power_up
int
Powerup::powerup_index() const{
    return index;
}


/// update the position of the power_up
void
Powerup::update_position(Position posn){
    block.x = posn.x;
    block.y = posn.y;
}
