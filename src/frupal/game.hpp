/* Daniel Dupriest, 2017
 * Sample game class
 */
#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "cgiReader.hpp"
#include "grovnick.hpp"
#include "player.hpp"
#include "map.hpp"
#include "hero.h"

using namespace std;
using json = nlohmann::json;

class Game
{
    public:
        Game();
        ~Game();
        void endGame();
        bool gameStateExists();
        bool loadGameState(fstream &file);
        void log(string newLogLine);
        void parseCommand(json input);
        bool playerIsDead();
        void saveGameState(fstream &file);
        void sendData();

    private:
        json current;
        json toSend;
        Hero hero;
		Map map;
        string log;
};
