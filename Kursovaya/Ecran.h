#pragma once
#include "pole.h"

class Ecran
{
public:
	static const string symvoli[4]; //Ñèìâîëû ñîîòâåòñâóþùèå ñîñòîÿíèÿì êëåòîê ïîëÿ
	static const string tsifri[NMAX]; //Ñèìâîëû ñîîòâåòñâóþùèå êîîðäèíàòàì ïî X
	static const string bykvi[NMAX]; //Ñèìâîëû ñîîòâåòñâóþùèå êîîðäèíàòàì ïî Y

	void prorisovkashapki(pole* doska);
	void prorisovkapolya(pole* doska);
	void prorisovkapodvala(pole* doska);
	void prorisovkastroki(pole* doska, int x, int y, int nomerdoski);
	static void set_cursor(int x, int y);
};