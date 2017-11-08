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
Hero::Hero() : energy(100), whiffles(0), x(0), y(0), name(""), inventory(""), alive(true)
{
    
}


//Parameterized constructor: sets energy/whiffles/name/inventory to the passed in arguments
Hero::Hero(int energy, int whiffles, int x, int y, string name, string inventory) : energy(energy), whiffles(whiffles), x(0), y(0), name(name), inventory(inventory)
{
    setCoords(x,y);
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
    cout << "Inventory contents : " << inventory << endl;
    cout << "X,Y coordinates : " << x << "," << y << endl << endl;
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


//Sets the Hero's whiffles to a value passed in, adds it to the hero's whiffles.
void Hero::setWhiffles(int newWhiffles)
{
    whiffles += newWhiffles;
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

//Sets the hero's energy, pass in a negative value to subtract
void Hero::setEnergy(int newEnergy)
{
    energy += newEnergy; 
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





//Paul Hubbard's funky functions

//Function that takes the value
//of the player's x and y coordinates
//and updates the hero's state file
void Hero::updateHero(int newX, int newY, int addedWhiffles)
{
	int startPosX = 0;
	int startPosY = 0;
	string fileToOpen = "heroState.txt";
	string xcord, ycord, whiffles, energy;
	ifstream stateFile(fileToOpen.c_str());

	//read in from the file
	getline(stateFile, energy);
	getline(stateFile, whiffles);
	getline(stateFile, xcord);
	getline(stateFile, ycord);

	
	//set the player's 
	//values from last turn
	this->energy = atoi(energy.c_str());
	this->whiffles = atoi(whiffles.c_str());
	this->x = atoi(xcord.c_str());
	this->y = atoi(ycord.c_str());

	//compare the player's prev x and y
	//by checking if x-x or y-y equals 0
	//if so, lower the player's energy by 1

	int checkx = (this->x - newX);
	int checky = (this->y - newY);

	if(checkx != 0 || checky != 0)
	{
		--this->energy;
	}

	this->x = newX;
	this->y = newY;

	this->whiffles += addedWhiffles;

	//checks for negative 
	//whiffle count	
	if(this->whiffles <= 0)
	{
		this->whiffles = 0;
	}

	//checks if the player is dead
	//and if they are the file 
	if(this->energy <= 0)
	{
		this->energy = 100;
		this->whiffles = 0;
		this->x = startPosX;
		this->y = startPosY;
		this->alive = false;
	}

	//delete file
	remove(fileToOpen.c_str());
	
	//create the new state file
	ofstream newStateFile;
	newStateFile.open(fileToOpen.c_str());

	//add the new player info to 
	//the file	
	newStateFile << this->energy << '\n'
		     << this->whiffles << '\n'
		     << this->x << '\n'
		     << this->y << '\n';
	//close and save the file
	newStateFile.close();
	
}

//returns true if the hero's energy level
//is above 0, and false if the hero is dead
bool Hero::energyStatus()
{
	return this->alive;
}
	
//Paul Hubbard's funky functions




























