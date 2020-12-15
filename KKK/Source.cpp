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
char da[] = "��"; char Da[] = "��";
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
    printf("\n ��� ��������� �����:\n 1. ���������������\n 2. ����������������� \n �������� ��� - ");
    scanf("%d", &type);
    while (type > 2)
    {
        printf("\n ����� ������ ���� �� ����������\n �������� ��� ������ - ");
        scanf("%d", &type);
    }

    printf(" ������� ���������� ������ ����� - ");
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
                printf(" ������� ���������� �� %d � %d  -  ", i + 1, j + 1);
                scanf_s("%d", &graph[i][j]);
                printf(" ������� ���������� �� %d � %d  -  ", j + 1, i + 1);
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
                printf(" ������� ���������� �� %d � %d  -  ", i + 1, j + 1);
                scanf_s("%d", &graph[i][j]);
                graph[j][i] = graph[i][j];
            }
        }
    }
    printf("\n\n   ");

    for (j = 0; j < n; j++)
    {
        printf("%4d  ", j + 1); //��������
    }
    printf("\n\n");

    for (i = 0; i < n; i++)
    {
        printf(" %d ", i + 1); // ������

        for (j = 0; j < n; j++)
        {
            printf("%4d  ", graph[i][j]);
        }
        printf("\n\n");

    }

    
    printf(" ��������� ������� � ����?  ");
    scanf("%s", &save);
    if ((strcmp(da, save) == 0) || (strcmp(Da, save) == 0))
    {
        res = fopen("��������� ���.txt", "w");
        fprintf(res, " ������ ������� ��������� ����� %dx%d  \n\n   ", n, n);
        for (j = 0; j < n; j++)
        {
            fprintf(res, "%4d  ", j + 1); //��������
        }
        fprintf(res, "\n\n");
        for (i = 0; i < n; i++)
        {
            fprintf(res, " %d ", i + 1); // ������

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

    printf(" ������� ��������� ������� - ");
    scanf("%d", &x_start);
    while (x_start > n)
    {
        printf(" ����� ������� �� ����������! \n ������� ��������� ������� ������ - ");
        scanf("%d", &x_start);
    }

    printf(" ������� �������� ������� - ");
    scanf("%d", &x_end);
    while (x_end > n)
    {
        printf(" ����� ������� �� ����������!\n ������� �������� ������� ������ - ");
        scanf("%d", &x_end);
    }

    while (x_start == x_end)
    {
        printf(" ��������� � �������� ������� ���������\n");

        printf(" ������� ��������� ������� ������ - ");
        scanf("%d", &x_start);
        while (x_start > n)
        {
            printf(" ����� ������� �� ����������!\n ������� ��������� ������� ������ - ");
            scanf("%d", &x_start);
        }

        printf(" ������� �������� ������� ������ - ");
        scanf("%d", &x_end);
        while (x_end > n)
        {
            printf(" ����� ������� �� ����������!\n ������� �������� ������� ������ - ");
            scanf("%d", &x_end);
        }

    }

    x_end--;
    x_start--;
   
    DIJKSTRA();
  
    if (dist[p] != 50000)
    {
        printf("\n ���� - %s", way[p + 1]);
        printf("\n");
        printf(" ���������� - %u \n\n", dist[p]);
    }

    else
       printf("\n ���� �� %d � %d �� ����������\n\n ", x_start + 1, x_end + 1);
    
    printf(" ��������� ��������� � ����?  ");
    scanf("%s", &save1);
    
    if ((strcmp(da, save1) == 0) || (strcmp(Da, save1) == 0))
    {
        res = fopen("��������� ���.txt", "a");
        fprintf(res, "\n ���� - %s", way[p + 1]);
        fprintf(res, "\n ���������� - %u", dist[p]);
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
    printf("\n ��� ������������ �����:\n 1. ���������������\n 2. ����������������� \n �������� ��� - ");
    scanf("%d", &type);
    while (type > 2)
    {
        printf("\n ����� ������ ���� �� ����������\n �������� ��� ������ - ");
        scanf("%d", &type);
    }

    printf("\n ������� ���������� ������ ����� - ");
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
        printf(" ������� ��������� ��� ���������������� �����\n");
        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; ++j)
            {

                R = rand() % 100;
                if (R > 30)
                {
                    graph[i][j] = rand() % 10;
                    graph[j][i] = 0;
                    graph[i][i] = graph[j][j] = 0; // ����� �����(����) �� �����������
                }

                else
                    graph[i][j] = graph[j][i] = rand() % 10;
                graph[i][i] = graph[j][j] = 0; // ����� �����(����) �� �����������
            }

        }
    }
    if (type == 2) {
        printf(" ������� ��������� ��� ������������������ �����\n");

        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; ++j)
            {
                graph[i][j] = graph[j][i] = rand() % 10;
                graph[i][i] = graph[j][j] = 0; // ����� �����(����) �� �����������
            }

        }
    }
    printf("\n   ");

    for (j = 0; j < n; j++)
    {
        printf("%4d  ", j + 1); //��������
    }
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", i + 1); // ������

        for (j = 0; j < n; j++)
        {
            printf("%4d  ", graph[i][j]);
        }
        printf("\n\n");

    }
    
    printf(" ��������� ������� � ����?  ");
    scanf("%s", &save);
    if ((strcmp(da, save) == 0) || (strcmp(Da, save) == 0))
    {
        
        res = fopen("��������� ���.txt", "w");
        fprintf(res, " ������ ������� ��������� ����� %dx%d  \n\n   ", n, n);
        for (j = 0; j < n; j++)
        {
            fprintf(res, "%4d  ", j + 1); //��������
        }

        fprintf(res, "\n\n");

        for (i = 0; i < n; i++)
        {
            fprintf(res, " %d ", i + 1); // ������

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

            if (graph[i][j] == 0) graph[i][j] = 50000; //�������������

    printf(" ������� ��������� ������� - ");
    scanf("%d", &x_start);
    while (x_start > n)
    {
        printf(" ����� ������� �� ����������! \n ������� ��������� ������� ������ - ");
        scanf("%d", &x_start);
    }
    printf(" ������� �������� ������� - ");
    scanf("%d", &x_end);
    while (x_end > n)
    {
        printf(" ����� ������� �� ����������!\n ������� �������� ������� ������ - ");
        scanf("%d", &x_end);
    }

    while(x_start == x_end)
    {

        printf(" ��������� � �������� ������� ���������\n");
        printf(" ������� ��������� ������� ������ - ");
        scanf("%d", &x_start);
        while (x_start > n)
        {
            printf(" ����� ������� �� ����������!\n ������� ��������� ������� ������ - ");
            scanf("%d", &x_start);
        }
        printf(" ������� �������� ������� ������ - ");
        scanf("%d", &x_end);
        while (x_end > n)
        {
            printf(" ����� ������� �� ����������!\n ������� �������� ������� ������ - ");
            scanf("%d", &x_end);
        }
    }
    x_end--;
    x_start--;
    DIJKSTRA();

    if (dist[p] != 50000)

    {
        printf("\n ���� - %s", way[p + 1]);
        printf("\n");
        printf(" ���������� - %u \n\n", dist[p]);

    }

    else

        printf("\n ���� �� %d � %d �� ����������\n\n", x_start + 1, x_end + 1);
    
    printf(" ��������� ��������� � ����?  ");
    scanf("%s", &save1);
    res = fopen("��������� ���.txt", "a");
    if((strcmp(da, save1) == 0) || (strcmp(Da, save1) == 0))
    {
        fprintf(res, "\n ���� - %s", way[p + 1]);
        fprintf(res, "\n ���������� - %u", dist[p]);
    }
    fclose(res);
    _getch;

}

void MENU()
{

    system("cls");

    printf("\n ���� ��������� ");
    printf("\n 1. ������� ���� �������������");
    printf("\n 2. ������� ���� �������");
    printf("\n 3. ���������� ������");

    printf("\n\n ������� ����� ������� - ");
    scanf("%d", &CMND);
    while( CMND > 3)
    {
        system("cls");
        printf("\n ���� ��������� ");
        printf("\n 1. ������� ���� �������������");
        printf("\n 2. ������� ���� �������");
        printf("\n 3. ���������� ������");

        printf("\n\n ������� ����� ������� - ");
        scanf("%d", &CMND);
    }
    system("cls");


    return;
}

void TITLE()
{
    printf("\n �������� ������ �� ����������");
    printf("\n ������ � ������ �������������� � ���������� �������");
    printf("\n �� ���� \"���������� ��������� ��������\"");
    printf("\n\n �������� ������� ������ 19��2");
    printf("\n ��������� �.�.");
    printf("\n\n �������");
    printf("\n �������� �.�.\n ����� �.�.");
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