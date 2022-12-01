#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Score.h"

// 리턴값이
// < 0 이면, _elem1이 _elem2보다 작다.
// 0 이면, _elem1이 _elem2와 같다.
// > 0 이면, _elem1이 _elem2보다 크다.

int CompareScore(const void* _elem1, const void* _elem2)
{
	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2)
		return 1;
	else if (*elem1 < *elem2)
		return -1;
	else
		return 0;
}

int main(void)
{
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	qsort((void*)DataSet, Length, sizeof(int), CompareScore);

	for (i = 0; i < Length; i++)
	{
		printf("number: %d, score:%lf\n", DataSet[i].number, DataSet[i].score);
	}

	printf("\n");

	return 0;
}