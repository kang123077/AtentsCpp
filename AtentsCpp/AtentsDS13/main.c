#include <stdio.h>

int main() {
	int array[] = { 6, 3, 4, 7, 9, 8, 1, 2, 5, 10 };
	int length = sizeof(array) / sizeof(int);
	int ischange = 0;

	//for (int i = 0; i < length - 1; i++)
	//{
	//	for (int j = i + 1; j < length; j++)
	//	{
	//		if (array[i] > array[j])
	//		{
	//			int temp = array[j];
	//			array[j] = array[i];
	//			array[i] = temp;
	//		}
	//	}
	//}

	for (int j = 0; j < length - 1; j++) {
		ischange = 0;
		for (int i = 0; i < length - 1 - j; i++) {
			if (array[i] > array[i + 1]) {
				int temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;

				ischange = 1;
			}
		}

		if (!ischange) {
			continue;
		}
	}

	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}