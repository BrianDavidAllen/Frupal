/* Daniel Dupriest, 2017
 * Main function and game logic.
 */
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hpp"
#include "cgiReader.hpp"
#include "grovnick.hpp"
#include "logger.hpp"
#include "map.hpp"
#include "hero.h"
#include "error.hpp"

using namespace std;
using json = nlohmann::json;

class Game
{
    public:
        Game();
        ~Game();
        void checkForObstacles();
        void checkHeroEnergy();
        void endGame();
	void endGameHappy();
        bool gameStateExists(const string filename);
	bool isObstructed();
        bool loadGameState(stringstream &file, bool reloading = false);
        void parseCommand(json input);
	void parseTool(json input);
        bool playerIsDead();
        bool saveGameState(ofstream &file);
        void sendData();
        void selectMap();
		void sendError(string message);
        void setNextGrovnick(string command);
        bool terrainCanBeTraversed();
        void tryToBuy();
        void tryToMove(string command);
	bool onRoyalDiamond(string content);

    private:
        void message(string message);
        json current;
        json toSend;
        Hero hero;
        Logger log;
		Map map;
        Grovnick * nextGrovnick;
};
