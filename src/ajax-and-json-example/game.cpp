/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include "game.hpp"

Game::Game() {
    file = fopen( "current-game.dat", "r");
    if(file == 0)
        startNewGame();
    else
        loadExistingGame();   
}

Game::~Game() {
    fclose(file);
}

void Game::loadExistingGame() {
    
}

void Game::parseCommand(json command) {
	string s = command.dump();
	Log::debug("Command is " + s);
	cout << s << endl;
}

void Game::startNewGame() {
    Map map;
}

int main() {
    cout << "Content-Type:application/json; charset=utf-8" << endl << endl;
    Game game;
    CgiReader cgi;
    game.parseCommand(cgi.getCommand());
    return 0;
}
