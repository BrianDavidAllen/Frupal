/* Daniel Dupriest, 2017
 * Player placeholder class. Public data, eww!!
 */
#pragma once
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Player
{
    public:
        Player();
        ~Player();
        int getX();
        int getY();
        void setPosition(int newX, int newY);
        json toJson();
    private:
        int x;
        int y;
};
