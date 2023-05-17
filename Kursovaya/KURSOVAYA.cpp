// Kursovaya.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
﻿// KURSOVAYA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Ecran.h"
#include "Igrok.h"
#include "Odnopalybnik.h"
#include "Mnogopalybnik.h"
#include "Igra.h"
#include <conio.h>

using namespace std;

string s1 = "Ivan";
string s2 = "Maksim";

pole doska1, doska2; //Доски игроков 1 - игрок, 2 - противник
Odnopalybnik* korabli1[MMAX];
Odnopalybnik* korabli2[MMAX];
Ecran ecranchik;
Igrok igrok1(s1), igrok2(s2);
Igra Morskoyboy;

int X, Y, f, c, i, f1, indekator1, indekator2, schetchikk;

int N; //Фактическая размерность поля при отчете с 1

int kolodnoGEL;//Желаемое Количество однопалубников
int koldvyGEL; //Желаемое Количество двупалубников
int koltreGEL; //Желаемое Количество трехпалубников
int kolchetireGEL; //Желаемое Количество четырехпалубников
int MGEL = MMAX; //Желаемое Количество кораблей у игрока

int kolodno;//Фактическая Количество однопалубников
int koldvy; //Фактическая Количество двупалубников
int koltre; //Фактическая Количество трехпалубников
int kolchetire; //Фактическая Количество четырехпалубников
int M = MMAX; //Фактическая Количество кораблей у игрока

