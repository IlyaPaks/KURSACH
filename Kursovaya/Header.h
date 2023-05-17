#pragma once
#include <iostream>
#include "string"
#include <windows.h>

using namespace std;

const int NMAX = 20; //МАКСИМАЛЬНОЕ размерность поля
const int NMIN = 3; //Минимальное размерность поля
const int NFIX = 3; //Обычная Размерность поля при отчете с 1


const int KOLPOP = 500; //МАКСИМАЛЬНОЕ количество попыток установки одного корабля
const int KOLRAZ = 100; //МАКСИМАЛЬНОЕ количество попыток расстановки всех кораблей


const int MMAX = 400; //МАКСИМАЛЬНОЕ количество кораблей
const int kolodnoFIX = 0; //Обычная Количество однопалубников
const int koldvyFIX = 2; //Обычная Количество двупалубников
const int koltreFIX = 0; //Обычная Количество трехпалубников
const int kolchetireFIX = 0; //Обычная Количество четырехпалубников
const int MFIX = kolodnoFIX + koldvyFIX + koltreFIX + kolchetireFIX; //Обычная Количество кораблей у игрока

const int ZAD = 10;//Задержка - 500 милисекунд
const int KOLPOPITOK = 1000;

extern int N; //Фактическая размерность поля при отчете с 1

extern int kolodno;//Фактическая Количество однопалубников
extern int koldvy; //Фактическая Количество двупалубников
extern int koltre; //Фактическая Количество трехпалубников
extern int kolchetire; //Фактическая Количество четырехпалубников
extern int M; //Фактическая Количество кораблей у игрока

enum sostoyanie //Состояние поля
{
	PUST,		//Пустое
	PUSTPOD,	//Пустое но сюда уже стреляли
	KOR,		//На этом поле стоит корабль
	KORPOD		//На этом поле стоит корабль по которому стреляли
};

enum sost //Состояние палубы и корабля
{
	PODBIT,     //Палуба подбита, попал в корабль
	NEPODBIT,   //Палуба НЕ подбита, мимо корабля
	UBIT,	  //Корабль убит
	NEUKAZANO   //Состояние не указано
};

enum varianti //Варианты выстрела
{
	var1, // Произвольный выстрел
	var2, // Первое попадание в корабль
	var3, // Следующие попадание в корабль
	var3A,// Промах после первого попадния
	var4, // Промах после серии
	var5
};
