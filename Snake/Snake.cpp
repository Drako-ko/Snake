// Snake.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <conio.h>

#include <stdlib.h>

using namespace std;

bool GameOver;

const int width = 20;

const int height = 20;

int tailx[100], taily[100];

int nTail;

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

    x = width / 2 - 1;

    y = height / 2 - 1;

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
            if (i == y && j == x) 
            {
                cout << "0";
            }
            else if (i == fruity && j == fruitx) 
            {
                cout << "F";
            }
            else
            {
                bool print = false;

                for (int k = 0; k < nTail; k++)
                {
                    if (tailx[k] == j && taily[k] == i) 
                    {
                        print = true;

                        cout << "o";
                    }
                }
                if (!print) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit()) 
    {
        switch (_getch ())
        {
            case 'a':
            {
                dir = LEFT;

                break;
            }
            case 'w':
            {
                dir = UP;

                break;
            }
            case 'd':
            {
                dir = RIGHT;

                break;
            }
            case 's':
            {
                dir = DOWN;

                break;
            }
            case 'x':
            {
                GameOver = true;

                break;
            }
        }
    }
}

void Logic()
{
    int prevx = tailx[0];

    int prevy = taily[0];

    int prev2x, prev2y;

    tailx[0] = x;

    taily[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2x = tailx[i];

        prev2y = taily[i];

        tailx[i] = prevx;

        taily[i] = prevy;

        prevx = prev2x;

        prevy = prev2y;
    }

    switch (dir)
    {
        case LEFT:
        {
            x--;

            break;
        }
        case RIGHT:
        {
            x++;

            break;
        }
        case UP:
        {
            y--;

            break;
        }
        case DOWN:
        {
            y++;

            break;
        }
    }
    /*
    if (x > width || x < 0 || y > height || y < 0)
    {
        GameOver = true;
    }
    */
    if (x >= width - 1) 
    {
        x = 0;
    }
    else if (x < 0) 
    {
        x = width - 2;
    }
    if (y >= height - 1)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = height - 2;
    }
    for (int i = 0; i < nTail; i++) 
    {
        if (tailx[i] == x && taily[i] == y)
        {
            GameOver = true;
        }
    }
    if (x == fruitx && y == fruity)
    {
        score += 10;

        fruitx = rand() % width;

        fruity = rand() % height;

        nTail++;
    }
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
