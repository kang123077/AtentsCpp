#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "Score.h"

Score* BinarySearch(Score ScoreList[], int Size, double Target)
{
    int Left, Right, Mid;

    Left = 0;
    Right = Size - 1;
    int Count = 0;
    while (Left <= Right)
    {
        Mid = (Left + Right) / 2;

        if (Target == ScoreList[Mid].score) {
            printf("Count = %d\n", Count);
            return &(ScoreList[Mid]);
        }
        else if (Target > ScoreList[Mid].score)
            Left = Mid + 1;
        else
            Right = Mid - 1;
        Count++;
    }

    printf("Count = %d\n", Count);

    return NULL;
}

int CompareScore(const void* _elem1, const void* _elem2)
{
    Score* elem1 = (Score*)_elem1;
    Score* elem2 = (Score*)_elem2;

    if (elem1->score > elem2->score)
        return 1;
    else if (elem1->score < elem2->score)
        return -1;
    else
        return 0;
}

// 1, 7, 11, 12, 14, 23, 67, 139, 672, 871
int main(void)
{
    srand(time(NULL));
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;
    Score* found = NULL;

    /*  점수의 오름차순으로 정렬 */
    qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

    /*  671.78 점을 받은 학생 찾기 */
   //double searchValue = 539.13;
    double Array[3] = { 156.88, 877.88, 811.02 };
    double searchValue = 877.88;

    for (int i = 0; i < 100; i++) {
        int randvalue = rand() % 30000;
        found = BinarySearch(DataSet, Length, DataSet[randvalue].score);

        if (found != NULL) {
            printf("found: %d %f \n", found->number, found->score);
        }
    }


    return 0;
}