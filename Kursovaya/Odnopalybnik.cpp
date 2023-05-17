#include "Odnopalybnik.h"
Odnopalybnik::Odnopalybnik() 
{
	palyba = NEUKAZANO;
	//korabl = NEUKAZANO;
};

sost Odnopalybnik::getpalyba()
{
	return palyba;
};

void Odnopalybnik::setpalyba(sost p)
{
	palyba = p;
};

sost Odnopalybnik::getkorabl()
{
	return palyba;
};

void Odnopalybnik::setkorabl(sost k)
{
	palyba = k;
};

 int Odnopalybnik::ustanovkakorablya(pole* doska)
 {
	 int x, y, kolpopytok;

	 kolpopytok = 0;
	 do
	 {
		 //Проверка не более KOLPOP попыток расстановки корабля
		 kolpopytok = kolpopytok + 1;
		 if (kolpopytok > KOLPOP)
		 {
			 //Если сделано KOLPOP попыток корабль поставить нельзя
			 //cout << endl << "Достигнуто ограничение количества попыток расстановки корабля. Корабль поставить не удалось!!!" << endl;
			 //break;
			 return 1; //Ошибка корабль поставить не удалось
		 }

		 x = (int)((rand() / 32767.0) * (N));
		 y = (int)((rand() / 32767.0) * (N));


		 //Проверяем поле чтобы в нем не было другого корабля
		 if (doska->pol[x][y].getklet() == KOR)
		 {
			 continue;
		 }

		 //Работает только для однопалубников!!!
		 //Проверяем соседние поля на наличие в них корабля, но до этого чтобы они не выходили за рамки массива
		 if ((x + 1) < N)
		 {
			 if (doska->pol[x + 1][y].getklet() == KOR)
			 {
				 continue;
			 }
		 }

		 if (((x + 1) < N) && ((y + 1) < N))
		 {
			 if (doska->pol[x + 1][y + 1].getklet() == KOR)
			 {
				 continue;
			 }
		 }

		 if ((y + 1) <= N)
		 {
			 if (doska->pol[x][y + 1].getklet() == KOR)
			 {
				 continue;
			 }
		 }

		 if (((x - 1) >= 0) && ((y + 1) < N))
		 {
			 if (doska->pol[x - 1][y + 1].getklet() == KOR)
			 {
				 continue;
			 }
		 }

		 if (((x - 1) >= 0))
		 {
			 if (doska->pol[x - 1][y].getklet() == KOR)
			 {
				 continue;
			 }
		 }

		 if (((x - 1) >= 0) && ((y - 1) >= 0))
		 {
			 if (doska->pol[x - 1][y - 1].getklet() == KOR)
			 {
				 continue;
			 }
		 }

		 if (((y - 1) >= 0))
		 {
			 if (doska->pol[x][y - 1].getklet() == KOR)
			 {
				 continue;
			 }
		 }

		 if (((x + 1) < N) && ((y - 1) >= 0))
		 {
			 if (doska->pol[x + 1][y - 1].getklet() == KOR)
			 {
				 continue;
			 }
		 }

		 //Если пройдены все этарации цикла и дошли до этого места значит корабль можно поставить
		 break;
	 } while (1);

	 setkoordinata(x, y); //Полиморфизм
	 setpalyba(NEPODBIT);
	 setkorabl(NEPODBIT);
	 doska->pol[x][y].setklet(KOR);
	 return 0; //Установка прошла успешно
 };

 sost Odnopalybnik::proverkakorablya(int x, int y)
 {
	 if ((x == getkoordinataX()) && (y == getkoordinataY()))
	 { 
		 setpalyba(PODBIT);
		 //setkorabl(PODBIT);
		 return UBIT;

	 }
	 else
	 {
		 return NEPODBIT;
	 }
	
 };
