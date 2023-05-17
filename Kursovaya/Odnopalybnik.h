#pragma once
#include "kletka.h"
#include "pole.h"


class Odnopalybnik: public kletka
{
private:
	sost palyba;//Őđŕíčň číôîđěŕöčţ î ńîńňî˙íčč ďŕëóáű ęîđŕáë˙
	//sost korabl; //Őđŕíčň číôîđěŕöčţ î ńîńňî˙íčč ęîđŕáë˙
public:
	Odnopalybnik();
	virtual int ustanovkakorablya(pole* doska); //Óńňŕíîâęŕ íŕ ďîëĺ îäíîďŕëóáíčęŕ
	virtual sost getpalyba(); //getpalyba íĺ íóćĺí ěíîăîďŕëóáíčęó
	virtual void setpalyba(sost p);//setpalyiba íĺ íóćĺí ěíîăîďŕëóáíčęó
	virtual sost proverkakorablya(int x, int y); //Ńďđŕřčâŕĺň ęîđŕáëü ďîďŕëč ëč â íĺăî
	virtual sost getkorabl();
	virtual void setkorabl(sost k);
};
