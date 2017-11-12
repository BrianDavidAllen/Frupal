///////////////////////////////////////////////////
////                                            //
////   main.cpp file                            //
////                                            // 
////   Used for testing hero class functions    //
////                                            //
////                                            //
////   CS300-Group D                            //
////   Fall 2017                                //
////   Ben Portis                               //
////                                            //
//////////////////////////////////////////////////

#include "hero.h"

using namespace std;

int main()
{
    Hero obj1;
    obj1.displayHero();

    Hero obj(100,0,0,0,"ben","axe");

    obj.displayHero();

    obj.addItem("boat");
    obj.setEnergy(50);
    obj.setWhiffles(1000000);
    obj.setCoords(5,4);
    obj.displayHero();

    return 0;
}
