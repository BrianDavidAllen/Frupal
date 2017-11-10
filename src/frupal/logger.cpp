/* Daniel Dupriest, 2017
 * Player class placeholder
 */

#include "logger.hpp"

Logger::Logger()
{
    ofstream file;
    file.open("default.log");
}

Logger::Logger(string name)
{
    ofstream file;
    file.open(name);
}

Logger::~Logger()
{
    file.close();
}

void Logger::write(string toAdd)
{
    file << toAdd << endl;
}
