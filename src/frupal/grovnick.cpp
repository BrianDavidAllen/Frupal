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

json toJson()
{
   json toSend; 
   
   toSend["x"] = x;
   toSend["y"] = y;
   toSend["Visible"] = visible;
   toSend["terrian"] = terrain;
   return toSend;
}

