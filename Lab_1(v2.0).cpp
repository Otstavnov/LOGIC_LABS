#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ctime"
#include <locale>
#include <Windows.h>



int main(void)
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int a[10], a_max, a_min, a_a;

	printf(" Задание №1\n\n ");
	for (int i = 0; i <= 9; i++) { a[i] = rand() % 100 - 20; printf("%3d ", a[i]); }

	a_max = a[0];
	printf("\n");
	for (int i = 0; i <= 9; i++) { if (a[i] >= a_max) a_max = a[i]; }
	printf("\n Максимальный элемент массива: %d", a_max);

	a_min = a[0];
	for (int i = 0; i <= 9; i++) { if (a[i] <= a_min)a_min = a[i]; }
	printf("\n Минимальный элемент массива: %d", a_min);
	a_a = a_max - a_min;
	printf("\n Разница между max и min элементами: %d\n", a_a);


	printf("\n Задание №2\n ");
	printf("Массив случаных чисел\n\n");

	int b[10];
	for (int i = 0; i <= 9; i++) { b[i] = rand() % 100 - 20; printf("%3d ", b[i]); }

	printf("\n\n Задание №3\n ");

	int g;
	do
	{
		printf("Введите размер массива: ");
		scanf("%d", &g);
	} while (g < 1);
	int* array = new int[g];
	for (int i = 0; i < g; i++) {
		array[i] = rand() % 200 - 100;
		printf(" array[%d] = %d \n", i, array[i]);
	}
	delete[] array;

	printf("\n\n Задание №4\n ");

	int i, j;
	int arrr[5][5];
	int sum = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {

			arrr[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < 5; i++) {
		sum = 0;
		for (j = 0; j < 5; j++) {

			printf("%d ", arrr[i][j]);
			sum = sum + arrr[i][j];

		}
		printf(" сумма элементов строки равна %d", sum);
		printf("\n ");
	}

	printf("\n\n Задание №5\n ");

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int e;
	struct student
	{
		char famil[30];
		char name[30], facult[30];
		char Nomzach[5];
	} stud[3];

	for (e = 0; e < 3; e++)
	{
		printf("Введите фамилию студента\n "); scanf("%20s", stud[e].famil);
	}
	for (e = 0; e < 3; e++)
	{
		printf("Введите имя студента %s\n ", stud[e].famil); scanf("%20s", stud[e].name);
	}
	for (e = 0; e < 3; e++)
	{
		printf("Введите название факультета студента %s %s\n ", stud[e].famil, stud[e].name); scanf("%20s", stud[e].facult);
	}
	for (e = 0; e < 3; e++)
	{
		printf("Введите номер зачётной книжки студента %s %s\n ", stud[e].famil, stud[e].name); scanf("%s", &stud[e].Nomzach);
	}
	for (e = 0; e < 3; e++) {
		for (e = 0; e < 3; e++) {
			printf(" Cтудент %s %s обучается на факультете %s, номер зачётной книжки %s \n", stud[e].famil, stud[e].name,
				stud[e].facult, stud[e].Nomzach);
		}
		char poisk[20];
		printf("Введите факультет: ");
		scanf("%s", &poisk);
		for (i = 0; i < 3; i++)
		{

			if ((strcmp(stud[i].famil, poisk) == 0) || (strcmp(stud[i].Nomzach,  poisk) == 0) || (strcmp(stud[i].name, poisk) == 0) || (strcmp(stud[i].facult, poisk) == 0)) {
				printf("\nCтудент %s %s обучается на факультете %s, номер зачётной книжки %s\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
			}
		}



		printf("\n");
		system("pause");
	}
}