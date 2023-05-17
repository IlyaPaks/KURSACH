#pragma once
#include "Header.h"

class koordinata
{
private:
	int koordinataX; //Координата по горизонтали
	int koordinataY; //Координата по вертикали

public:
	koordinata();
	//Работаю с координатой как с общим объектом
	void getkoordinata(int *x, int *y); //Получение поля координата
	void setkoordinata(int x, int y); //Установка поля координата

	int getkoordinataX(); //Возращает X	
	int getkoordinataY(); //Возращает Y для вывода на экран
};
