#include "Igra.h"
#include "Ecran.h"


int Igra::rasstanovka(Odnopalybnik* korabli[MMAX], pole* doska)
{
	int i;

	imyapobeditelya = "Íå èçâåñòíî";

	for (i = (M - 1); i >= 0; i--)
	{
		if (korabli[i]->ustanovkakorablya(doska) == 1)
		{
			return 1; //Îøèáêà ðàññòàíîâêà êîðàáëåé íå ïîëó÷èëàñü
		}
	}

	return 0; //ðàññòàíîâêà êîðàáëåé ïðîøëà óñïåøíî
};

void Igra::hod(Odnopalybnik* korabli[MMAX], pole* doska, int x, int y)
{
	int i;
	sostoyanie per;//Äîïîëíèòåëüíàÿ ïåðåìåííàÿ
	sost vspper;//Äîïîëíèòåëüíàÿ ïåðåìåííàÿ

	doska->koorposlxoda = Ecran::bykvi[x] + Ecran::tsifri[y];

	per = doska->pol[x][y].getklet();
	if (per == PUST)
	{
		doska->pol[x][y].setklet(PUSTPOD);
		doska->resposlxoda = "Ìèìî";
	}
	if ((per == PUSTPOD) || (per == KORPOD))
	{
		doska->resposlxoda = "Òîæå ìèìî";
	}
	if (per == KOR)
	{
		doska->pol[x][y].setklet(KORPOD);
		for (i = 0; i < M; i++) //Ïðîõîäèò ïî ìàññèâó êîðàáëåé ÷òîáû íàéòè òîò â êîòîðûé ìû ïîïàëè
		{
			vspper = korabli[i]->proverkakorablya(x, y);
			if (vspper == UBIT)
			{
				doska->resposlxoda = "Óáèò";
				return;
			}
			if (vspper == PODBIT)
			{
				doska->resposlxoda = "Ïîïàë";
				return;
			}
			if (vspper == NEPODBIT)
			{
				//Íè÷åãî íå äåëàåò, òî åñòü ïðîâåðÿåì ñëåäóþùèé êîðàáëü
			}
		}
		cout << endl << "ÏÎÄÁÈÒÛÉ ÊÎÐÀÁËÜ ÍÅ ÍÀÉÄÅÍ" << endl;
	}

};

int Igra::konecigry(Odnopalybnik* korabli[MMAX])
{
	int i;

	for (i = 0; i < M; i++)
	{
		if (korabli[i]->getkorabl() == NEPODBIT)
		{
			//Ïðîäîëæàåì èãðó
			return 1;
		}
	}
	//Çàêîí÷èòü èãðó
	return 0;

}

string Igra::getimyapobeditelya()
{
	return imyapobeditelya;
};

void Igra::setimyapobeditelya(string imyapobeditelya)
{
	this->imyapobeditelya = imyapobeditelya;
};

int Igra::scetchikXodov = 0; //Âûäåëÿåì ìåñòî â ïàìÿòè äëÿ static ïåðåìåííîé è èíèöèàëèçèðóåì å¸
string Igra::igrokperviy;
string Igra::igrokvtoroy;