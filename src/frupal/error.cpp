/* Daniel Dupriest 2017
 * This class helps troubleshoot errors by sending messages directly to the broser from the back end.
 */

#include "error.hpp"

using namespace std;

void Error::sendError(string message)
{
	cout << "Content-Type:text/plain; charset=utf-8" << endl << endl;
	cout << message;
}
