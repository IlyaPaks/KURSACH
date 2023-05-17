#pragma once
#include "Odnopalybnik.h"
#include "pole.h"

class Igra
{
private:
	string imyapobeditelya;
public:
	int rasstanovka(Odnopalybnik* korabli[MMAX], pole* doska);
	void hod(Odnopalybnik* korabli[MMAX], pole* doska, int x, int y);
	int konecigry(Odnopalybnik* korabli[MMAX]);
	string getimyapobeditelya();
	void setimyapobeditelya(string imyapobeditelya);
	static int scetchikXodov;
	static string igrokperviy;
	static string igrokvtoroy;

};