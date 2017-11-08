/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include "game.hpp"

Game::Game()
{
    //Player player;
    Hero hero;
    json toSend;

	fstream stateFile("mapGen.txt");

	if(!stateFile || !loadExistingGame(stateFile))
		startNewGame(stateFile);

	stateFile.close();
}

Game::~Game()
{
}

void Game::endGame()
{
    //Punam, alert box here maybe?
}

bool Game::loadExistingGame(fstream &file)
{
    /* Get map, object, item and hero info from file and load into objects. */
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

	// TODO: Have the hero load info here

	getline(file, blankSpace);
	if(blankSpace.empty() || blankSpace[0] != '#')
		return false;

	return map.loadFile(identifier, dimensions, file);
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

void Game::saveGame()
{
    /* Save the new game state to file */
}

void Game::sendData()
{
    //toJson() use example
   // toSend["hero"] = hero.toJson();

    //Test some getGrovnick functions
    Grovnick * grovnickUnderPlayer = map.getGrovnick(hero.getX(), hero.getY());
    toSend["test"] = grovnickUnderPlayer->isVisible();

    //Populate array of tiles.;
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

void Game::startNewGame(fstream &stateFile)
{
    /* Load from map file and set up new hero/inventory.
     */
	fstream staticFile("mapGen.txt");
	// TODO: Copy stateFile <- staticFile

	map.generateFile(stateFile);

	staticFile.close();
}

int main()
{
    Game game;
    CgiReader cgi;
    game.parseCommand(cgi.getCommand());
    if(game.playerIsDead())
    {
        game.endGame();
    }
    else
    {
        game.saveGame();
    }
    game.sendData();
    return 0;
}


    
