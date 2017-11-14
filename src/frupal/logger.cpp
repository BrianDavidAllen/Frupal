/* Daniel Dupriest, 2017
 * Player class placeholder
 */

#include "logger.hpp"

Logger::Logger()
{
    ofstream file;
    filename = "default.log";
    //addHeader();
}

Logger::Logger(string name)
{
    ofstream file;
    filename = "default.log";
    //addHeader();
}

Logger::~Logger()
{
}

void Logger::addHeader()
{
   // file.open(filename);
   // file << "Log file '" + filename + "'" << endl;
   // file.close();
}

void Logger::wipe()
{
    file.open(filename);
    file << "== Log file ==" << endl;
    file.close();
}

void Logger::write(string toAdd)
{
   file.open(filename, fstream::app);
   file << toAdd << endl;
   file.close();
}
