#include <stdio.h>
#include <math.h>
#define MAX 100

int arr[MAX];

//Вычисление максимума
int max(int len) {
	//Указаетель на глобальный массив
	int* parr = arr;
	int maxt = *parr;

	//Работа с массивом
	for (int i = 1; i < len; i++) {
		if (*(parr + i) > maxt) {
			maxt = *(parr + i);
		}
	}
	return maxt;
}

//Вычисление минимума
int min(int len) {
	//Указаетель на глобальный массив
	int* parr = arr;
	int mint = *parr;

	//Работа с массивом
	for (int i = 1; i < len; i++) {
		if (*(parr + i) < mint) {
			mint = *(parr + i);
		}
	}
	return mint;
}

//Вычисление среднего
float mean(int len) {
	float mean = 0;

	//Расчёт среднего
	for (int i = 0; i < len; i++) {
		mean = mean + ((float)arr[i] / len);
	}
	return mean;
}

//Вычисление отклонения
float RMS(int len) {
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
	return sqrt(sigma);
}

int main() {
	char ch;
	do {
		printf("Array's maximal length - %d", MAX);

		//Длина массива
		int len;
		int mint, maxt;
		float meant, RMSt;
		printf("\nInput length: ");
		scanf_s("%d", &len);

		//Инициализация массива
		printf("Input array: ");
		for (int i = 0; i < len; i++) {
			scanf_s("%d", &arr[i]);
		}

		maxt = max(len);

		mint = min(len);

		meant = mean(len);

		RMSt = RMS(len);

		printf("Maximum - %d\nMinimum - %d\nMean - %f\nRMS - %f\n", maxt, mint, meant, RMSt);

		//Повтор программы
		printf("\nDo you wish to restart program? (y/n)\n");
		getchar();
		scanf_s("%c", &ch);
	} while (ch == 'y' || ch == 'Y');
	return 0;
}