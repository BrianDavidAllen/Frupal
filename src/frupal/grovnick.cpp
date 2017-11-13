#include "grovnick.hpp"

Grovnick::Grovnick(const int x, const int y, const bool visible, const int terrain, const string content):
	x(x), y(y), visible(visible), terrain(terrain), content(content)
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

bool Grovnick::isVisited()
{
   return visited; 
}

void Grovnick::setVisited()
{
   visited = true;
}

void Grovnick::saveState(ofstream &file) const {
	file << x << ',' << y << ',' << visited << ',' << terrain << ',' << content << '\n';
}

json Grovnick::toJson()
{
   json toSend; 
   toSend["x"] = x;
   toSend["y"] = y;
   
   if(isVisible() || isVisited()) {
   	toSend["visible"] = true;
   } else {
   	toSend["visible"] = false;
   }
   toSend["terrian"] = terrain;
   return toSend;
}
