#include "Igrok.h"


Igrok::Igrok(string imya)
{
	fdobit = var1; //Íĺň ęîđŕáë˙ ęîňîđűé íóćíî äîáčâŕňü
	napr = 0;  //Íĺň íŕďđŕâëĺíč˙ ďî ęîňîđîěó ńňđĺë˙ĺě
	ch = 0;
	xnach = -1;
	ynach = -1;
	xpre = -1;
	ypre = -1;
	naprmimo[0] = 0;
	naprmimo[1] = 0;
	naprmimo[2] = 0;
	naprmimo[3] = 0;
	this->imya = imya;
	int i, j;
	for (i = 0; i < N; i++) //Číčöčŕëčçŕöč˙ ěŕńńčâŕ ńäĺëŕííűő âűńňđĺëîâ
	{
		for (j = 0; j < N; j++)
		{
			masproverky[i][j] = PUST;
		}
	}
};

void Igrok::vystrel(int* x, int* y, pole* doska) //Ăĺíĺđŕöč˙ ďîë˙ â ęîňîđîĺ čăđîę ńňđĺë˙ĺň
{

	if ((doska->resposlxoda == "Ďîďŕë") && (fdobit == var1)) //Ďĺđâîĺ ďîďŕäŕíčĺ
	{
		fdobit = var2;
	}
	else
	{
		if ((doska->resposlxoda == "Ďîďŕë") && (fdobit == var2)) //Âňîđîĺ ďîďŕäŕíčĺ
		{
			fdobit = var3;
		}
		else
		{
			if ((doska->resposlxoda == "Ďîďŕë") && (fdobit == var3)) //
			{
				fdobit = var3;
			}
			else
			{
				if ((doska->resposlxoda == "Ďîďŕë") && (fdobit == var3A)) //
				{
					fdobit = var3;
				}
				else
				{
					if (((doska->resposlxoda == "Ěčěî") || (doska->resposlxoda == "Ňîćĺ ěčěî")) && (fdobit == var2)) //Ďđîěŕő ďîńëĺ ďĺđâîăî ďîďŕäŕíč˙
					{
						fdobit = var3A;
					}
					else
					{
						if (((doska->resposlxoda == "Ěčěî") || (doska->resposlxoda == "Ňîćĺ ěčěî")) && (fdobit == var3)) //Ďđîěŕő ďîńëĺ ńĺđčč ďîďŕäŕíčé
						{
							fdobit = var4;
						}
						else
						{
							if (doska->resposlxoda == "Óáčň") //Ĺńëč óáčëč ęîđŕáëü
							{
								fdobit = var5;
							}
						}
					}
				}
			}
		}
	}

	if (fdobit == var5)
	{
		//Çŕíîâî číčöčŕëčçčđóĺě ďĺđĺěĺííűĺ
		fdobit = var1; //Íĺň ęîđŕáë˙ ęîňîđűé íóćíî äîáčâŕňü
		napr = 0;  //Íĺň íŕďđŕâëĺíč˙ ďî ęîňîđîěó ńňđĺë˙ĺě
		ch = 0;
		xnach = -1;
		ynach = -1;
		xpre = -1;
		ypre = -1;
		naprmimo[0] = 0;
		naprmimo[1] = 0;
		naprmimo[2] = 0;
		naprmimo[3] = 0;

		//Ďîâňîđ˙ĺě äĺéńňâč˙ âŕđčŕíňŕ 1
		do
		{
			*(x) = round(((double)rand() / 32767) * ((N - 1) - 0) + 0);
			*(y) = round(((double)rand() / 32767) * ((N - 1) - 0) + 0);
		} while (masproverky[*(x)][*(y)] == PUSTPOD);
		masproverky[*(x)][*(y)] = PUSTPOD;

		//Őđŕí˙ň đĺçóëüňŕňŕ ďîńëĺäíĺăî őîäŕ
		xnach = *(x);
		ynach = *(y);
		xpre = xnach;
		ypre = ynach;

		return;
	}

	if (fdobit == var3A)
	{
		//Âűáčđŕĺě íŕďđŕâëĺíčĺ
		do {
			napr = round(((double)rand() / 32767) * (4 - 1) + 1); //Âűáĺđŕĺě îäíî čç 4-ő íŕďđŕâëĺíčé

			if ((napr == naprmimo[0]) || (napr == naprmimo[1]) || (napr == naprmimo[2]))
			{
				continue;
			}
			else
			{
				if ((napr == 1) && (!((xnach + 1) < N)))
				{
					continue;
				}
				if ((napr == 2) && (!((xnach - 1) >= 0)))
				{
					continue;
				}
				if ((napr == 3) && (!((ynach + 1) < N)))
				{
					continue;
				}
				if ((napr == 4) && (!((ynach - 1) >= 0)))
				{
					continue;
				}

				ch = ch + 1;
				naprmimo[ch] = napr;
				break;
			}
		} while (1);

		if (napr == 1)
		{
			xpre = xnach + 1;
			ypre = ynach;
		}
		else
		{
			if (napr == 2)
			{
				xpre = xnach - 1;
				ypre = ynach;
			}
			else
			{
				if (napr == 3)
				{
					ypre = ynach + 1;
					xpre = xnach;
				}
				else
				{
					if (napr == 4)
					{
						ypre = ynach - 1;
						xpre = xnach;
					}
				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	if (fdobit == var3)
	{
		if ((napr == 1) && ((xpre + 1) < N))
		{
			xpre = xpre + 1;
		}
		else
		{
			if ((napr == 2) && ((xpre - 1) >= 0))
			{
				xpre = xpre - 1;
			}
			else {
				if ((napr == 3) && ((ypre + 1) < N))
				{
					ypre = ypre + 1;
				}
				else {
					if ((napr == 4) && ((ypre - 1) >= 0))
					{
						ypre = ypre - 1;
					}
					else
					{
						//Ńäĺńü âŕđčŕíň 4
						if (napr == 1)
						{
							napr = 2;
							xpre = xnach - 1;
						}
						else
						{
							if (napr == 2)
							{
								napr = 1;
								xpre = xnach + 1;
							}
							else
							{
								if (napr == 3)
								{
									napr = 4;
									ypre = ynach - 1;
								}
								else
								{
									if (napr == 4)
									{
										napr = 3;
										ypre = ynach + 1;
									}
								}
							}
						}
					}
				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	//Ěĺí˙ĺě íŕďđŕâëĺíčĺ íŕ ďđîňčâîďîëîćĺííîĺ
	if (fdobit == var4)
	{
		if (napr == 1)
		{
			napr = 2;
			xpre = xnach - 1;
		}
		else
		{
			if (napr == 2)
			{
				napr = 1;
				xpre = xnach + 1;
			}
			else
			{
				if (napr == 3)
				{
					napr = 4;
					ypre = ynach - 1;
				}
				else
				{
					if (napr == 4)
					{
						napr = 3;
						ypre = ynach + 1;
					}


				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		fdobit = var3;
		return;
	}

	if (fdobit == var2)
	{
		//Âűáčđŕĺě íŕďđŕâëĺíčĺ
		do {
			napr = round(((double)rand() / 32767) * (4 - 1) + 1); //Âűáĺđŕĺě îäíî čç 4-ő íŕďđŕâëĺíčé
			if ((napr == 1) && ((xnach + 1) < N))
			{
				break;
			}
			if ((napr == 2) && ((xnach - 1) >= 0))
			{
				break;
			}
			if ((napr == 3) && ((ynach + 1) < N))
			{
				break;
			}
			if ((napr == 4) && ((ynach - 1) >= 0))
			{
				break;
			}
		} while (1);

		naprmimo[ch] = napr;

		if (napr == 1)
		{
			xpre = xnach + 1;
		}
		if (napr == 2)
		{
			xpre = xnach - 1;
		}
		if (napr == 3)
		{
			ypre = ynach + 1;
		}
		if (napr == 4)
		{
			ypre = ynach - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	if (fdobit == var1)
	{
		do
		{
			*(x) = round(((double)rand() / 32767) * ((N - 1) - 0) + 0);
			*(y) = round(((double)rand() / 32767) * ((N - 1) - 0) + 0);
		} while (masproverky[*(x)][*(y)] == PUSTPOD);
		masproverky[*(x)][*(y)] = PUSTPOD;

		//Őđŕí˙ň đĺçóëüňŕňŕ ďîńëĺäíĺăî őîäŕ
		xnach = *(x);
		ynach = *(y);
		xpre = xnach;
		ypre = ynach;
		return;
	}
};

string Igrok::getimya()
{
	return imya;
};