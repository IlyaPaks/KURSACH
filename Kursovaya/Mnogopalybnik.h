#pragma once
#include "Odnopalybnik.h"

class Mnogopalybnik : public Odnopalybnik
{
private: 
	Odnopalybnik* bolkorabl[4]; //Многопалубник это массив однопалубников
	int kolpalyb;	//Хранит количество палуб
public:
	Mnogopalybnik(); //По умолчанию создается двухпалубный корабль
	Mnogopalybnik(int k); //Конструктор с параметров количество палуб
	//sost getpalyba(); //Перекрыл методы однопалубника
	//void setpalyba(sost p);
	sost getkorabl();
	//void setkorabl(sost k);
	int ustanovkakorablya(pole* doska); //Установка на поле многопалубника
	sost proverkakorablya(int x, int y); //Спрашивает корабль попали ли в него
};
