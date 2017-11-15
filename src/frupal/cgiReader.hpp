/* Daniel Dupriest, 2017
 * Communication from client with json library
 */

#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class CgiReader {
    public:
        CgiReader();
        ~CgiReader();
        json getCommand();
};
