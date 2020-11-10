#include <stdio.h>
#include <random>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

using namespace std;

void cpy(int** mass1, int** mass2, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mass1[i][j] = mass2[i][j];
		}
	}
}

void generate(int** mass, int n) { // заполнение массивов
	int i, r, c;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			r = rand() % 2;
			c = rand() % 2;
			if (r == 1) {
				mass[i][j] = 1;
			}
			else
				mass[i][j] = 0;
			if (i == j) {
				mass[i][j] = 0;
			}

		}
	}
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mass[i][j] != mass[j][i]) {
				mass[i][j] = mass[j][i];
			}
		}
	}

}

void otoz(int s, int s1, int** mass, int n) { //отождествление
	int i, j;
	printf("Результат отождествления вершин 1й матрицы:\n");

	for (i = 0; i < n; i++) { //заносим 1ю матрицу
		for (j = 0; j < n; j++) {
			if (mass[s][j] > mass[s1][j])
				mass[s1][j] = 1;
			if (mass[i][s1] > mass[s1][j])
				mass[i][s1] = 1;
		}
	}

	int l = 0, g = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mass[s][j] == 1)
				g = 1;
			if (mass[i][s] == 1)
				l = 1;
			mass[s][j] = 0;
			if (g == 1)
				mass[s1][j] = g;
			mass[i][s] = 0;
			if (l == 1)
				mass[i][s1] = l;
			g = 0;
			l = 0;
			mass[s1][s1] = 1;
		}
	}

	//выполняем отождествление и вывод матрицы
	int** printmass = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == s || j == s) {
				continue;
			}
			printf("%3d ", mass[i][j]);
		}
		if (i != s) {
			printf("\n");
		}

	}

}

void styag(int s, int s1, int** mass1, int n) { //стягивание
	int g = 0, l = 0;
	printf("Результат стягивания ребра 1й матрицы:\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mass1[s][j] == 1)
				g = 1;
			if (mass1[i][s] == 1)
				l = 1;
			mass1[s][j] = 0;
			if (g == 1)
				mass1[s1][j] = g;
			mass1[i][s] = 0;
			if (l == 1)
				mass1[i][s1] = l;
			g = 0;
			l = 0;
			mass1[s1][s1] = 0;
		}
	}
	for (int i = 0; i < n; i++) { //выполняем стягивание и вывод матрицы
		for (int j = 0; j < n; j++)
		{
			if (i == s || j == s) {
				continue;
			}
			printf("%3d ", mass1[i][j]);
		}
			if (i != s)
			{
			printf("\n");
			}
	}
}

void ras(int s, int s1, int** mass2, int n, int** mass3) { //расщепление
	printf("\nРезультат расщепления вершины 1й матрицы:\n");

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			mass2[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mass2[i][j] = mass3[i][j];
		}
	}

	for (int i = 0; i < n + 1; i++) { //расщепление вершины 1й матрицы
		for (int j = 0; j < n + 1; j++) {
			if (j < n / 2 && mass2[s][j] == 1) {
				mass2[n][j] = 1;
				mass2[s][j] = 0;
			}
			if (i < n / 2 && mass2[i][s] == 1) {
				mass2[i][n] = 1;
				mass2[i][s] = 0;
			}
			printf("%3d ", mass2[i][j]); //вывод результата
		}
		printf("\n");
	}
}


void obe(int** mass_p1, int** mass_p2, int n, int n1) { //объединение
	int i, j;

	printf("Матрица 1\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

			printf("%3d ", mass_p1[i][j]); //вывод матрицы
		}
		printf("\n");
	}

	printf("\nМатрица 2\n");
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n1; j++) {

			printf("%3d ", mass_p2[i][j]); //вывод матрицы
		}
		printf("\n");
	}

	//выполнение операции
	if (n > n1) {
		for (i = 0; i < n1; i++) {
			for (j = 0; j < n1; j++) {
				if (mass_p1[i][j] != 1 && mass_p2[i][j] == 1) {
					mass_p1[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%3d ", mass_p1[i][j]);
			}
		}
	}

	if (n1 > n) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (mass_p1[i][j] == 1 && mass_p2[i][j] != 1) {
					mass_p2[i][j] = 1;
				}
			}
		}

		printf("\nРезультат объединения матриц:\n");
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1; j++) {
				printf("%3d ", mass_p2[i][j]);
			}
			printf("\n");
		}
	}
}


void pere(int** mass_o1, int** mass_o2, int n, int n1) { //пересечение
	int i, j;
	printf("Матрица 1\n");
	for (i = 0; i < n; i++) { //вывод матрицы1
		for (j = 0; j < n; j++) {

			printf("%3d ", mass_o1[i][j]);
		}
		printf("\n");
	}

	printf("\nМатрица 2\n");
	for (i = 0; i < n1; i++) { //вывод матрицы2
		for (j = 0; j < n1; j++) {

			printf("%3d ", mass_o2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	if (n > n1) { //выполнение операции
		for (i = 0; i < n1; i++) {
			for (j = 0; j < n1; j++) {
				if (mass_o2[i][j] == 1 && mass_o1[i][j] == 1)
					mass_o1[i][j] = 1;
				else mass_o1[i][j] = 0;
			}
		}
		for (i = 0; i < n1; i++) {
			for (j = 0; j < n1; j++) {
				printf("%3d ", mass_o1[i][j]);
			}
			printf("\n");
		}
	}
	if (n1 > n) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (mass_o2[i][j] == 1 && mass_o1[i][j] == 1)
					mass_o2[i][j] = 1;
				else mass_o2[i][j] = 0;
				if (n > n1) {
					mass_o2[i][j] = 0;
				}
			}
		}

		printf("Результат пересечения матриц:\n");
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%3d ", mass_o2[i][j]);
			}
			printf("\n");
		}
	}
	printf("\n");
}

