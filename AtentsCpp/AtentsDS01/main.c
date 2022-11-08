//int main() {
//	// 20, 30
//	// C언어로 자료구조를 공부합니다.
//	// 정수형, 실수형, 문자형
//	// short(2byte) 양의정수 0, 음의정수
//	// long(4byte)
//	// int(4byte)
//	// unsigned short(2byte) 양의정수, 0
//	// unsigned long(4byte)
//	// unsigned int(4byte)
//
//	int a;   // 변수
//	a = 20;
//
//	int* pa = &a;   //포인터형 지정자
//	printf("&a = %d\n", &a);
//
//	int** ppa = &pa;
//
//	**ppa;
//	**&pa;
//	*pa;
//	*&a;
//	a;
//
//	printf("&**ppa = %p, &**&pa = %p, &*pa = %p, &*&a = %p, &a = %p\n", &**ppa, &**&pa, &*pa, &*&a, &a);
//	printf("**ppa = %d, **&pa = %d, *pa = %d, *&a = %d, a = %d\n", **ppa, **&pa, *pa, *&a, a);
//
//
//	return 0;
//}

//void Swap(int a, int b) {
//	int temp;
//
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//void PSwap(int* pa, int* pb) {
//	int temp;
//	temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//
//
//int main() {
//	int a = 20;
//	int b = 30;
//
//	Swap(a, b);
//
//	printf("Swap a = %d, b = %d\n", a, b);
//
//	PSwap(&a, &b);
//
//	printf("PSwap a = %d, b = %d\n", a, b);
//
//
//	return 0;
//}

//int main()
//{
//	// 동일한 데이타 타입의 공간이 여러개 필요할 때 사용하는 기능이 있습니다.
//
//	// 0 ~ 100
//	int a0 = 0;
//	int a1 = 1;
//	int a2 = 2;
//	//...
//	int a100 = 100;
//
//	if (a0 % 2 == 0) {
//		printf("a0 = %d\n", a0);
//	}
//
//	int array[101];   // 배열
//
//
//	for (int i = 0; i < 101; i++) {
//		array[i] = i;
//	}
//
//	for (int i = 0; i < 101; i++) {
//		printf("array[%d] = %d\n", i, array[i]);
//	}
//
//
//
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//struct tagStudent {   // 사용자 정의 데이타 타입
//	int age;   // 구조체 멤버
//	char name[30];
//	int grade;
//};
//
//typedef struct tagStudent Student;
//
//int main() {
//	// 학생 관리용 프로그램
//	// 나이, 이름, 학년
//	char buff[100];
//
//	// 연관된 데이타를 하나로 묶어주는 기능있습니다.
//	// 구조체..
//
//	Student array[100];
//
//	for (int i = 0; i < 100; i++) {
//		array[i].age = i;
//
//		sprintf(buff, "monster_%d", i);
//		strcpy(array[i].name, buff);
//
//		array[i].grade = i % 3 + 1;
//	}
//
//	for (int i = 0; i < 100; i++) {
//		printf("%d번째 학생 이름: %s, 나이: %d, 학년: %d\n\n", i, array[i].name, array[i].age, array[i].grade);
//	}
//
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a;
	float b;

	// 실행중에 변수의 사이즈가 결정이 나는 경우가 있습니다.
	// 동적메모리공간에 메모리공간을 할당 받습니다.

	// 동적메모리 할당할때
	// malloc, calloc, realloc 
	// 반납
	// free

	int count = 0;
	printf("필요한 정수 갯수를 입력하세요: ");
	scanf("%d", &count);

	int* pa = (int*)malloc(sizeof(int) * count);   // 동적메모리 할당

	//pa = (int*)calloc(count, sizeof(int)); calloc은 할당 받은 공간을 초기화 합니다.


	for (int i = 0; i < count; i++) {
		pa[i] = i;
	}

	for (int i = 0; i < count; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}

	printf("\n-------------------------------------\n\n");
	count *= 2;

	pa = realloc(pa, sizeof(int) * count);   // 동적메모리공간 재할당

	for (int i = 0; i < count; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}

	free(pa);   // 반납처리

	return 0;
}