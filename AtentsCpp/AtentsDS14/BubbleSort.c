/*

#include <stdio.h> 
#include "Score.h"
#include <time.h>

void BubbleSort(Score DataSet[], int Length)
{
    int i = 0;
    int j = 0;
    Score temp = { 0, 0.0 };

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

    clock_t starttime, endtime;

    float resulttime = 0.0f;

    starttime = clock();
    BubbleSort(DataSet, Length);
    endtime = clock();

    resulttime = (float)(endtime - starttime) / CLOCKS_PER_SEC;

    for (i = 0; i < Length; i++)
    {
        printf("number: %d, score: %lf\n", DataSet[i].number, DataSet[i].score);
    }

    printf("3만개의 소팅시간: %lf\n", resulttime);

    printf("\n");

    return 0;
}

*/