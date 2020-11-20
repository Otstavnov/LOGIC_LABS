#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
int* dist;
int* visited;
int** graph;
queue<int>Q;
int start;
int N, j, i;

void BFSD(int vertex, int N, int** graph) {
	
	Q.push(vertex);
	dist[vertex] = 0;
	while (!Q.empty()) {
		vertex = Q.front();
		printf(" %d", vertex + 1);
		Q.pop();
		for (int i = 0; i < N; i++) {
			if ((graph[vertex][i] == 1) && (dist[i] == -1)) {
				Q.push(i);
				dist[i] = dist[vertex] + 1;
			}
		}
	}
}
int main() {
	srand(time(NULL));
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int min = 10000;
	printf("Ведите размер матрицы  ");
	scanf_s("%d", &N);
	srand(time(NULL));
	graph = new int* [N];
	visited = new int[N];
	dist = new int[N];
	for (int i = 0; i < N; i++) {
		graph[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		dist[i] = -1;
	}
	
	printf("\n");

	for (i = 0; i < N; ++i)
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
		printf("\n Вершина %d смежна с ", i + 1);
		for (j = 0; j < N; j++)
		{
			if (graph[i][j] == 1)
				printf("%d ", j + 1);

		}
	}

	printf("\n\n Введите начальную вершину ");
	scanf("%d", &start);
	printf(" Результат обхода в ширину ");
	BFSD(start - 1, N, graph);
	printf("\n\n Вершины      ");
	for (int i = 1; i <= N; i++) {
		printf(" %d ", i);
	}
	printf("\n Расстояние   ");
	for (int i = 0; i < N; i++) {
		printf(" %d ", dist[i]);
	}
	printf("\n\n");

}
