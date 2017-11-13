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
   toSend["visible"] = false;

   if(isVisible() || isVisited()) {
   	toSend["visible"] = true;
   }
   toSend["terrian"] = terrain;
   return toSend;
}
