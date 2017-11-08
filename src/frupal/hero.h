////////////////////////////
////                      //
////  Hero Header File    //
////                      //
////   CS300-Group D      //
////   Fall 2017          //
////   Ben Portis         //
////                      //
//////////////////////////

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Hero
{

    public:
        Hero();                                                                         //Default Hero constructor

        Hero(int energy, int whiffles, int x, int y, string name, string inventory);    //Hero parameterized constructor

        ~Hero();                                                                        //Hero destructor

        void displayHero();                                                             //display the hero's energy level, whiffles, name, and items in inventory 
        void setName(string name);                                                      //Set the hero's name
        string getName();                                                               //Returns the hero's name

        void setWhiffles(int newWhiffles);                                              //Set the amount of whiffles the player has
        int getWhiffles();                                                              //Returns the hero's whiffle count

        void addItem(string item);                                                      //Add an item to the player's inventory 
        string getInventory();                                                          //Returns the hero's inventory

        void setEnergy(int newEnergy);                                                  //Set the energy level of the hero      
        int getEnergy();                                                                //Returns the energy level of the hero

        void setCoords(int x, int y);                                                   //Set the coordinates of the hero
        int getX();                                                                     //Returns the x coordinate of the hero
        int getY();                                                                     //Returns the y coordinate of the hero

	//Paul Hubbard's funky functions

	//function to update hero's 
	//state file
	void updateHero(int x, int y);

	//Loads the hero's state from the 
	//previous turn
	void loadHero();

	//function to check if the player is 
	//alive or dead
	bool energyStatus();

	//function that reloads the 
	//hero state file to the 
	//original state and sets the player's 
	//var's to their og state
	void ogHeroState();
	
	//Paul Hubbard's funky functions

    protected:
        int energy;
        int whiffles;
        int x;
        int y;
        string name;
        string inventory;
	bool alive;
        
};
