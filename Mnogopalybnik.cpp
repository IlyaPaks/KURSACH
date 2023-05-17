#include "Mnogopalybnik.h"

Mnogopalybnik::Mnogopalybnik() //Ïî óìîë÷àíèþ ñîçäàåì äâóõïàëóáíûé êîðàáëü
{
	kolpalyb = 2;
	int i;
	for (i = 0; i < kolpalyb; i++)
	{
		bolkorabl[i] = new Odnopalybnik();
	}
};

Mnogopalybnik::Mnogopalybnik(int k)
{
	if (1 < k <= 4)
	{
		kolpalyb = k;
		int i;
		for (i = 0; i < kolpalyb; i++)
		{
			bolkorabl[i] = new Odnopalybnik();
		}
	}
	else
	{
		kolpalyb = 2;
		int i;
		for (i = 0; i < kolpalyb; i++)
		{
			bolkorabl[i] = new Odnopalybnik();
		}
		cout << endl << "Íå âåðíîå çíà÷åíèå ïàðàìåòðà k, ñîçäàí äâóõïàëáóíûé êîðàáëü!!!" << endl;
	}
};

//Ïåðåêðûâàþ ìåòîäû îäíîïàëóáíèêà
/*sost Mnogopalybnik::getpalyba()
{
	return Odnopalybnik::getpalyba();
};

void Mnogopalybnik::setpalyba(sost p)
{
	Odnopalybnik::setpalyba(p);
};
*/
sost Mnogopalybnik::getkorabl()
{
	int i;
	for (i = 0; i < kolpalyb; i++)
	{
		if (bolkorabl[i]->getpalyba() == NEPODBIT)
		{
			return NEPODBIT;
		}
	}
 	return UBIT;
};

/*void Mnogopalybnik::setkorabl(sost k)
{
	Odnopalybnik::setkorabl(k);
}; */

int Mnogopalybnik::ustanovkakorablya(pole* doska)
{
	int x,y, xk[4], yk[4], napr, kolpopytok,i; //Â ìàññèâå ëåæèò ìàêñèìóì 4 êîîðäèíàòû äëÿ 4õ-ïàëóáíèêà
	
	kolpopytok = 0;
	do
	{
	//Ïðîâåðêà íå áîëåå KOLPOP ïîïûòîê ðàññòàíîâêè êîðàáëÿ
	kolpopytok = kolpopytok + 1;
	if (kolpopytok > KOLPOP)
	{
		//Åñëè ñäåëàíî KOLPOP ïîïûòîê êîðàáëü ïîñòàâèòü íåëüçÿ
		//cout << endl << "Äîñòèãíóòî îãðàíè÷åíèå êîëè÷åñòâà ïîïûòîê ðàññòàíîâêè êîðàáëÿ. Êîðàáëü ïîñòàâèòü íå óäàëîñü!!!" << endl;
		//break;
		return 1; //Îøèáêà êîðàáëü ïîñòàâèòü íå óäàëîñü
	}

	x = (int)((rand() / 32767.0) * (N));
	y = (int)((rand() / 32767.0) * (N));
	napr = (int)((rand() / 32767.0) * (3)) + 1; //Âûáåðàåì îäíî èç 4-õ íàïðàâëåíèé

	for (i = 0; i < kolpalyb; i++)
	{
		//Ïðîâåðÿåì ïîëå ÷òîáû â íåì íå áûëî äðóãîãî êîðàáëÿ
		if (doska->pol[x][y].getklet() == KOR)
		{
			break;
		}

		//Ïðîâåðÿåì ñîñåäíèå ïîëÿ íà íàëè÷èå â íèõ êîðàáëÿ, íî äî ýòîãî ÷òîáû îíè íå âûõîäèëè çà ðàìêè ìàññèâà
		if ((x + 1) < N)
		{
			if (doska->pol[x + 1][y].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x + 1) < N) && ((y + 1) < N))
		{
			if (doska->pol[x + 1][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if ((y + 1) < N)
		{
			if (doska->pol[x][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x - 1) >= 0) && ((y + 1) < N))
		{
			if (doska->pol[x - 1][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x - 1) >= 0))
		{
			if (doska->pol[x - 1][y].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x - 1) >= 0) && ((y - 1) >= 0))
		{
			if (doska->pol[x - 1][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((y - 1) >= 0))
		{
			if (doska->pol[x][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}

		if (((x + 1) < N) && ((y - 1) >= 0))
		{
			if (doska->pol[x + 1][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			//break;
		}
		//Ñîõðàíÿåì ïîäõîäÿùèå êîîðäèíàòû ìíîãîïàëóáíèêà â ìàññèâ
		xk[i] = x; 
		yk[i] = y;

		if ((napr == 1) && ((x + 1) < N))
		{
			x = x + 1;
		}
		else
		{
			if ((napr == 2) && ((x - 1) >= 0))
			{
				x = x - 1;
			}
			else
			{
				if ((napr == 3) && ((y + 1) < N))
				{
					y = y + 1;
				}
				else
				{
					if ((napr == 4) && ((y - 1) >= 0))
					{
						y = y - 1;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	if (i == kolpalyb)
	{
		//Åñëè äîøåë äî kolpalyb èòåðàöèè öèêëà òî óäàëîñü ïîñòàâèòü êîðàáëü
		break;
	}
	} while (1);

	for (i = 0; i < kolpalyb; i++)
	{
		bolkorabl[i]->setkoordinata(xk[i], yk[i]); 
		bolkorabl[i]->setpalyba(NEPODBIT);
		doska->pol[xk[i]][yk[i]].setklet(KOR);
	}
	//setkorabl(NEPODBIT);
	return 0; //Óñòàíîâêà ïðîøëà óñïåøíî
};

sost Mnogopalybnik::proverkakorablya(int x, int y)//Ñïðàøèâàåò êîðàáëü ïîïàëè ëè â íåãî
{
	int i;
	sost res = NEPODBIT;
	for (i = 0; i < kolpalyb; i++)
	{
		if ((x == bolkorabl[i]->getkoordinataX()) && (y == bolkorabl[i]->getkoordinataY()))
		{
			bolkorabl[i]->setpalyba(PODBIT);
			res = PODBIT;

			if (this->getkorabl() == UBIT)
			{
				res = UBIT;
			}

			break;
		}
	}
	return res;
}; 
