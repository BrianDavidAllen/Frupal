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

using namespace std;

class Hero
{

    public:
        Hero();                                                                         //Default Hero constructor

        Hero(int energy, int whiffles, int x, int y, string name, string inventory);    //Hero parameterized constructor

        ~Hero();                                                                        //Hero destructor

        void displayHero();                                                             //display the hero's energy level, whiffles, name, and items in inventory 
        void setName(string name);                                                      //Set the hero's name
        void setWhiffles(int newWhiffles);                                              //Set the amount of whiffles the player has
        void addItem(string item);                                                      //Add an item to the player's inventory 
        void setEnergy(int newEnergy);                                                  //Set the energy level of the hero      
        void setCoords(int x, int y);                                                   //Set the coordinates of the hero

    protected:
        int energy;
        int whiffles;
        int x;
        int y;
        string name;
        string inventory;
        
};
