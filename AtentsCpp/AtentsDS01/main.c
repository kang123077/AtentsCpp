//int main() {
//	// 20, 30
//	// C���� �ڷᱸ���� �����մϴ�.
//	// ������, �Ǽ���, ������
//	// short(2byte) �������� 0, ��������
//	// long(4byte)
//	// int(4byte)
//	// unsigned short(2byte) ��������, 0
//	// unsigned long(4byte)
//	// unsigned int(4byte)
//
//	int a;   // ����
//	a = 20;
//
//	int* pa = &a;   //�������� ������
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
//	// ������ ����Ÿ Ÿ���� ������ ������ �ʿ��� �� ����ϴ� ����� �ֽ��ϴ�.
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
//	int array[101];   // �迭
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
//struct tagStudent {   // ����� ���� ����Ÿ Ÿ��
//	int age;   // ����ü ���
//	char name[30];
//	int grade;
//};
//
//typedef struct tagStudent Student;
//
//int main() {
//	// �л� ������ ���α׷�
//	// ����, �̸�, �г�
//	char buff[100];
//
//	// ������ ����Ÿ�� �ϳ��� �����ִ� ����ֽ��ϴ�.
//	// ����ü..
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
//		printf("%d��° �л� �̸�: %s, ����: %d, �г�: %d\n\n", i, array[i].name, array[i].age, array[i].grade);
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

	// �����߿� ������ ����� ������ ���� ��찡 �ֽ��ϴ�.
	// �����޸𸮰����� �޸𸮰����� �Ҵ� �޽��ϴ�.

	// �����޸� �Ҵ��Ҷ�
	// malloc, calloc, realloc 
	// �ݳ�
	// free

	int count = 0;
	printf("�ʿ��� ���� ������ �Է��ϼ���: ");
	scanf("%d", &count);

	int* pa = (int*)malloc(sizeof(int) * count);   // �����޸� �Ҵ�

	//pa = (int*)calloc(count, sizeof(int)); calloc�� �Ҵ� ���� ������ �ʱ�ȭ �մϴ�.


	for (int i = 0; i < count; i++) {
		pa[i] = i;
	}

	for (int i = 0; i < count; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}

	printf("\n-------------------------------------\n\n");
	count *= 2;

	pa = realloc(pa, sizeof(int) * count);   // �����޸𸮰��� ���Ҵ�

	for (int i = 0; i < count; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}

	free(pa);   // �ݳ�ó��

	return 0;
}