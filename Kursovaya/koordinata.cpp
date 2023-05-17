#include "koordinata.h"

using namespace std;

koordinata::koordinata() //Конструктор
{
	koordinataX = -1;
	koordinataY = -1;
};

void koordinata::getkoordinata(int* x, int* y) //Получение поля координата
{
	*(x) = koordinataX;
	*(y) = koordinataY;
};

void koordinata::setkoordinata(int x, int y) //Установка поля координата
{
	// проверка на коректность переданной значения координат. Она должна быть от 0 до N.
	try
	{
		if ((x < 0) || (x > (N-1)) || (y < 0) || (y > (N - 1)))
		{
			throw "Ошибка, координата неверна";
		}
	}
	catch(const char* oshibka)
	{
		cout << oshibka << endl;
		cout <<  "X = " << x << " " << "Y = " << y << endl;
		
	}
	koordinataX = x;
	koordinataY = y;
};

int koordinata::getkoordinataX() //Получение поля координата
{
	return koordinataX;
};

int koordinata::getkoordinataY() //Получение поля координата
{
	return koordinataY;
};
