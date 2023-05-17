#pragma once
#include "Header.h"
#include "pole.h"

class Igrok
{
private:
	string imya;
	sostoyanie masproverky[NMAX][NMAX]; //Õðàíèò ñäåëàííûå âûñòðåëû èãðîêà
	varianti fdobit; //Ôëàæîê äëÿ ôóíêöèè âûñòðåë
	int napr; //Íàïðàâëåíèå âûñòðåëîâ ïî ïîäáèòîìó êîðàáëþ
	int xnach, ynach, xpre, ypre, naprmimo[4], ch; //Ïåðåìåííûå äëÿ àëãîðèòìà äîáèòèÿ êîðàáëÿ
public:
	Igrok(string imya);
	void vystrel(int* x, int* y, pole* doska);
	string getimya();

};