#include "BinaryTree.h"

int main(void)
{
	// ��� ����
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');

	// Ʈ���� ��� �߰�
	A->Left = B;
	B->Left = C;
	C->Left = D;

	A->Right = E;
	E->Left = F;
	F->Right = G;

	// Ʈ�� ���
	printf("Preorder ...\n");
	SBT_PreorderPrintTree(A);
	printf("\n");

	printf("Inorder ...\n");
	SBT_InorderPrintTree(A);
	printf("\n");

	printf("Postorder ...\n");
	SBT_PostorderPrintTree(A);
	printf("\n");

	// Ʈ�� �Ҹ�
	SBT_DestroyTree(A);

	return 0;
}