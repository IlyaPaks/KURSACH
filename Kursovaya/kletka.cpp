#include "kletka.h"

kletka::kletka() //Êîíñòðóêòîð
{
	klet = PUST;
};

void kletka::setklet(sostoyanie k) //óñòàíàâëèâàåò ñîñòîÿíèå êëåòêè
{
	klet = k;
};

sostoyanie kletka::getklet() //ñ÷èòàòü ñîñòîÿíèå êëåòêè
{
	return klet;
};
