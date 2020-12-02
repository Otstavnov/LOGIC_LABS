#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
#include <string>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

int start, i, j, R, N, OOO;
int* dist;
int* visited;
int** graph;
queue<int>Q;


void BFSD(int v, int N, int** graph) {

	Q.push(v);
	dist[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 0; i < N; i++) {
			if ((graph[v][i] > 0) && (dist[i] == -1)) {
				Q.push(i);
				dist[i] = dist[v] + graph[v][i];
			}
		}
	}
}
void BFSD_OR(int v, int N, int** graph) {

	Q.push(v);
	dist[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 0; i < N; i++) {
			if ((graph[v][i] > 0) && (dist[i] == -1)) {
				Q.push(i);
				dist[i] = dist[v] + graph[v][i];
			}
		}
	}
}


void OR_VSV()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//printf("Ведите размер матрицы  ");
	//scanf_s("%d", &N);
	graph = new int* [N];
	dist = new int[N];
	for (int i = 0; i < N; i++)
	{
		graph[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		dist[i] = -1;
	}
	printf("\n Матрица смежности для взвешенного ориентированного графа\n\n");

	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; ++j)
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
	printf("   ");
	for (j = 0; j < N; j++)
	{
		printf("%4d  ", j + 1); //горизонт
	}
	printf("\n\n");
	for (i = 0; i < N; i++) {

		printf(" %d ", i + 1); // вертик

		for (j = 0; j < N; j++)
		{
			printf("%4d  ", graph[i][j]);
		}
		printf("\n\n");
	}
	for (i = 0; i < N; i++)
	{
		printf("\n Из вершины %d есть дорога в ", i + 1);
		for (j = 0; j < N; j++)
		{
			if (graph[i][j] >= 1)
				printf("%d ", j + 1);

		}
	}

	printf("\n\n Введите начальную вершину ");
	scanf("%d", &start);
	BFSD_OR(start - 1, N, graph);
	printf("\n\n Вершины      ");
	for (int i = 1; i <= N; i++) {
		printf("|%3d ", i);
	}
	printf("\n Расстояние   ");
	for (int i = 0; i < N; i++) {
		printf("|%3d ", dist[i]);
	}
	printf("\n\n");
	return;

}

void NOT_OR_NOT_VSV()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//printf("Ведите размер матрицы  ");
	//scanf_s("%d", &N);
	srand(time(NULL));
	graph = new int* [N];
	dist = new int[N];
	visited = new int[N];

	for (int i = 0; i < N; i++)
	{
		graph[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		dist[i] = -1;
	}

	printf("\n Матрица смежности для невзвешенного неориентированного графа \n\n");

	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; ++j)
		{
			graph[i][j] = graph[j][i] = rand() % 2;
			graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
		}

	}
	printf("   ");
	for (j = 0; j < N; j++)
	{
		printf("%4d  ", j + 1); //горизонт
	}
	printf("\n\n");
	for (i = 0; i < N; i++) {

		printf(" %d ", i + 1); // вертик

		for (j = 0; j < N; j++)
		{
			printf("%4d  ", graph[i][j]);
		}
		printf("\n\n");
	}
	for (i = 0; i < N; i++)
	{
		printf("\n Из вершины %d есть дорога в ", i + 1);
		for (j = 0; j < N; j++)
		{
			if (graph[i][j] >= 1)
				printf("%d ", j + 1);

		}
	}

	printf("\n\n Введите начальную вершину ");
	scanf("%d", &start);
	BFSD(start - 1, N, graph);
	printf("\n\n Вершины      ");
	for (int i = 1; i <= N; i++) {
		printf("|%3d ", i);
	}
	printf("\n Расстояние   ");
	for (int i = 0; i < N; i++) {
		printf("|%3d ", dist[i]);
	}
	printf("\n\n");


	return;

}

void OR_NOT_VSV()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//printf("Ведите размер матрицы  ");
	//scanf_s("%d", &N);
	graph = new int* [N];
	dist = new int[N];
	for (int i = 0; i < N; i++)
	{
		graph[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		dist[i] = -1;
	}
	printf("\n Матрица смежности для невзвешенного ориентированного графа\n\n");

	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; ++j)
		{

			R = rand() % 100;
			if (R > 30)
			{
				graph[i][j] = rand() % 2;
				graph[j][i] = 0;
				graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
			}

			else
				graph[i][j] = graph[j][i] = rand() % 2;
			graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
		}

	}
	printf("   ");
	for (j = 0; j < N; j++)
	{
		printf("%4d  ", j + 1); //горизонт
	}
	printf("\n\n");
	for (i = 0; i < N; i++) {

		printf(" %d ", i + 1); // вертик

		for (j = 0; j < N; j++)
		{
			printf("%4d  ", graph[i][j]);
		}
		printf("\n\n");
	}
	for (i = 0; i < N; i++)
	{
		printf("\n Из вершины %d есть дорога в ", i + 1);
		for (j = 0; j < N; j++)
		{
			if (graph[i][j] >= 1)
				printf("%d ", j + 1);

		}
	}

	printf("\n\n Введите начальную вершину ");
	scanf("%d", &start);
	BFSD_OR(start - 1, N, graph);
	printf("\n\n Вершины      ");
	for (int i = 1; i <= N; i++) {
		printf("|%3d ", i);
	}
	printf("\n Расстояние   ");
	for (int i = 0; i < N; i++) {
		printf("|%3d ", dist[i]);
	}
	printf("\n\n");
	return;


}

