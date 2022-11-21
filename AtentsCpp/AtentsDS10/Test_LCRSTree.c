#include "LCRSTree.h"

int main(void)
{
	// ��� ����
	LCRSNode* root = LCRS_CreateNode('A');

	LCRSNode* B = LCRS_CreateNode('B');
	LCRSNode* C = LCRS_CreateNode('C');
	LCRSNode* D = LCRS_CreateNode('D');
	LCRSNode* E = LCRS_CreateNode('E');
	LCRSNode* F = LCRS_CreateNode('F');
	LCRSNode* G = LCRS_CreateNode('G');
	LCRSNode* H = LCRS_CreateNode('H');
	LCRSNode* I = LCRS_CreateNode('I');
	LCRSNode* J = LCRS_CreateNode('J');
	LCRSNode* K = LCRS_CreateNode('K');

	// Ʈ���� ��� �߰�
	LCRS_AddChildNode(root, B);

	LCRS_AddChildNode(B, C);
	LCRS_AddChildNode(B, D);

	LCRS_AddChildNode(D, E);
	LCRS_AddChildNode(D, F);

	LCRS_AddChildNode(root, G);
	LCRS_AddChildNode(G, H);

	LCRS_AddChildNode(root, I);
	LCRS_AddChildNode(I, J);
	LCRS_AddChildNode(J, K);

	// Ʈ�� ���
	LCRS_PrintTree(root, 0);

	// ���� ���
	printf("Level : 1\n");
	LCRS_PrintNodesAtLevel(root, 1);
	printf("Level : 2\n");
	LCRS_PrintNodesAtLevel(root, 2);
	printf("Level : 3\n");
	LCRS_PrintNodesAtLevel(root, 3);
	printf("Level : 1\n");
	LCRS_PrintNodesAtLevel(root, 4);

	// Ʈ�� �Ҹ�
	LCRS_DestroyTree(root);

	return 0;
}