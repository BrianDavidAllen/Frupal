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
            changeEnergy(-6);
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
            --inventory.hatchet; 
            changeEnergy(-8);
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
            changeEnergy(-2);
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
            changeEnergy(-4);
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
            changeEnergy(-2);
            return true;
        }
        else
        {
            return false;
        }
    }

    if(itemName.compare("power-bar") == 0)
    {
        if(inventory.powerbar >= 1)
        {
            --inventory.powerbar; 
            changeEnergy(20);
            return true;
        }
        else
        {
            return false;
        }
    }

    if(itemName.compare("shears") == 0)
    {
        if(inventory.shears >= 1)
        {
            --inventory.shears; 
            changeEnergy(-2);
            return true;
        }
        else
        {
            return false;
        }
    }

    if(itemName.compare("chisel") == 0)
    {
        if(inventory.chisel >= 1)
        {
            --inventory.chisel; 
            changeEnergy(-15);
            return true;
        }
        else
        {
            return false;
        }
    }

    if(itemName.compare("sledge") == 0)
    {
        if(inventory.sledge >= 1)
        {
            --inventory.sledge; 
            changeEnergy(-12);
            return true;
        }
        else
        {
            return false;
        }
    }
    if(itemName.compare("suplex") == 0)
    {
        changeEnergy(-16);
    	return true;
    }
    if(itemName.compare("karate chop") == 0 || itemName.compare("karate kick") == 0)
    {
	    changeEnergy(-4);
    	return true;
    } 
    if(itemName.compare("tackle") == 0)
    {
        changeEnergy(-10);
	    return true;
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

    if(itemName.compare("power-bar") == 0)
    {
        ++inventory.powerbar;
        return;
    }

    cout << "Unknown Item passed in " << endl;
    
}


//Buy an item and add the item to the inventory, pass in the item name to add it to the inventory
//Make sure you pass in the correct itemName!

//Function by Ben Portis and Paul Hubbard
bool Hero::buyItem(string itemName)
{
    if("binoculars" == itemName)
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

    else if("boat" == itemName)
    {
        if(whiffles >= 250)
        {
            inventory.boat = true; 
            whiffles = whiffles - 250;
            return true;
        }
        else
            return false;
    }

    else if("axe" == itemName)
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
    else if("chainsaw" == itemName)
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

    else if("jackhammer" == itemName)
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

    else if("machete" == itemName)
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

    else if("power-bar" == itemName)
    {
        if(whiffles >= 1)
        {
//            ++inventory.powerbar;
            whiffles = whiffles - 1;
	    changeEnergy(20);
	    
            return true;
        }
        else
            return false;
    }
    else if("type-1-treasure-chest" == itemName)
    {
    	changeWhiffles(100);
    	return true;
    }
    else if("type-2-treasure-chest" == itemName)
    {
    	setWhiffles(0);
        return true;
    }
	else if("chisel" == itemName)
    {
        if(whiffles >= 5)
        {
            ++inventory.chisel;
            whiffles -= 5;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if("hatchet" == itemName)
    {
        if(whiffles >= 15)
        {
            ++inventory.hatchet;
            whiffles -= 15;
            return true;
        }
        else
        {
            return false;
        }
    }	
    else if("sledge" == itemName)
    {
        if(whiffles >= 25)
        {
            ++inventory.sledge;
            whiffles -= 25;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if("shears" == itemName)
    {
        if(whiffles >= 35)
        {
            ++inventory.shears;
            whiffles -= 35;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
}
//Function by Ben Portis and Paul Hubbard ^^

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
   output["whiffles"] = whiffles;
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
	string xcord, ycord, whifflesString, energyString, axeCount, hatchetCount, 
	       chainsawCount, chiselCount, sledgeCount, shearsCount, jackhammerCount, 
	       macheteCount, powerbarCount, binocularsBool, boatBool;
	ifstream stateFile(fileToOpen.c_str());
	int binCount, boatCount;

	//read in from the file
	getline(stateFile, energyString);
	getline(stateFile, whifflesString);
	getline(stateFile, xcord);
	getline(stateFile, ycord);
	getline(stateFile, axeCount);
	getline(stateFile, hatchetCount);
	getline(stateFile, chainsawCount);
	getline(stateFile, chiselCount);
	getline(stateFile, sledgeCount);
	getline(stateFile, shearsCount);
	getline(stateFile, jackhammerCount);
	getline(stateFile, macheteCount);
	getline(stateFile, powerbarCount);
	getline(stateFile, boatBool);
	getline(stateFile, binocularsBool);

	
	//set the player's 
	//values from last turn
	energy = atoi(energyString.c_str());
	whiffles = atoi(whifflesString.c_str());
	x = atoi(xcord.c_str());
	y = atoi(ycord.c_str());
	inventory.axe = atoi(axeCount.c_str());
	inventory.hatchet = atoi(hatchetCount.c_str());
	inventory.chainsaw = atoi(chainsawCount.c_str());
	inventory.chisel = atoi(chiselCount.c_str());
	inventory.sledge = atoi(sledgeCount.c_str());
	inventory.shears = atoi(shearsCount.c_str());
	inventory.jackhammer = atoi(jackhammerCount.c_str());
	inventory.machete = atoi(macheteCount.c_str());
	inventory.powerbar = atoi(powerbarCount.c_str());

	binCount = atoi(binocularsBool.c_str());
	boatCount = atoi(boatBool.c_str());
	if(binCount == 0)
		inventory.binoculars = false;
	else
		inventory.binoculars = true;

	if(boatCount == 1)
		inventory.boat == true;
	else
		inventory.boat == false;
}

//Function that takes the value
//of the player's x and y coordinates
//and updates the hero's state file
void Hero::saveState() 
{
	string fileToOpen = "heroState.txt";
	ifstream stateFile(fileToOpen.c_str());
	int binocularBool, boatBool;
	
	//check the binoculars and 
	//boat bool, and then convert
	//them into an int. 1 for true
	//and 0 for false
	if(inventory.binoculars)
		binocularBool = 1;
	else 
		binocularBool = 0;

	if(inventory.boat)
		boatBool = 1;
	else
		boatBool = 0;

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
		     << y << '\n'
		     << inventory.axe << '\n'
		     << inventory.hatchet << '\n'
		     << inventory.chainsaw << '\n'
		     << inventory.chisel << '\n'
		     << inventory.sledge << '\n' 
		     << inventory.shears << '\n'
		     << inventory.jackhammer << '\n'
		     << inventory.machete << '\n'
		     << inventory.powerbar << '\n'
		     << boatBool << '\n'
		     << binocularBool << '\n';

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
		     << "13" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n'
		     << "0" << '\n';

	//close and save the file
	newStateFile.close();
	
    //Change hero energy stats to match
	//reset
	energy = 100;
	whiffles = 0;
	x = 11;
	y = 13;
}

//Paul Hubbard's funky functions ^^