void kolz(int** mass_k1, int** mass_k2, int n, int n1) { //кольцевая сумма
	int i, j;
	printf("\nМатрица 1\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

			printf("%3d ", mass_k1[i][j]);
		}
		printf("\n");
	}

	printf("\nМатрица 2\n");
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n1; j++) {

			printf("%3d ", mass_k2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	if (n > n1) { //выполнение операции
		for (i = 0; i < n1; i++) {
			for (j = 0; j < n1; j++) {
				if (mass_k1[i][j] != 1 && mass_k2[i][j] == 1 || mass_k2[i][j] != 1 && mass_k1[i][j] == 1) {
					mass_k1[i][j] = 1;
				}
				else mass_k1[i][j] = 0;
			}
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%3d ", mass_k1[i][j]);
			}
			printf("\n");
		}
	}
	if (n1 > n) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (mass_k1[i][j] != 1 && mass_k2[i][j] == 1 || mass_k2[i][j] != 1 && mass_k1[i][j] == 1) {
					mass_k2[i][j] = 1;
				}
				else mass_k2[i][j] = 0;
			}
		}

		printf("Результат кольцевой суммы матриц:\n");
		for (i = 0; i < n1; i++) {
			for (j = 0; j < n1; j++) {
				printf("%3d ", mass_k2[i][j]);
			}
			printf("\n");
		}
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int s, s1, n, n1;

	printf("ЗАДАНИЕ 1\n");

	printf("Введите размеры массивов через пробел:");
	scanf_s("%3d %3d", &n, &n1);
	int** mass = (int**)malloc(sizeof(int) * n);
	int** mass1 = (int**)malloc(sizeof(int) * n);
	int** mass_p1 = (int**)malloc(sizeof(int) * n);
	int** mass_o1 = (int**)malloc(sizeof(int) * n);
	int** mass_k1 = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		mass[i] = (int*)malloc(sizeof(int) * n);
		mass1[i] = (int*)malloc(sizeof(int) * n);
		mass_p1[i] = (int*)malloc(sizeof(int) * n);
		mass_o1[i] = (int*)malloc(sizeof(int) * n);
		mass_k1[i] = (int*)malloc(sizeof(int) * n);
	}
	int** massre = (int**)malloc(sizeof(int) * n1);
	int** mass_p2 = (int**)malloc(sizeof(int) * n1);
	int** mass_o2 = (int**)malloc(sizeof(int) * n1);
	int** mass_k2 = (int**)malloc(sizeof(int) * n1);
	for (int i = 0; i < n1; i++) {
		massre[i] = (int*)malloc(sizeof(int) * n1);
		mass_p2[i] = (int*)malloc(sizeof(int) * n1);
		mass_o2[i] = (int*)malloc(sizeof(int) * n1);
		mass_k2[i] = (int*)malloc(sizeof(int) * n);
	}
	int** mass2 = (int**)malloc(sizeof(int) * n + 1);
	for (int i = 0; i < n + 1; i++) {
		mass2[i] = (int*)malloc(sizeof(int) * n + 1);
	}
	int** mass3 = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		mass3[i] = (int*)malloc(sizeof(int) * n);
	}

	int i = 0;
	int j = 0, k = 0, m = 0;
	int a;

	printf("\nМатрица 1:\n");
	generate(mass, n);
	generate(mass_p2, n1);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			mass1[i][j] = mass[i][j];
			mass_o1[i][j] = mass1[i][j];
			mass_p1[i][j] = mass1[i][j];
			mass_k1[i][j] = mass1[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d ", mass[i][j]);
		}
		printf("\n");
	}

	printf("\nМатрица 2:\n");
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n1; j++) {
			printf("%3d ", mass_p2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("\nЗАДАНИЕ 2\n");

	printf("1.Отождествление вершин\n");
	printf("Введите номера вершин:");
	scanf_s("%3d %3d", &s, &s1);
	printf("\n");
	cpy(mass3, mass, n);
	otoz(s, s1, mass3, n);
	printf("\n");
	printf("\n2.Стягивание ребер\n");
	printf("\n");
	cpy(mass3, mass, n);
	styag(s, s1, mass3, n);
	printf("\n");
	printf("\n3.Расщепление вершин\n");
	cpy(mass3, mass, n);
	ras(s, s1, mass2, n, mass3);
	printf("\n");

	printf("\nЗАДАНИЕ 3\n");

	printf("1.Объединение матриц\n");
	cpy(mass_k2, mass_p2, n1);
	printf("\n");
	obe(mass_p1, mass_p2, n, n1);
	printf("\n");
	printf("\n2.Пересечение матриц\n");
	cpy(mass_o2, mass_p2, n1);
	printf("\n");
	pere(mass_o1, mass_o2, n, n1);
	printf("\n3.Кольцевая сумма матриц\n");
	kolz(mass_k1, mass_k2, n, n1);
}
