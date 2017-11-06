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
//#include "json.hpp"

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

        void changeWhiffles(int newWhiffles);                                           //Change the amount of whiffles the hero has by the amount passed in
        void setWhiffles(int newWhiffles);                                              //Sets the amount of whiffles the hero has to a value passed in
        int getWhiffles();                                                              //Returns the hero's whiffle count
        
        void addItem(string item);                                                      //Add an item to the player's inventory 
        string getInventory();                                                          //Returns the hero's inventory

        void changeEnergy(int newEnergy);                                               //Changes the energy level of the hero by the amount passed in
        void setEnergy(int newEnergy);                                                  //Sets the energy level of the hero to a value passed in
        int getEnergy();                                                                //Returns the energy level of the hero

        void setCoords(int x, int y);                                                   //Set the coordinates of the hero
        int getX();                                                                     //Returns the x coordinate of the hero
        int getY();                                                                     //Returns the y coordinate of the hero
    
 //       json toJson();                                                                  //Json function
        
    protected:
        int energy;
        int whiffles;
        int x;
        int y;
        string name;
        string inventory;
        
};