int main()
{
    setlocale(LC_ALL, "RUS");

    N = NFIX;

    kolodno = kolodnoFIX;
    koldvy = koldvyFIX;
    koltre = koltreFIX;
    kolchetire = kolchetireFIX;

    M = kolodno + koldvy + koltre + kolchetire;


    string nachsnaach;
    //Инициализация генератора случайных чисел
    srand(time(NULL));

    do {
        //Блок начала игры
        system("cls");
        cout << "Приветсвуем в игре Морской бой!" << endl << endl;

        do {
            cout << "Введите размер поля(стандартный размер 10) но не менее " << NMIN << " и не более " << NMAX << ": ";
            cin >> N;
            cout << endl;

        } while (N < NMIN || N > NMAX);

        do {
            cout << "Введите количество кораблей четырехпалубников но не более " << N / 4 << ": ";
            cin >> kolchetire;

        } while (kolchetire < 0 || kolchetire > N / 4);

        do {
            cout << "Введите количество кораблей трехпалубников    но не более " << N / 2 << ": ";
            cin >> koltre;

        } while (koltre < 0 || koltre > N / 2);

        do {
            cout << "Введите количество кораблей двухпалубников    но не более " << N << ": ";
            cin >> koldvy;

        } while (koldvy < 0 || koldvy > N);

        do {
            cout << "Введите количество кораблей однопалубников    но не более " << 2 * N << ": ";
            cin >> kolodno;

        } while (kolodno < 1 || kolodno > 2 * N);

        M = kolodno + koldvy + koltre + kolchetire;

        system("cls");
        cout << "Приветсвуем в игре Морской бой!" << endl;
        cout << "Игрок 1: " << s1 << endl;
        cout << "Игрок 2: " << s2 << endl;
        Igra::igrokperviy = s1;
        Igra::igrokvtoroy = s2;

        doska1.imyapolya = igrok1.getimya();
        doska2.imyapolya = igrok2.getimya();



        //Блок создания кораблей
        for (i = 0; i < kolodno; i++)
        {
            korabli1[i] = new Odnopalybnik();
            korabli2[i] = new Odnopalybnik();
        }
        for (i = 0; i < koldvy; i++)
        {
            korabli1[i + kolodno] = new Mnogopalybnik(2);
            korabli2[i + kolodno] = new Mnogopalybnik(2);
        }
        for (i = 0; i < koltre; i++)
        {
            korabli1[i + kolodno + koldvy] = new Mnogopalybnik(3);
            korabli2[i + kolodno + koldvy] = new Mnogopalybnik(3);
        }
        for (i = 0; i < kolchetire; i++)
        {
            korabli1[i + kolodno + koldvy + koltre] = new Mnogopalybnik(4);
            korabli2[i + kolodno + koldvy + koltre] = new Mnogopalybnik(4);
        }

        schetchikk = 1;
        indekator1 = 0;
        indekator2 = 0;

        do
        {
            if (indekator1 == 0)
            {
                indekator1 = Morskoyboy.rasstanovka(korabli1, &doska1);
            }
            if ((indekator1 == 0) && (indekator2 == 0))
            {
                indekator2 = Morskoyboy.rasstanovka(korabli2, &doska2);
            }

            if ((indekator1 == 0) && (indekator2 == 0))
            {
                break;
            }
            else
            {
                if (indekator1 == 1)
                {
                    doska1.chistka();
                    indekator1 = 0;
                }
                if (indekator2 == 1)
                {
                    doska2.chistka();
                    indekator2 = 0;
                }
            }

            schetchikk = schetchikk + 1;
        } while (schetchikk < KOLRAZ);

        if (schetchikk >= KOLRAZ)
        {
            cout << endl << "Расстановка кораблей не удалась, запустите игру снова " << endl << endl;
        }
        else
        {
            ecranchik.prorisovkapolya(&doska1);
            ecranchik.prorisovkapolya(&doska2);

            //Решить кто первый ходит
            cout << endl << endl << endl << endl;
            cout << "Первым ходит игрок " << s1 << endl;
            cout << "Нажмите любую клавишу... ";
            c = _getch();

            //Блок хода игры
            do {

                if ((Morskoyboy.scetchikXodov % 2) == 0)
                {
                    igrok1.vystrel(&X, &Y, &doska2);
                    Morskoyboy.hod(korabli2, &doska2, X, Y);

                    ecranchik.prorisovkashapki(&doska1);
                    if (Morskoyboy.scetchikXodov == 0)
                    {
                        //Прорисовка 1 хода
                        system("cls");
                        ecranchik.prorisovkashapki(&doska1);
                        ecranchik.prorisovkapolya(&doska1);
                        ecranchik.prorisovkapolya(&doska2);
                    }
                    else
                    {
                        ecranchik.prorisovkastroki(&doska1, X, Y, 1);
                        ecranchik.prorisovkastroki(&doska2, X, Y, 2);
                    }
                    cout << "          " << "Этот ход сделал игрок: " << Igra::igrokperviy << "                 " << endl; //Длинный пробел перезатрет более длинное слово
                    ecranchik.prorisovkapodvala(&doska2);

                    f = Morskoyboy.konecigry(korabli2);//1 - если игры продолжается, 0 - если закончилась
                    if (f == 0)
                    {
                        Morskoyboy.setimyapobeditelya(s1);
                    }
                }

                else
                {
                    igrok2.vystrel(&X, &Y, &doska1);
                    Morskoyboy.hod(korabli1, &doska1, X, Y);

                    ecranchik.prorisovkashapki(&doska1);
                    ecranchik.prorisovkastroki(&doska1, X, Y, 1);
                    ecranchik.prorisovkastroki(&doska2, X, Y, 2);
                    cout << "          " << "Этот ход сделал игрок: " << Igra::igrokvtoroy << "                 " << endl; //Длинный пробел перезатрет более длинное слово
                    ecranchik.prorisovkapodvala(&doska1);

                    f = Morskoyboy.konecigry(korabli1);//1 - если игры продолжается, 0 - если закончилась
                    if (f == 0)
                    {
                        Morskoyboy.setimyapobeditelya(s2);
                    }
                }
                Morskoyboy.scetchikXodov = Morskoyboy.scetchikXodov + 1;

                Sleep(ZAD); //Задержка перед следующим ходом
                //cout << "Следующий ход... "; //Задержка после каждого хода
                //c = _getch();

            } while (f);



            //Блок конца игры
            system("cls");
            cout << endl << endl << endl;
            ecranchik.prorisovkapolya(&doska1);
            ecranchik.prorisovkapolya(&doska2);

            cout << "Победил игрок: " << Morskoyboy.getimyapobeditelya() << endl << endl;



        }
        cout << "Если вы хотите закончить игру введите 1" << endl;
        cout << "Если вы хотите начать игру заново введите любой символ" << endl;
        cout << "> ";
        cin >> nachsnaach;

        //Чистим память от объектов корабли
        for (i = 0; i < M; i++)
        {
            free(korabli1[i]);
            free(korabli2[i]);
        }
        doska1.chistka();
        doska2.chistka();
        igrok1.Igrok::Igrok(s1);
        igrok2.Igrok::Igrok(s2);
        Morskoyboy.scetchikXodov = 0;
    } while (nachsnaach != "1");
    cout << "Вы закончили игру";
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.