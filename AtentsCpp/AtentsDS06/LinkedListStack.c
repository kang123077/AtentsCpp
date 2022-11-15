#define _CRT_SECURE_NO_WARNINGS
#include "LinkedListStack.h"

void	LLS_CreateStack(LinkedListStack** Stack)
{
	// 스택을 자유저장소에 생성
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

	// 스택을 자유 저장소에서 해제
	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	// 데이터를 저장한다
	strcpy(NewNode->Data, NewData);

	NewNode->NextNode = NULL;

	// 노드 주소를 반환한다
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
		// 최상의 노드를 찾아 NewNode를 연결한다(쌓는다)
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL)
		{
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
	}

	// 스택의 Top 필드에 새 노드의 주소를 등록한다
	Stack->Top = NewNode;
}

// Top 노드를 Pop해야해서 Top노드의 이전 노드 찾는 로직이 비효율적임
// 더블 링크 리스트가 될 듯
Node* LLS_Pop(LinkedListStack* Stack)
{
	// LLS_Pop() 함수가 반환할 최상위 노드
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		// 새로운 최상위 노드를 스택의 Top 필드에 등록한다
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

// GetSIze함수 노드 갯수가 많으면 갯수를 세는 방식이 비효율적
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