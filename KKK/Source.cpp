#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

int i, j, n, p, x_start, x_end, CMND, type, visited[ 200];
unsigned int graph[200][200], dist[200];
char Temp[200], way[200][200], save[5], save1[5], ex[5];
char da[] = "да"; char Da[] = "Да";
FILE* res;

void DIJKSTRA()
{
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        dist[i] = 50000;
    }

    dist[x_start] = 0;
    visited[x_start] = 1;
    p = x_start;
    _itoa_s(x_start + 1, Temp, 10);

    for (i = 1; i <= n; i++)
    {
        strcpy_s(way[i], "X");
        strcat_s(way[i], Temp);
    }

    do
    {
        for (i = 0; i < n; i++)
        {
            if ((graph[p][i] != 50000) && (!visited[i]) && (i != p))
            {
                if (dist[i] > dist[p] + graph[p][i])
                {
                    _itoa_s(i + 1, Temp, 10);
                    strcpy_s(way[i + 1], way[p + 1]);
                    strcat_s(way[i + 1], " -> X");
                    strcat_s(way[i + 1], Temp);
                }
                if (dist[i] > dist[p] + graph[p][i])
                    dist[i] = dist[p] + graph[p][i];
                else
                    dist[i] = dist[i] + 0;
            }
        }
        for (i = 0; i < n; i++)
            if (!(visited[i]))
                p = i;
     
        for (i = 0; i < n; i++)
            if ((dist[p] > dist[i]) && (!visited[i]))
                p = i;
        
        visited[p] = 1;
    } while (p != x_end);
}

void HAND()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("\n Тип вводимого графа:\n 1. Ориентированный\n 2. Неориентированный \n Выберите тип - ");
    scanf("%d", &type);
    while (type > 2)
    {
        printf("\n Номер такого типа не существует\n Выберите тип заново - ");
        scanf("%d", &type);
    }

    printf(" Введите количество вершин графа - ");
    scanf_s("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    if (type == 1) 
    {
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)

            {
                printf(" Введите расстояние из %d в %d  -  ", i + 1, j + 1);
                scanf_s("%d", &graph[i][j]);
                printf(" Введите расстояние из %d в %d  -  ", j + 1, i + 1);
                scanf_s("%d", &graph[j][i]);
            }
        }
    }
    if (type == 2) 
    {
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)

            {
                printf(" Введите расстояние из %d в %d  -  ", i + 1, j + 1);
                scanf_s("%d", &graph[i][j]);
                graph[j][i] = graph[i][j];
            }
        }
    }
    printf("\n\n   ");

    for (j = 0; j < n; j++)
    {
        printf("%4d  ", j + 1); //горизонт
    }
    printf("\n\n");

    for (i = 0; i < n; i++)
    {
        printf(" %d ", i + 1); // вертик

        for (j = 0; j < n; j++)
        {
            printf("%4d  ", graph[i][j]);
        }
        printf("\n\n");

    }

    
    printf(" Сохранить матрицу в файл?  ");
    scanf("%s", &save);
    if ((strcmp(da, save) == 0) || (strcmp(Da, save) == 0))
    {
        res = fopen("РЕЗУЛЬТАТ ТУТ.txt", "w");
        fprintf(res, " Размер матрицы смежности графа %dx%d  \n\n   ", n, n);
        for (j = 0; j < n; j++)
        {
            fprintf(res, "%4d  ", j + 1); //горизонт
        }
        fprintf(res, "\n\n");
        for (i = 0; i < n; i++)
        {
            fprintf(res, " %d ", i + 1); // вертик

            for (j = 0; j < n; j++)
            {
                fprintf(res, "%4d  ", graph[i][j]);
            }
            fprintf(res, "\n\n");

        }
        fclose(res);
    }
   
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) 
        {
            if (graph[i][j] == 0) graph[i][j] = 50000;
        }
    }

    printf(" Введите начальную вершину - ");
    scanf("%d", &x_start);
    while (x_start > n)
    {
        printf(" Такой вершины не существует! \n Введите начальную вершину заново - ");
        scanf("%d", &x_start);
    }

    printf(" Введите конечную вершину - ");
    scanf("%d", &x_end);
    while (x_end > n)
    {
        printf(" Такой вершины не существует!\n Введите конечную вершину заново - ");
        scanf("%d", &x_end);
    }

    while (x_start == x_end)
    {
        printf(" Начальная и конечная вершины совпадают\n");

        printf(" Введите начальную вершину заново - ");
        scanf("%d", &x_start);
        while (x_start > n)
        {
            printf(" Такой вершины не существует!\n Введите начальную вершину заново - ");
            scanf("%d", &x_start);
        }

        printf(" Введите конечную вершину заново - ");
        scanf("%d", &x_end);
        while (x_end > n)
        {
            printf(" Такой вершины не существует!\n Введите конечную вершину заново - ");
            scanf("%d", &x_end);
        }

    }

    x_end--;
    x_start--;
   
    DIJKSTRA();
  
    if (dist[p] != 50000)
    {
        printf("\n Путь - %s", way[p + 1]);
        printf("\n");
        printf(" Расстояние - %u \n\n", dist[p]);
    }

    else
       printf("\n Пути из %d в %d не существует\n\n ", x_start + 1, x_end + 1);
    
    printf(" Сохранить результат в файл?  ");
    scanf("%s", &save1);
    
    if ((strcmp(da, save1) == 0) || (strcmp(Da, save1) == 0))
    {
        res = fopen("РЕЗУЛЬТАТ ТУТ.txt", "a");
        fprintf(res, "\n Путь - %s", way[p + 1]);
        fprintf(res, "\n Расстояние - %u", dist[p]);
        fclose(res);
    }
    _getch;
}

