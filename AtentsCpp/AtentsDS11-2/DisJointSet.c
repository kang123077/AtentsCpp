#include "DisJointSet.h"

void DS_UnionSet(DisJointSet* set1, DisJointSet* set2)
{
	set2 = DS_FindSet(set2);
	set2->Parent = set1;
}

DisJointSet* DS_FindSet(DisJointSet* set)
{
	while (set->Parent != NULL)
	{
		set = set->Parent;
	}

	return set;
}

DisJointSet* DS_MakeSet(void* NewData)
{
	DisJointSet* NewNode = (DisJointSet*)malloc(sizeof(DisJointSet));
	NewNode->Data = NewData;
	NewNode->Parent = NULL;
}

void DS_DestroySet(DisJointSet* set)
{
	free(set);
}