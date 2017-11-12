/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include <iostream>
#include <string>
#include "json.hpp"
//#include <cgi.hpp>

using json = nlohmann::json;
using namespace std;

class CgiReader {
    public:
        CgiReader();
        ~CgiReader();
        json getCommand();
};
