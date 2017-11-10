/* Daniel Dupriest, 2017
 * Player placeholder class. Public data, eww!!
 */
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Logger
{
    public:
        Logger();
        Logger(string name);
        ~Logger();
        void write(string toAdd);
    private:
        ofstream file;
};
