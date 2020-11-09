#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>

using namespace std;
int i, j, m;
bool* visited = new bool[m];
int** graph;
stack <int> s;
stack <int> DFSstack;


void DFS_2(int vertex) {
	
	DFSstack.push(vertex);
	visited[vertex] = 1;
	while (!DFSstack.empty()) {
		vertex = DFSstack.top();
		printf("%d ", vertex + 1);
		DFSstack.pop();
		for /*(int i = 0; i <= m; i++)*/(int i = m; i >= 0; i--) {
			if (graph[vertex][i] == 1 && visited[i] != 1) {
				visited[i] = 1;
				DFSstack.push(i);
			}
		}
	}

}


void DFS_1(int st) 
{	
	stack <int> ss;
	visited[st] = true;
	printf("%d ", st + 1);
	ss.push(st);
	int v;

	while (!ss.empty()) 
	{
		
		v = ss.top();
		ss.pop();
		for (i = 0; i < m; i++) 
		{
			
			if ((graph[v][i] == 1) && (visited[i]== false ))
			{

				visited[i] = 1;				
				ss.push(i);
				printf("%d ", i + 1);
			}
		}
		
	}
}

void DFS(int st)
{
	int r;
	printf("%d ", st + 1);
	visited[st] = true;
	for (r = 0; r <= m; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r);
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

	for (i = 0; i < m; i++)
	{
		printf("\nВершина %d смежна с ", i + 1);
		for (j = 0; j < m; j++) {
			if (graph[i][j] == 1)
				printf("%d ", j + 1);
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



	printf("\nПорядок обхода(не рекурсия): ");
	DFS_2(start - 1);
	for (i = 0; i < m; i++) {
		visited[i] = false;
		
	}
	printf("\nПорядок обхода(рекурсия):    ");
	DFS(start - 1);

	system("pause");
}

void main(void)
{
	DFS_main();
}

