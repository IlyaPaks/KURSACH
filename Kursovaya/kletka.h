#pragma once
#include "koordinata.h"
class kletka : public koordinata
{
private:
	 sostoyanie klet; //Őđŕíčň ńîńňî˙íčĺ ęëĺňęč
public:
	kletka();
	void setklet(sostoyanie k);
	sostoyanie getklet();

};
