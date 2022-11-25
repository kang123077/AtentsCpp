/*

#include <stdio.h>
#include "Score.h"

// Score.h 파일 안에는 3만개의 데이터가 저장 된 배열이 있음
// DataSet은 스코어 구조체 데이터 타입의 배열
// Score 구조체 데이터 타입은 안에 number 멤버와 score 멤버를 가지고 있음
// DataSet 배열을 score값을 기준으로 오름 차순으로 sort해보세요...

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