void RAND()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int R;
    printf("\n Тип создаваемого графа:\n 1. Ориентированный\n 2. Неориентированный \n Выберите тип - ");
    scanf("%d", &type);
    while (type > 2)
    {
        printf("\n Номер такого типа не существует\n Выберите тип заново - ");
        scanf("%d", &type);
    }

    printf("\n Введите количество вершин графа - ");
    scanf_s("%d", &n);
    system("cls");

    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    if (type == 1) {
        printf(" Матрица смежности для ориентированного графа\n");
        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; ++j)
            {

                R = rand() % 100;
                if (R > 30)
                {
                    graph[i][j] = rand() % 10;
                    graph[j][i] = 0;
                    graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
                }

                else
                    graph[i][j] = graph[j][i] = rand() % 10;
                graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
            }

        }
    }
    if (type == 2) {
        printf(" Матрица смежности для неориентированного графа\n");

        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; ++j)
            {
                graph[i][j] = graph[j][i] = rand() % 10;
                graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
            }

        }
    }
    printf("\n   ");

    for (j = 0; j < n; j++)
    {
        printf("%4d  ", j + 1); //горизонт
    }
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", i + 1); // вертик

        for (j = 0; j < n; j++)
        {
            printf("%4d  ", graph[i][j]);
        }
        printf("\n\n");

    }
    
    printf(" Сохранить матрицу в файл?  ");
    scanf("%s", &save);
    if ((strcmp(da, save) == 0) || (strcmp(Da, save) == 0))
    {
        
        res = fopen("РЕЗУЛЬТАТ ТУТ.txt", "w");
        fprintf(res, " Размер матрицы смежности графа %dx%d  \n\n   ", n, n);
        for (j = 0; j < n; j++)
        {
            fprintf(res, "%4d  ", j + 1); //горизонт
        }

        fprintf(res, "\n\n");

        for (i = 0; i < n; i++)
        {
            fprintf(res, " %d ", i + 1); // вертик

            for (j = 0; j < n; j++)
            {
                fprintf(res, "%4d  ", graph[i][j]);
            }
            fprintf(res, "\n\n");
        }


        fclose(res);
    }
    
    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

            if (graph[i][j] == 0) graph[i][j] = 50000; //бесконечность

    printf(" Введите начальную вершину - ");
    scanf("%d", &x_start);
    while (x_start > n)
    {
        printf(" Такой вершины не существует! \n Введите начальную вершину заново - ");
        scanf("%d", &x_start);
    }
    printf(" Введите конечную вершину - ");
    scanf("%d", &x_end);
    while (x_end > n)
    {
        printf(" Такой вершины не существует!\n Введите конечную вершину заново - ");
        scanf("%d", &x_end);
    }

    while(x_start == x_end)
    {

        printf(" Начальная и конечная вершины совпадают\n");
        printf(" Введите начальную вершину заново - ");
        scanf("%d", &x_start);
        while (x_start > n)
        {
            printf(" Такой вершины не существует!\n Введите начальную вершину заново - ");
            scanf("%d", &x_start);
        }
        printf(" Введите конечную вершину заново - ");
        scanf("%d", &x_end);
        while (x_end > n)
        {
            printf(" Такой вершины не существует!\n Введите конечную вершину заново - ");
            scanf("%d", &x_end);
        }
    }
    x_end--;
    x_start--;
    DIJKSTRA();

    if (dist[p] != 50000)

    {
        printf("\n Путь - %s", way[p + 1]);
        printf("\n");
        printf(" Расстояние - %u \n\n", dist[p]);

    }

    else

        printf("\n Пути из %d в %d не существует\n\n", x_start + 1, x_end + 1);
    
    printf(" Сохранить результат в файл?  ");
    scanf("%s", &save1);
    res = fopen("РЕЗУЛЬТАТ ТУТ.txt", "a");
    if((strcmp(da, save1) == 0) || (strcmp(Da, save1) == 0))
    {
        fprintf(res, "\n Путь - %s", way[p + 1]);
        fprintf(res, "\n Расстояние - %u", dist[p]);
    }
    fclose(res);
    _getch;

}

void MENU()
{

    system("cls");

    printf("\n Меню программы ");
    printf("\n 1. Создать граф автоматически");
    printf("\n 2. Создать граф вручную");
    printf("\n 3. Завершение работы");

    printf("\n\n Введите номер команды - ");
    scanf("%d", &CMND);
    while( CMND > 3)
    {
        system("cls");
        printf("\n Меню программы ");
        printf("\n 1. Создать граф автоматически");
        printf("\n 2. Создать граф вручную");
        printf("\n 3. Завершение работы");

        printf("\n\n Введите номер команды - ");
        scanf("%d", &CMND);
    }
    system("cls");


    return;
}

void TITLE()
{
    printf("\n Курсовая работа по дисциплине");
    printf("\n Логика и основы алгоритмизации в инженерных задачах");
    printf("\n На тему \"Реализация алгоритма Дейкстры\"");
    printf("\n\n Выполнил студент группы 19ВВ2");
    printf("\n Отставнов А.М.");
    printf("\n\n Приняли");
    printf("\n Митрохин М.А.\n Юрова О.В.");
    printf("\n\n ");
    system("pause");
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TITLE();
    do {
        MENU();
        switch (CMND)
        {
        case 1:
            RAND();
            break;
        case 2:
            HAND();
            break;

        case 3:
            return 0;
        }
        if (CMND != 3)
            system("pause");
    } while (CMND != 3);
}