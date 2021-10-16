// Snake.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <stdlib.h>

using namespace std;

bool GameOver;

const int width = 20;

const int height = 20;

int x, y, fruitx, fruity, score;

enum eDirection 
{
    STOP = 0,LEFT,RIGHT,UP,DOWN 
};

eDirection dir;

void Setup()
{
    GameOver = false;

    dir = STOP;

    x = width / 2;

    y = height / 2;

    fruitx = rand() % width;

    fruity = rand() % height;

    score = 0;
}

void Draw()
{
    system("cls"); 

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "#";
            }
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;
}

void Input()
{

}

void Logic()
{

}

int main()
{
    Setup();

    while (!GameOver)
        {
            Draw();

            Input();

            Logic();
        }

    return 0;
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
