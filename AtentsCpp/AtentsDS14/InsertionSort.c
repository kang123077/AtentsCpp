#include <stdio.h>
#include <string.h>
#include "Score.h"

void InsertionSort(Score DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	Score value;

	for (i = 1; i < Length; i++)
	{
		if (DataSet[i - 1].score <= DataSet[i].score)
			continue;
		value = DataSet[i];

		for (j = 0; j < i; j++)
		{
			if (DataSet[j].score > value.score)
			{
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

int main(void)
{
	// int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	InsertionSort(DataSet, Length);

	for (i = 0; i < Length; i++)
	{
		printf("number: %d, score:%lf\n", DataSet[i].number, DataSet[i].score);
	}

	printf("\n");

	return 0;
}