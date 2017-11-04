/* Daniel Dupriest, 2017
 * Player class placeholder
 */

#include "player.hpp"

Player::Player()
{
    x = 5;
    y = 5;
}

Player::~Player()
{
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

void Player::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;
}

json Player::toJson()
{
    json output;
    output["x"] = x;
    output["y"] = y;
    return output;
}
