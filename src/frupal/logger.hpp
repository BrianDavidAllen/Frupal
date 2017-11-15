/* Daniel Dupriest, 2017
 * Utility logger class for debugging.
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
        void addHeader();
        void wipe();
        void write(string toAdd);
    private:
        ofstream file;
        string filename;
};
