#include "pole.h"

pole::pole()
{
	imyapolya = "";
};

void pole::chistka() //×čńňčň ďîëĺ
{
	int i, j;//Ďĺđĺěĺííűĺ ń÷ĺň÷čęč
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < N; j++) 
		{
			pol[i][j].setklet(PUST);
			pol[i][j].setkoordinata(i, j);
		}
	}
};
