/*

#include <stdio.h>
#include "Score.h"

// Score.h ���� �ȿ��� 3������ �����Ͱ� ���� �� �迭�� ����
// DataSet�� ���ھ� ����ü ������ Ÿ���� �迭
// Score ����ü ������ Ÿ���� �ȿ� number ����� score ����� ������ ����
// DataSet �迭�� score���� �������� ���� �������� sort�غ�����...

void BubbleSort(Score DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	Score temp;

	for (i = 0; i < Length - 1; i++)
	{
		for (j = 0; j < Length - (i + 1); j++)
		{
			if (DataSet[j].score > DataSet[j + 1].score)
			{
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}
int main(void)
{
	//int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	BubbleSort(DataSet, Length);

	for (i = 0; i < Length; i++)
	{
		printf("number: %d, score:%lf\n", DataSet[i].number, DataSet[i].score);
	}

	printf("\n");

	return 0;
}

*/