void NOT_OR_VSV()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//printf("Ведите размер матрицы  ");
	//scanf_s("%d", &N);
	srand(time(NULL));
	graph = new int* [N];
	dist = new int[N];
	visited = new int[N];

	for (int i = 0; i < N; i++)
	{
		graph[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		dist[i] = -1;
	}

	printf("\n Матрица смежности для взвешенного неориентированного графа \n\n");

	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; ++j)
		{
			graph[i][j] = graph[j][i] = rand() % 10;
			graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
		}

	}
	printf("   ");
	for (j = 0; j < N; j++)
	{
		printf("%4d  ", j + 1); //горизонт
	}
	printf("\n\n");
	for (i = 0; i < N; i++) {

		printf(" %d ", i + 1); // вертик

		for (j = 0; j < N; j++)
		{
			printf("%4d  ", graph[i][j]);
		}
		printf("\n\n");
	}
	for (i = 0; i < N; i++)
	{
		printf("\n Из вершины %d есть дорога в ", i + 1);
		for (j = 0; j < N; j++)
		{
			if (graph[i][j] >= 1)
				printf("%d ", j + 1);

		}
	}

	printf("\n\n Введите начальную вершину ");
	scanf("%d", &start);
	BFSD(start - 1, N, graph);
	printf("\n\n Вершины      ");
	for (int i = 1; i <= N; i++) {
		printf("|%3d ", i);
	}
	printf("\n Расстояние   ");
	for (int i = 0; i < N; i++) {
		printf("|%3d ", dist[i]);
	}
	printf("\n\n");

	return;
}


int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int OR = 0;
	int VSV = 0;

	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "size") == 0)
			N = stoi(argv[i + 1]);
	}



	for (int i = 0; i < argc; ++i)
	{
		if (strcmp(argv[i], "o") == 0)
			OR = 1;

		if (strcmp(argv[i], "v") == 0)
			VSV = 1;
	}

	if ((VSV == 1) & (OR == 1))
		OR_VSV(); 
	if ((VSV == 1) & (OR == 0))
		NOT_OR_VSV();
	if ((VSV == 0) & (OR == 1))
		OR_NOT_VSV();
	else
		NOT_OR_NOT_VSV();
		
	
	//for (int i = 0; i < argc; i++)
	//{
	//	if (strcmp(argv[i], "vsv?") == 0)
	//	{
	//		if (strcmp(argv[i + 1], "da") == 0)
	//		{
	//			if (strcmp(argv[i + 2], "or?") == 0)
	//			{
	//				if (strcmp(argv[i + 3], "da") == 0)
	//				{
	//					OOO = 1;
	//				}
	//				if (strcmp(argv[i + 3], "no") == 0)
	//				{
	//					OOO = 2;
	//				}
	//			}
	//		}
	//		if (strcmp(argv[i + 1], "no") == 0)
	//		{
	//			if (strcmp(argv[i + 2], "or?") == 0)
	//			{
	//				if (strcmp(argv[i + 3], "da") == 0)
	//				{
	//					OOO = 3;
	//				}
	//				if (strcmp(argv[i + 3], "no") == 0)
	//				{
	//					OOO = 4;
	//				}
	//			}
	//		}
	//	}
	//	if (strcmp(argv[i], "or?") == 0)
	//	{
	//		if (strcmp(argv[i + 1], "da") == 0)
	//		{
	//			if (strcmp(argv[i + 2], "vsv?") == 0)
	//			{
	//				if (strcmp(argv[i + 3], "da") == 0)
	//				{
	//					OOO = 1;
	//				}
	//				if (strcmp(argv[i + 3], "no") == 0)
	//				{
	//					OOO = 3;
	//				}
	//			}
	//		}
	//		if (strcmp(argv[i + 1], "no") == 0)
	//		{
	//			if (strcmp(argv[i + 2], "vsv?") == 0)
	//			{
	//				if (strcmp(argv[i + 3], "da") == 0)
	//				{
	//					OOO = 2;
	//				}
	//				if (strcmp(argv[i + 3], "no") == 0)
	//				{
	//					OOO = 4;
	//				}
	//			}
	//		}
	//	}
	//}

	system("pause");
}