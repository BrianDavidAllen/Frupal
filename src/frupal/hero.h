////////////////////////////
////                      //
////   Hero Header File   //
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
#include <stdlib.h>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Hero
{

    public:
        Hero();                                                                         //Default Hero constructor

        Hero(int energy, int whiffles, int x, int y, string name, string inventory);    //Hero parameterized constructor

        ~Hero();                                                                        //Hero destructor

        void displayHero();                                                             //display the hero's energy level, whiffles, name, and items in inventory 
        void setName(string name);                                                      //Set the hero's name
        string getName();                                                               //Returns the hero's name
         
        void changeWhiffles(int newWhiffles);                                           //Change the amount of whiffles the hero has by the amount passed in
        void setWhiffles(int newWhiffles);                                              //Sets the amount of whiffles the hero has to a value passed in
        int getWhiffles();                                                              //Returns the hero's whiffle count
        
        void changeEnergy(int newEnergy);                                               //Changes the energy level of the hero by the amount passed in
        void setEnergy(int newEnergy);                                                  //Sets the energy level of the hero to a value passed in
        int getEnergy();                                                                //Returns the energy level of the hero

        void setCoords(int x, int y);                                                   //Set the coordinates of the hero
        int getX();                                                                     //Returns the x coordinate of the hero
        int getY();                                                                     //Returns the y coordinate of the hero
    
        bool useItem(string itemName);                                                  //Decrements the item from the users inventory if the user has this item. returns true if they have it, false if they dont.
        bool buyItem(string itemName);                                                  //Adds the item to the inventory if the user has enough whiffles. Subtracts the whiffle cost of the item, and returns a bool if succcessfull.
        bool hasBinoculars();                                                           //Returns whether or not the hero has binoculars
        bool hasBoat();                                                                 //Returns whether or not the hero has a boat
        void addItem(string itemName);                                                  //Adds an item to the users inventory, based on the string that is passed in.

        json toJson();                                                                  //Json function
   
        //The hero's inventory.
        //Access individual items by typing inventory.itemname
        struct Inventory
        {
            int axe = 0;
            int hatchet = 0;
            int chainsaw = 0;
            int chisel = 0;
            int sledge = 0;
            int shears = 0;
            int jackhammer = 0;
            int machete = 0;
            int powerbar = 0;
            bool binoculars = false;
            bool boat = false;	    

        }inventory;

		
		//Paul Hubbard's funky functions
		
			//State file functions

				//function to saves hero's 
				//state file
				void saveState();

				//Loads the hero's state from the 
				//previous turn
				void loadState();

				//function to check if the player is 
				//alive or dead if alive it returns true
				//if dead it returns false
				bool isAlive();

				//function that reloads the 
				//hero state file to the 
				//original state  
				void resetState();

			//State file functions ^^	

		//Paul Hubbard's funky functions ^^

    protected:
        int energy;
        int whiffles;
        int x;
        int y;
        string name;
		bool alive; 		
	       
};
