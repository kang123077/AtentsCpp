#define _CRT_SECURE_NO_WARNINGS
#include "LinkedListStack.h"

void	LLS_CreateStack(LinkedListStack** Stack)
{
	// ������ ��������ҿ� ����
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void	LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyStack(Popped);
	}

	// ������ ���� ����ҿ��� ����
	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	// �����͸� �����Ѵ�
	strcpy(NewNode->Data, NewData);

	NewNode->NextNode = NULL;

	// ��� �ּҸ� ��ȯ�Ѵ�
	return NewNode;
}

void	LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void	LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		// �ֻ��� ��带 ã�� NewNode�� �����Ѵ�(�״´�)
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL)
		{
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
	}

	// ������ Top �ʵ忡 �� ����� �ּҸ� ����Ѵ�
	Stack->Top = NewNode;
}

// Top ��带 Pop�ؾ��ؼ� Top����� ���� ��� ã�� ������ ��ȿ������
// ���� ��ũ ����Ʈ�� �� ��
Node* LLS_Pop(LinkedListStack* Stack)
{
	// LLS_Pop() �Լ��� ��ȯ�� �ֻ��� ���
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		// ���ο� �ֻ��� ��带 ������ Top �ʵ忡 ����Ѵ�
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL;
	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

// GetSIze�Լ� ��� ������ ������ ������ ���� ����� ��ȿ����
int	LLS_GetSize(LinkedListStack* Stack)
{
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}