/* Daniel Dupriest, 2017
 * Main function and game logic.
 */

#include "game.hpp"

Game::Game()
{
    Logger log;
    Hero hero;
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
	int hero_energy = hero.getEnergy();
    if(hero_energy < 1)
        endGame();
	
}

void Game::endGame()
{
    //Punam, alert box here maybe?
	toSend["alert"] = "You died!";

	hero.resetState(); //Paul Hubbard

	string defaultStateName = "default.txt";
	ifstream defaultState(defaultStateName);
	stringstream buffer;
	buffer << defaultState.rdbuf();
	defaultState.close();
	if(!loadGameState(buffer, true))
		log.write("Could not load from '" + defaultStateName + "'.");
}
//end the game if you find the royal diamonds -BDA
void Game::endGameHappy(){
        int heroEnery = hero.getEnergy();
        if(heroEnery >= 1)
                toSend["alert"] = "You've found the Royal Diamonds! You win!";
        else
                toSend["alert"] = "With their last dying breath the hero touches the royal diamonds and saves all of frutopia";
        hero.resetState();

        string defaultStateName = "default.txt";
        ifstream defaultState(defaultStateName);
        stringstream buffer;
        buffer << defaultState.rdbuf();
        defaultState.close();
        if(!loadGameState(buffer, true))
                log.write("Could not load from '" + defaultStateName + "'.");

}

bool Game::gameStateExists(const string filename)
{
    //function stub
	ifstream stateFile(filename);

	if(stateFile)
    {
        stateFile.close();
        return true;
    }

    stateFile.close();
    return false;
}
//returns true if an obstacle is blocking the way -BDA
bool Game::isObstructed(){
	string nextContent = nextGrovnick->getContent();
	if( nextContent == "boulder"){
		toSend["tool1"] = "jackhammer";
		toSend["tool2"] = "sledge";
		toSend["tool3"] = "chisel";
		toSend["noTool"] = "hands";
		return true;
	}
	else if(nextContent == "blackberry-bush"){
		toSend["tool1"] = "machete";
		toSend["tool2"] = "shears";
		toSend["tool3"] = "none";
		toSend["noTool"] = "hands";
	}
	else if(nextContent == "tree"){
		toSend["tool1"] = "chainsaw";
		toSend["tool2"] = "axe";
		toSend["tool3"] = "none";
		toSend["noTool"] = "hands"; 
	}
	else{ 
		return false;
	}

}

bool Game::loadGameState(stringstream &file, bool reloading)
{
    log.write("Inside loadGameState()");
    /* Get map, objects, and hero info from file and load into objects. */
    string identifier, dimensionsString, blankSpace;
	getline(file, identifier);
	if(identifier.empty())
		return false;
    log.write("Identifier is: " + identifier);

	getline(file, dimensionsString);
	if(dimensionsString.empty())
		return false;

    log.write("Dimensions is: " + dimensionsString);

	int dimensions = stoi(dimensionsString);

	getline(file, blankSpace);
	if(blankSpace.empty() || blankSpace[0] != '#')
		return false;

	hero.loadState(); //Paul Hubbard

	getline(file, blankSpace);
	if(blankSpace.empty() || blankSpace[0] != '#')
		return false;

	// Either the game is reloading the default map file after the hero's death or not
	if(reloading)
		return map.reloadDefaultFile(identifier, dimensions, file);
	else
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

    map.setHeroVisited(hero.getX(), hero.getY());
    map.setHeroVision(hero.getX(), hero.getY(), hero.hasBinoculars()); 
}

bool Game::saveGameState(ofstream &file)
{
    //Write out hero and map data here.
	map.saveIdentifier(file);
    hero.saveState(); //Paul Hubbard
    log.write("Hero X after hero.saveState(): " + to_string(hero.getX()));
    map.saveMap(file);
    return true;
}

void Game::selectMap()
{
    //Stub
}

void Game::sendData()
{
    toSend["map"] = map.toJson();
    toSend["hero"] = hero.toJson();
    cout << "Content-Type:application/json; charset=utf-8" << endl << endl;
   
    //Send the header and json 
    cout << toSend.dump();

}

