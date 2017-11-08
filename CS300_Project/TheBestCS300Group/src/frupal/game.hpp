/* Daniel Dupriest, 2017
 * Sample game class
 */
#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "cgiReader.hpp"
#include "player.hpp"

using namespace std;
using json = nlohmann::json;

class Game
{
    public:
        Game();
        ~Game();
        void loadExistingGame();
        void parseCommand(json input);
        void saveGame();
        void sendData();
        void startNewGame();

    private:
        json current;
        Player player;
        string log;
};
