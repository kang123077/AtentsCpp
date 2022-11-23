#include <stdio.h>
#include <stdlib.h>

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

typedef struct tagDisJointSet
{
	struct tagDisJointSet* Parent;
	void* Data;
} DisJointSet;

void DS_UnionSet(DisJointSet* Set1, DisJointSet* Set2);
DisJointSet* DS_FindSet(DisJointSet* set);
DisJointSet* DS_MakeSet(void* NewData);
void DS_DestroySet(DisJointSet set);

#endif