void Game::setNextGrovnick(string command)
{
    int tempX = hero.getX();
    int tempY = hero.getY();
    log.write("hero.getX/Y inside setNextGrovnick function: " + to_string(tempX) + ", " + to_string(tempY));
    
    if(command == "up")
        tempY -= 1;
    else if(command == "down")
        tempY += 1;
    else if(command == "left")
        tempX -= 1;
    else if(command == "right")
        tempX += 1;
    
    log.write("X/Y to send to map.getGrovnick(x,y): " + to_string(tempX) + ", " + to_string(tempY));
    nextGrovnick = map.getGrovnick(tempX, tempY);
    if(!nextGrovnick)
        log.write("nextGrovnick is null!");
}
//Checks to see if hero is walking into water or a wall
bool Game::terrainCanBeTraversed()
{
	//string nextContent = nextGrovnick->getContent();
	int nextTerrain = nextGrovnick->getTerrain();
        if(nextTerrain == 3){
		toSend["log"] = "You walked into a wall!";
		return false;
	}
	if(nextTerrain == 2 && !hero.hasBoat()){
		toSend["log"] = "You can't get into the water without a boat!";
		return false;
	} 
	else
	return true;
}

void Game::tryToBuy()
{
    //Stub
}

void Game::tryToMove(string command)
{
    toSend["log"] = " ";//to reset the message after a move
    setNextGrovnick(command);
    if(terrainCanBeTraversed())
    {
        //Do lots more checking in here for items/objects
        //...
	//Paul Hubbard
	//Grovnick * currentGrovnick;
	//currentGrovnick = map.getGrovnick(hero.getX(), hero.getY());
	string itemToBuy = nextGrovnick->getContent();   
 
    	if(itemToBuy == "machete")
    		toSend["log"] = "Press space bar to buy " + itemToBuy + " for x whiffles.";

    	else if(itemToBuy == "shears")
    		toSend["log"] = "Press space bar to buy " + itemToBuy + " for x whiffles.";

    	else if(itemToBuy == "jackhammer")
    		toSend["log"] = "Press space bar to buy the Jack Hammer for x whiffles.";

    	else if(itemToBuy == "power-bar")
    		toSend["log"] = "Press space bar to buy Power Bar for x whiffles.";

   	//Paul Hubbard ^^

        //nextGrovnick->setVisited();
        int nextX = nextGrovnick->getX();
        int nextY = nextGrovnick->getY();
        log.write("X/Y from nextGrovnick->getX/Y(): " + to_string(nextX) + ", " + to_string(nextY));
        hero.setCoords(nextX, nextY);
	
	//tells frupal.js to freeze until tool or hands gets used to remove obstacle
	if(isObstructed()){
		toSend["obstacle"] = "true";
	}
        
	//Deduct terrain movement cost from hero energy
        hero.changeEnergy(-1);
    }
    else
    {
        hero.changeEnergy(-1);
    }
        string contentString = nextGrovnick->getContent();

        if(onRoyalDiamond(contentString)){
            endGameHappy();
        }
    checkHeroEnergy();

}

bool Game::onRoyalDiamond(string content){
	if(content == "royal-diamonds"){
		return true;
	}
	else
		return false;
		
}

int main()
{
    Game game;
    Logger log;
    log.wipe();
    CgiReader cgi;
	string gameStateName = "state.txt";
	string defaultStateName = "default.txt";

	bool loadFail = false;
	bool saveFail = false;

    if(game.gameStateExists(gameStateName))
    {
        log.write("Game state '" + gameStateName + "' exists. Attempting to load.");

        ifstream existingState(gameStateName);
		if(!existingState)
			Error::sendError("Couldn't open state.txt");
		stringstream buffer;
		buffer << existingState.rdbuf();
		existingState.close();
        if(!game.loadGameState(buffer))
            log.write("Could not load from '" + gameStateName + "'.");
    }
    else
    {
        log.write("Game state '" + gameStateName +"' does not exist. Attempting to load '" + defaultStateName + "'");
        ifstream defaultState(defaultStateName);
		if(!defaultState)
			Error::sendError("Couldn't open default.txt");
		stringstream buffer;
		buffer << defaultState.rdbuf();
		defaultState.close();
        if(!game.loadGameState(buffer))
            log.write("Could not load from '" + defaultStateName + "'.");
    }

	game.parseCommand(cgi.getCommand());

    log.write("Attempting to save new state to '" + gameStateName + "'.");
    ofstream newState(gameStateName);
	if(!newState)
		Error::sendError("Couldn't open state.txt for writing.");
    if(!game.saveGameState(newState))
        log.write("Could not save new state to '" + gameStateName + "'.");
    newState.close();

    game.sendData();
    return 0;
}
