/* Daniel Dupriest, 2017
 * Sample game class
 */
#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "cgiReader.hpp"
#include "player.hpp"
#include "map.hpp"

using namespace std;
using json = nlohmann::json;

class Game
{
    public:
        Game();
        ~Game();
        void endGame();
        bool loadExistingGame(fstream &file);
        void parseCommand(json input);
        bool playerIsDead();
        void saveGame();
        void sendData();
        void startNewGame(fstream &file);

    private:
        json current;
        json toSend;
        Player player;
		Map map;
        string log;
};
