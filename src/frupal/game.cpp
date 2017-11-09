/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include "game.hpp"

Game::Game()
{
    json toSend;
}

Game::~Game()
{
}

void Game::endGame()
{
    //Punam, alert box here maybe?
}

bool Game::gameStateExists()
{
    //function stub
	fstream stateFile("mapGen.txt");

	if(stateFile)
    {
        stateFile.close();
        return true;
    }

    stateFile.close();
    return false;
}

bool Game::loadGameState(fstream &file)
{
    /* Get map, objects, and hero info from file and load into objects. */
	string identifier, dimensionsString, blankSpace;
	getline(file, identifier);
	if(identifier.empty())
		return false;

	getline(file, dimensionsString);
	if(dimensionsString.empty())
		return false;

	int dimensions = stoi(dimensionsString);

	getline(file, blankSpace);
	if(blankSpace.empty() || blankSpace[0] != '#')
		return false;

	// TODO: Have the hero load info here. Something like
    // hero.loadFile(file);
    // for now, do:
    Hero hero;

	getline(file, blankSpace);
	if(blankSpace.empty() || blankSpace[0] != '#')
		return false;

	return map.loadFile(identifier, dimensions, file);
}

void Game::log(string newLogLine)
{
    toSend["log"] += newLogLine + "\n";
}

void Game::parseCommand(json input)
{
    string command = input["command"];
    log = "";
    int heroX = hero.getX();
    int heroY = hero.getY();

    if(command == "up")
    {
        log = "You moved north.";
        hero.setCoords(heroX,heroY-1);
    }
    else if(command == "down")
    {
        log = "You moved south.";
        hero.setCoords(heroX, heroY+1);
    }
    else if(command == "left")
    {
        log = "You moved west.";
        hero.setCoords(heroX-1, heroY);
    }
    else if(command == "right")
    {
        log = "You moved east.";
        hero.setCoords(heroX+1, heroY);
    }
    else if(command == "space")
    {
        log = "You hit space.";
    }
}

bool Game::playerIsDead()
{
    //Punam, add check for hero energy here
}

bool Game::saveGameState(fstream &file)
{
    //Write out hero and map data here.
    return true;
}

void Game::sendData()
{
    toSend["hero"] = hero.toJson();
    toSend["map"] = map.toJson();
    toSend["log"] = log;

    //Send the header and json 
    cout << "Content-Type:application/json; charset=utf-8" << endl << endl;
    cout << toSend.dump();
}

int main()
{
    Game game;
    CgiReader cgi;
    if(game.gameStateExists())
    {
        fstream existingState("mapGen.txt");
        if(!game.loadGameState(existingState))
            game.log("Could not load existing game state.");
        existingState.close();
        game.parseCommand(cgi.getCommand());
    }
    else
    {
        fstream defaultState("default.txt");
        if(!game.loadGameState(defaultState))
            game.log("Could not load default game state.");
        defaultState.close();
    }
    fstream newState("mapGen.txt");
    if(!game.saveGameState(newState))
        game.log("Could not save new game state.");
    newState.close();
    game.sendData();
    return 0;
}    
