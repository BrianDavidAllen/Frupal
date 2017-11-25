/* Group D, 2017
 * Grovnick class with terrain and contents.
 */

#include "grovnick.hpp"

Grovnick::Grovnick(const int x, const int y, const bool visible, const int terrain, const string content):
	x(x), y(y), visible(visible), terrain(terrain), content(content)
{
}

Grovnick::~Grovnick()
{
}
int Grovnick::getTerrain(){
    return terrain;
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



string Grovnick::saveState() const {
	stringstream ss;
	ss << x << "," << y << "," << visible << "," << terrain << "," << content << endl;
	return ss.str();
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

   if(isVisible()) {
   	toSend["visible"] = true;
   }
   toSend["terrain"] = terrain;
   toSend["content"] = content;
   return toSend;
}

//Paul Hubbard: Function to set the content of a grovnick to 
//              "none" when you buy an item
void Grovnick::clearContent()
{
	content = "none";
}
