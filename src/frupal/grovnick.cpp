/* Group D, 2017
 * Grovnick class with terrain and contents.
 */

#include "grovnick.hpp"

Grovnick::Grovnick(const int x, const int y, const bool visited, const int terrain, const string content):
	x(x), y(y), visible(false), visited(visited), terrain(terrain), content(content)
{
}

Grovnick::~Grovnick()
{
}

int Grovnick::getX()
{
    return x;
}

int Grovnick::getY()
{
    return y;
}

bool Grovnick::isVisible()
{
    return visible;
}

void Grovnick::setVisible()
{
    visible = true;
}

//David Gilmore: returns bool to determine if tile has been visited.
bool Grovnick::isVisited()
{
   return visited; 
}

//David Gilmore: sets bool to true when a tile is visited. 
void Grovnick::setVisited()
{
   visited = true;
}

void Grovnick::saveState(ofstream &file) const {
	file << x << ',' << y << ',' << visited << ',' << terrain << ',' << content << '\n';
}

string Grovnick::getContent(){
	return content;
}

//David Gilmore: Function to pass grovnicks as a json object to map class
json Grovnick::toJson()
{
   json toSend; 
   toSend["x"] = x;
   toSend["y"] = y;
   toSend["visible"] = false;

   if(isVisible() || isVisited()) {
   	toSend["visible"] = true;
   }
   toSend["terrain"] = terrain;
   toSend["content"] = content;
   return toSend;
}
