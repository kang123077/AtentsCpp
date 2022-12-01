#include <stdio.h>

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First];

	++Left;

	while (Left < Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right)
			++Left;

		while (DataSet[Right] > Pivot && Left <= Right)
			--Right;

		if (Left < Right)
			break;

		Swap(&DataSet[Left], &DataSet[Right]);
	}

	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

void QuickSort(int Dataset[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(Dataset, Left, Right);

		QuickSort(Dataset, Left, Index - 1);
		QuickSort(Dataset, Index + 1, Right);
	}
}

/*
int main(void)
{
	int Dataset[] = { 5, 1, 6, 4, 8, 3, 7, 9, 2 };
	int Length = sizeof Dataset / sizeof Dataset[0];
	int i = 0;

	QuickSort(Dataset, 0, Length - 1);

	for (i = 0; i < Length; i++)
		printf("%d ", Dataset[i]);

	printf("\n");

	return 0;
}
*/