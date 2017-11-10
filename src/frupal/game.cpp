/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include "game.hpp"

Game::Game()
{
    Logger log("game.log");
    json toSend;
    toSend["log"] = "";
    Grovnick * nextGrovnick = NULL;
}

Game::~Game()
{
}

void Game::checkHeroEnergy()
{
    //Punam, check hero energy in here please
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

void Game::parseCommand(json input)
{
    string command = input["command"];
    if(command == "up" ||
        command == "down" ||
        command == "left" ||
        command == "right")
        tryToMove(command);
    else if(command == "space")
        tryToBuy();
    else if(command == "map")
        selectMap();
    else
        log.write("Command not recognized.");
}

bool Game::saveGameState(fstream &file)
{
    //Write out hero and map data here.
    return true;
}

void Game::selectMap()
{
    //Stub
}

void Game::sendData()
{
    toSend["hero"] = hero.toJson();
    toSend["map"] = map.toJson();

    //Send the header and json 
    cout << "Content-Type:application/json; charset=utf-8" << endl << endl;
    cout << toSend.dump();
}



void Game::setNextGrovnick(string command)
{
    int currentX = hero.getX();
    int currentY = hero.getY();
    int tempX = currentX;
    int tempY = currentY;

    if(command == "up")
        tempY -= 1;
    else if(command == "down")
        tempY += 1;
    else if(command == "left")
        tempX -= 1;
    else if(command == "right")
        tempX += 1;
    
    nextGrovnick = map.getGrovnick(tempX, tempY);
    if(!nextGrovnick)
        log.write("nextGrovnick is null!");
}

bool Game::terrainCanBeTraversed()
{
    //always true for now. Eventually we'll check for walls, boat, etc.
    return true;
}

void Game::tryToBuy()
{
    //Stub
}

void Game::tryToMove(string command)
{
    setNextGrovnick(command);
    if(terrainCanBeTraversed())
    {
        //Do lots more checking in here for items/objects
        //...

        //nextGrovnick->setVisited();
        int nextX = nextGrovnick->getX();
        int nextY = nextGrovnick->getY();
        hero.setCoords(nextX, nextY);

        //Deduct terrain movement cost from hero energy
        //...
    }
    else
    {
        hero.changeEnergy(-1);
    }
    checkHeroEnergy();
}

int main()
{
    Game game;
    Logger log("main.log");
    CgiReader cgi;
    if(game.gameStateExists())
    {
        fstream existingState("mapGen.txt");
        if(!game.loadGameState(existingState))
            log.write("Could not load existing game state.");
        existingState.close();
        game.parseCommand(cgi.getCommand());
    }
    else
    {
        fstream defaultState("default.txt");
        if(!game.loadGameState(defaultState))
            log.write("Could not load default game state.");
        defaultState.close();
    }
    fstream newState("mapGen.txt");
    if(!game.saveGameState(newState))
        log.write("Could not save new game state.");
    newState.close();
    game.sendData();
    return 0;
}    
