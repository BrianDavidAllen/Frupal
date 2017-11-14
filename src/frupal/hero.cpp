//////////////////////////
//                      // 
//   Hero.cpp           //
//                      //
//   CS300-Group D      //
//   Fall 2017          //
//   Ben Portis         //
//                      //
////////////////////////

#include "hero.h"

using namespace std;

//Default constructor: sets energy level to 100, x,y to zero, whiffles to zero, and name/invetory to NULL
Hero::Hero() : energy(100), whiffles(0), x(11), y(13), name(""), inventory(""), alive(true)
{
    
}


//Parameterized constructor: sets the name to a string passed in, everything else is set to default values
Hero::Hero(int energy, int whiffles, int x, int y, string newName, string inventory) : energy(100), whiffles(0), x(11), y(13), name(newName), inventory(""), alive(true)
{

}

//Hero destructor
Hero::~Hero()
{

}

//Display the Hero's name,stats, and items
void Hero::displayHero()
{
    cout << "Name: " << name << endl;
    cout << "Energy level: " << energy << endl;
    cout << "Whiffle count: " << whiffles << endl;
    cout << "Inventory contents: " << inventory << endl;
    cout << "X,Y coordinates: " << x << "," << y << endl << endl;
}

//Sets the Hero's name to a string passed in
void Hero::setName(string newName)
{
    name = newName;
}

//Returns the hero's name
string Hero::getName()
{
    return name;
}


//changes the Hero's whiffles by adding to the hero's whiffles
//Pass in a negative value to subtract from the hero's whiffles
void Hero::changeWhiffles(int newWhiffles)
{
    if(whiffles + newWhiffles <= 0)
    {
        whiffles = 0; 
        return;
    }
    else
    {
        whiffles += newWhiffles;
        return;
    }
}

//Sets the whiffles to a value passed in
void Hero::setWhiffles(int newWhiffles)
{
    whiffles = newWhiffles;
}

//Rerturns the hero's whiffle count
int Hero::getWhiffles()
{
    return whiffles;
}

//Add an item to the inventory
void Hero::addItem(string item)
{
    //If inventory is not empty we'll add a comma and then add the item. 
    if(inventory.empty())
        inventory = item;
    else
        inventory = inventory + "," + " " + item;
}

//Returns the hero's inventory
string Hero::getInventory()
{
    return inventory;
}

//Change the hero's energy, pass in a negative value to subtract, positive to add
void Hero::changeEnergy(int newEnergy)
{

    if(energy + newEnergy > 100)
    {
        energy = 100;
        return;
    }
    if(energy + newEnergy <= 0)
    {
        energy = 0;
		alive = false;
        return;
    }

    energy += newEnergy; 
}

//sets the energy to a value passed in
void Hero::setEnergy(int newEnergy)
{
    energy = newEnergy;
}

//Returns the hero's energy
int Hero::getEnergy()
{
    return energy;
}

//Sets the hero's coordinates
void Hero::setCoords(int newX, int newY)
{
    x = newX;
    y = newY;
}

//Returns the hero's x coordinate
int Hero::getX()
{
    return x;
}

//Returns the hero's y coordinate
int Hero::getY()
{
    return y;
}


//toJson function
json Hero::toJson()
{
   json output;

   output["x"] = x;
   output["y"] = y;
   output["energy"] = energy;
   output["name"] = name;
   output["inventory"] = inventory;

   return output;
}



//Paul Hubbard's funky functions

void Hero::loadState()
{
	string fileToOpen = "heroState.txt";
	string xcord, ycord, whifflesString, energyString;
	ifstream stateFile(fileToOpen.c_str());

	//read in from the file
	getline(stateFile, energyString);
	getline(stateFile, whifflesString);
	getline(stateFile, xcord);
	getline(stateFile, ycord);

	
	//set the player's 
	//values from last turn
	energy = atoi(energyString.c_str());
	whiffles = atoi(whifflesString.c_str());
	x = atoi(xcord.c_str());
	y = atoi(ycord.c_str());
}

//Function that takes the value
//of the player's x and y coordinates
//and updates the hero's state file
void Hero::saveState() 
{
	string fileToOpen = "heroState.txt";
	ifstream stateFile(fileToOpen.c_str());

	//delete file
	remove(fileToOpen.c_str());
	
	//create the new state file
	ofstream newStateFile;
	newStateFile.open(fileToOpen.c_str());

	//add the new player info to 
	//the file	
	newStateFile << energy << '\n'
		     << whiffles << '\n'
		     << x << '\n'
		     << y << '\n';
	//close and save the file
	newStateFile.close();
	
}

//returns true if the hero's energy level
//is above 0, and false if the hero is dead
bool Hero::isAlive()
{
	return alive;
}

//function that reloads the hero state
//file, and sets it to the original state

void Hero::resetState()
{
	const char * fileToOpen = "heroState.txt";

	//deletes old file
	remove(fileToOpen);

	//create new file with orginal state
	ofstream newStateFile;
	newStateFile.open(fileToOpen);

	newStateFile << "100" << '\n'
				 << "0" << '\n'
				 << "11" << '\n'
				 << "13" << '\n';

	//close and save the file
	newStateFile.close();

    //Change hero stats to match
    energy = 100;
    whiffles = 0;
    x = 11;
    y = 13;

}

//Paul Hubbard's funky functions ^^


