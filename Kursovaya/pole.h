#pragma once
#include "kletka.h"
class pole 
{
public:
	string imyapolya; // Хранит копию имени игрока
	string koorposlxoda; // Хранит копию координаты последнего хода
	string resposlxoda; // Хранит копию  результата последнего хода
	kletka pol[NMAX][NMAX]; //Хранит информацию о клетках
	pole();
	void chistka(); //Чистит поля
};

