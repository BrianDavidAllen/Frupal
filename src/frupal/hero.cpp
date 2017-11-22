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
Hero::Hero() : energy(100), whiffles(0), x(11), y(13), name(""), alive(true)
{
    
}


//Parameterized constructor: sets the name to a string passed in, everything else is set to default values
Hero::Hero(int energy, int whiffles, int x, int y, string newName, string inventory) : energy(100), whiffles(0), x(11), y(13), name(newName), alive(true)
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

//use an item in the inventory if it is there,
//returning true if the item was used.
bool Hero::useItem(string itemName)
{
    //If player has item and enough energy to use the item,    
    //return true, else return false   
    if(itemName.compare("axe") == 0)
    {
        if(inventory.axe >= 1)
        {
            --inventory.axe;  
            energy = energy - 6;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    if(itemName.compare("hatchet") == 0)
    {
        if(inventory.hatchet >= 1)
        {
            --inventory.axe; 
            energy = energy - 8;
            return true;
        }
        else
        {
            return false;
        }
    }

    if(itemName.compare("chainsaw") == 0)
    {
        if(inventory.chainsaw >= 1)
        {
            --inventory.chainsaw; 
            energy = energy - 2;
            return true;
        }
        else
        {
            return false;
        }
    }

    if(itemName.compare("jackhammer") == 0)
    {
        if(inventory.jackhammer >= 1)
        {
            --inventory.jackhammer; 
            energy = energy - 4;
            return true;
        }
        else
        {
            return false;
        }
    }

    if(itemName.compare("machete") == 0)
    {
        if(inventory.machete >= 1)
        {
            --inventory.machete; 
            energy = energy - 2;
            return true;
        }
        else
        {
            return false;
        }
    }

    if(itemName.compare("powerbar") == 0)
    {
        if(inventory.powerbar >= 1)
        {
            --inventory.powerbar; 
            energy = energy + 20;
            return true;
        }
        else
        {
            return false;
        }
    }

    //else return false
    return false;
}

//Add an item to the inventory, pass in the item name to add it to the inventory
//Make sure you pass in the correct itemName!
void Hero::addItem(string itemName)
{
    if(itemName.compare("binoculars") == 0)
    {
        inventory.binoculars = true; 
        return;
    }

    if(itemName.compare("boat") == 0)
    {
        inventory.boat = true; 
        return;
    }

    if(itemName.compare("axe") == 0)
    {
        ++inventory.axe; 
        return;
    }

    if(itemName.compare("hatchet") == 0)
    {
        ++inventory.hatchet;
        return;
    }

    if(itemName.compare("chainsaw") == 0)
    {
        ++inventory.chainsaw; 
        return;
    }

    if(itemName.compare("chisel") == 0)
    {
        ++inventory.chisel;
        return;
    }

    if(itemName.compare("sledge") == 0)
    {
        ++inventory.sledge;
        return;
    }

    if(itemName.compare("shears") == 0)
    {
        ++inventory.shears;
        return;
    }

    if(itemName.compare("jackhammer") == 0)
    {
        ++inventory.jackhammer; 
        return;
    }

    if(itemName.compare("machete") == 0)
    {
        ++inventory.machete; 
        return;
    }

    if(itemName.compare("powerbar") == 0)
    {
        ++inventory.powerbar;
        return;
    }

    cout << "Unknown Item passed in " << endl;
    
}


//Buy an item and add the item to the inventory, pass in the item name to add it to the inventory
//Make sure you pass in the correct itemName!
bool Hero::buyItem(string itemName)
{
    if(itemName.compare("binoculars") == 0)
    {
        if(whiffles >= 50)
        {
            inventory.binoculars = true; 
            whiffles = whiffles - 50;
            return true;
        }
        else 
            return false;
    }

    if(itemName.compare("boat") == 0)
    {
        if(whiffles >= 250)
        {
            inventory.boat = true; 
            whiffles = whiffles - 250;
            return true;
        }
        else
            false;
    }

    if(itemName.compare("axe") == 0)
    {
        if(whiffles >= 30)
        {
            ++inventory.axe; 
            whiffles = whiffles - 30;
            return true;
        }
        else
            return false;
    }

    if(itemName.compare("chainsaw") == 0)
    {
        if(whiffles >= 60)
        { 
            ++inventory.chainsaw; 
            whiffles = whiffles - 60;
            return true;
        }
        else 
            return false;
    }

    if(itemName.compare("jackhammer") == 0)
    {
        if(whiffles >= 100)
        {
            ++inventory.jackhammer; 
            whiffles = whiffles - 100;
            return true;
        }
        else
            return false;
    }

    if(itemName.compare("machete") == 0)
    {
        if(whiffles >= 25)
        {
            ++inventory.machete; 
            whiffles = whiffles - 25;
            return true;
        }
        else
            return false;
    }

    if(itemName.compare("powerbar") == 0)
    {
        if(whiffles >= 1)
        {
            ++inventory.powerbar;
            whiffles = whiffles - 1;
            return true;
        }
        else
            return false;
    }

    cout << "Unknown Item passed in " << endl;
    
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
   output["axe"] = inventory.axe;
   output["hatchet"] = inventory.hatchet;
   output["chainsaw"] = inventory.chainsaw;
   output["chisel"] = inventory.chisel;
   output["sledge"] = inventory.sledge;
   output["shears"] = inventory.shears;
   output["jackhammer"] = inventory.jackhammer;
   output["machete"] = inventory.machete;
   output["powerbar"] = inventory.powerbar;
   output["binoculars"] = inventory.binoculars;
   output["boat"] = inventory.boat;

   return output;
}

//Returns a boolean based on whether or not the hero has binoculars
bool Hero::hasBinoculars()
{
    if(inventory.binoculars == true)
        return true;
    else
        return false;
}

//Returns a boolean based on whether or not the hero has a boat
bool Hero::hasBoat()
{
    if(inventory.boat == true)
        return true;
    else
        return false;
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

	//Change hero energy stats to match
	//reset
	energy = 100;
	whiffles = 0;
	x = 11;
	y = 13;
	
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
}

//Paul Hubbard's funky functions ^^


