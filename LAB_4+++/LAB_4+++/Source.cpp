#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
#include <vector>
#include <locale>

using namespace std;
using Edge = int;
using Vertex = vector<Edge>;
using Graph = vector<Vertex>;
int i, j, m, k;
bool* visited = new bool[m];
bool* visit = new bool[m];
int** graph;
stack <int> s;
stack <int> ss;
Graph GRAPH_1;



void DFS_NO_REC(int st)
{

	visited[st] = true;
	ss.push(st);
	int v;

	while (!ss.empty())
	{

		v = ss.top();
		ss.pop();
		printf("%d ", v + 1);
		for (i = 0; i < m; i++)
		{

			if ((graph[v][i] == 1) && (!visited[i]))
			{

				visited[i] = 1;
				ss.push(i);

			}
		}

	}
}

void DFS_REC(int st)
{
	int r;
	printf("%d ", st + 1);
	visited[st] = true;
	for (r = 0; r <= m; r++)
		if ((graph[st][r] == 1) && (!visited[r]))
			DFS_REC(r);
}

void DFS_REC_LIST(int v)
{
	{
		if (visit[v]) { // если мы были в данной вершине, то уходим из нее
			return;
		}
		visit[v] = 1; // говорим что уже были в этой вершине
		printf("%d ", v + 1);
		for (int i : GRAPH_1[v]) { // цикл, основанный на диапазоне
			DFS_REC_LIST(i); // запускаем новый обход от каждого соседа
		}
	}
}

void DFS_main()
{
	setlocale(LC_ALL, "Rus");
	printf("Введите размерность матрицы: ");
	scanf_s("%d", &m);
	graph = new int* [m];
	for (int i = 0; i < m; i++) {
		graph[i] = new int[m];
	}

	int start;
	printf("Матрица смежности:\n");
	srand(time(NULL));
	for (i = 0; i < m; ++i)
		for (j = i; j < m; ++j) {
			graph[i][j] = graph[j][i] = rand() % 2;
			graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
		}
	printf("   ");
	for (j = 0; j < m; j++)
	{
		printf("   %d ", j + 1); //горизонт
	}
	printf("\n\n");
	for (i = 0; i < m; ++i)
	{
		printf(" %d ", i + 1); // вертик
		visited[i] = false;

		for (j = 0; j < m; ++j)
			printf("%4d ", graph[i][j]); // сама матрица
		printf("\n\n");
	}


	GRAPH_1.resize(m);
	for (i = 0; i < m; i++)
	{
		printf("\nВершина %d смежна с ", i + 1);
		for (j = 0; j < m; j++) {
			if (graph[i][j] == 1)
			{
				printf("%d ", j + 1);
				GRAPH_1[i].push_back(j);
			}
		}

	}

	printf("\nВведите вершину: ");
	scanf_s("%d", &start);
	while (start > m) {
		printf("\nТакая вершина не существует!\n");
		printf("\nВведи вершину: ");
		scanf_s("%d", &start);
	}

	bool* vis = new bool[m];

	printf("\nПорядок обхода матрицы(не рекурсия):  ");
	DFS_NO_REC(start - 1);
	for (i = 0; i < m; i++) {
		visited[i] = false;

	}
	printf("\nПорядок обхода матрицы (рекурсия):    ");
	DFS_REC(start - 1);
	for (i = 0; i < m; i++) {
		visit[i] = false;
	}
	printf("\nПорядок обхода списка (рекурсия):     ");
	DFS_REC_LIST(start - 1);


	system("pause");
}

void main(void)
{
	DFS_main();
}

