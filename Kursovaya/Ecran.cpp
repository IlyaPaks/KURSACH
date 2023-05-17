#include "Ecran.h"

const string Ecran::symvoli[4] = { "  ","· ","+ ","x " }; 

const string Ecran::tsifri[NMAX] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" }; 
const string Ecran::bykvi[NMAX] = { "a ","b ","c ","d ","e ","f ","g ","h ","j ","k ", "l ", "m ", "n " , "o " , "p " , "q " , "r " , "s " , "t " , "u " }; 

const string OTST = "          "; 

void Ecran::prorisovkashapki(pole* doska)
{
	cout << endl << endl << endl;
}

void Ecran::prorisovkapolya(pole* doska)
{

	int i, j; 

	
	cout << endl;

	cout << OTST << "Èãðîê: " << doska->imyapolya << endl;
	cout << endl;

	
	cout << OTST << "  ";
	for (i = 0; i < N; i++)
	{
		if (i < 10)
		{
			cout << Ecran::tsifri[i] << " ";
		}
		else
		{
			cout << Ecran::tsifri[i];
		}
	}
	cout << endl;

	for (i = 0; i < N; i++)
	{
		cout << OTST << Ecran::bykvi[i];
		for (j = 0; j < N; j++)
		{
			cout << Ecran::symvoli[doska->pol[i][j].getklet()];
		}
		cout << Ecran::bykvi[i];
		cout << endl;
	}

	cout << OTST << "  ";
	for (i = 0; i < N; i++)
	{
		if (i < 10)
		{
			cout << Ecran::tsifri[i] << " ";
		}
		else
		{
			cout << Ecran::tsifri[i];
		}
	}
	cout << endl;
	cout << endl;
};

void Ecran::prorisovkapodvala(pole* doska)
{
	cout << OTST << "Õîä: " << doska->koorposlxoda << "   " << endl;
	cout << OTST << "Ðåçóëüòàò:   " << doska->resposlxoda << "           " << endl;
	cout << OTST << "Ñëåäóþùèé õîä èãðîêà: " << doska->imyapolya << "                           ";
}

void Ecran::prorisovkastroki(pole* doska, int x, int y, int nomerdoski)
{
	Ecran::set_cursor(0, 0);
	int delta;
	if (nomerdoski == 1)
	{
		delta = 3 + 4;
		Ecran::set_cursor((10 + 2 + 2 * y), (delta + x));
		cout << Ecran::symvoli[doska->pol[x][y].getklet()];

	}
	else
	{ 
		delta = 8 + 1 + N + 4;
		Ecran::set_cursor((10 + 2 + 2 * y), (delta + x));
		cout << Ecran::symvoli[doska->pol[x][y].getklet()];
	}
	Ecran::set_cursor(0, (2 * N + 15));
}

void Ecran::set_cursor(int x, int y) 
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}