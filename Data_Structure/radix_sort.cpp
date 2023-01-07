#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 1000

int getMax(int list[], int n)
{
	int max = list[0];
	for (int i = 1; i < n; i++)
		if (list[i] > max)
			max = list[i];
	return max;
}

void Counting_Sort(int list[], int n, int exp)
{
	int i, count[10] = { 0, };
	int output[SIZE];

	for (i = 0; i < n; i++)
		count[(list[i] / exp) % 10] ++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(list[i] / exp) % 10] - 1] = list[i];
		count[(list[i] / exp) % 10] --;
	}

	for (i = 0; i < n; i++)
		list[i] = output[i];
}

void radix_sort(int list[], int n)
{
	int max = getMax(list, n);
	int exp = 1;

	do {
		for (int count = 0; count < 4; count++) {
			Counting_Sort(list, n, exp);
			exp *= 10;
		}
	} while (max / exp > 0);
}

int main(void)
{
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % ((int)pow(2, 24));

	radix_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}