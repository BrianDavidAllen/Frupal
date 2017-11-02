/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include "game.hpp"

Game::Game()
{
    Player player;

    /* Check for existing game file.
     * Load existing game if it exists.
     * Start a new one if it doesn't
     */
}

Game::~Game()
{
}

void Game::loadExistingGame()
{
    /* Get map, object, item and player info from file and load into objects. */
}

void Game::parseCommand(json input)
{
    string command = input["command"];
    log = "";

    if(command == "up")
    {
        log = "You moved north.";
        player.y -= 1;
    }
    else if(command == "down")
    {
        log = "You moved south.";
        player.y += 1;
    }
    else if(command == "left")
    {
        log = "You moved west.";
        player.x -= 1;
    }
    else if(command == "right")
    {
        log = "You moved east.";
        player.x += 1;
    }
    else if(command == "space")
        log = "You hit space.";
}

void Game::saveGame()
{
    /* Save the new game state to file */
}

void Game::sendData()
{

    //Create empty json object
    json toSend;

    //Populate "player" object with coordinates
    toSend["player"] = {
        {"x", player.x },
        {"y", player.y }
    };

    /* Populate array of tiles with x & y coordinates
     * and terrain type string. All randomized for now.
     */
    toSend["tiles"] = nullptr;
    for(int x = 0; x < 8; ++x)
    {
        for(int y = 0; y < 8; ++y)
        {
            string type = rand()%2 == 0 ? "plain" : "water";
            toSend["tiles"].push_back({
                    {"x", x },
                    {"y", y },
                    {"terrain", type}
                });
        }
    }

    //Add the log
    toSend["log"] = log;

    //Send the header first 
    cout << "Content-Type:application/json; charset=utf-8" << endl << endl;

    //Send the stringified json
    cout << toSend.dump();
}

void Game::startNewGame()
{
    /* Load from map file and set up new player/inventory.
     */
}

int main()
{
    Game game;
    CgiReader cgi;
    game.parseCommand(cgi.getCommand());
    game.saveGame();
    game.sendData();
    return 0;
}


    
