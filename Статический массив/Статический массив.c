#include <stdio.h>
#include <math.h>
#define MAX 100

int arr[MAX];

//Вычисление максимума/минимума
void minax(int len) {
	//Указаетель на глобальный массив
	int* parr = arr;
	int maxt = *parr, mint = *parr;

	//Работа с массивом
	for (int i = 1; i < len; i++) {
		if (*(parr + i) > maxt) {
			maxt = *(parr + i);
		}
		else if (*(parr + i) < mint) {
			mint = *(parr + i);
		}
	}
	printf("Maximum - %d\nMinimum - %d\n", mint, maxt);
}

//Вычисление среднего и отклонения
void meams(int len) {
	float sigma = 0, mean = 0;
	//sigma - квадрат отклонения

	//Расчёт среднего
	for (int i = 0; i < len; i++) {
		mean = mean + ((float)arr[i] / len);
	}
	//Расчёт квадрата отклонения
	for (int i = 0; i < len; i++) {
		sigma = sigma + ((mean - arr[i])*(mean - arr[i]) / len);
	}
	printf("Mean - %f\nRMS - %f\n", mean, sqrt(sigma));
}

int main() {
	char ch;
	do {
		printf("Array's maximal length - %d", MAX);

		//Длина массива
		int len;
		printf("\nInput length: ");
		scanf_s("%d", &len);

		//Инициализация массива
		printf("Input array: ");
		for (int i = 0; i < len; i++) {
			scanf_s("%d", &arr[i]);
		}

		minax(len);
		meams(len);

		//Повтор программы
		printf("\nDo you wish to restart program? (y/n)\n");
		getchar();
		scanf_s("%c", &ch);
	} while (ch == 'y' || ch == 'Y');
	return 0;
}