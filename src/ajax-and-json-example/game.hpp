/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "json.hpp"
#include "terrain.hpp"
#include "map.hpp"
#include "cgiReader.hpp"
#include "log.hpp"

using namespace std;
using json = nlohmann::json;

class Game {
    public:
        Game();
        ~Game();
        void loadExistingGame();
        void startNewGame();
        void parseCommand(json command);
    private:
        FILE *file;
        Map map;
};

