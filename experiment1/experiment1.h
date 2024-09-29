#ifndef EXPERIMENT1_H
#define EXPERIMENT1_H

#include "../DataStructure/List/List.c"

Status addListElem(const LinkedList toAdd);
Status mergeAB(const LinkedList A, const LinkedList B, const LinkedList ALLSet);
Status bingAB(const LinkedList A, const LinkedList B, const LinkedList ALLSet);
Status chaAB(const LinkedList A, const LinkedList B, const LinkedList ALLSet);
Status buAB(const LinkedList A, const LinkedList B, const LinkedList ALLSet);
Status delSet(const LinkedList toDel);

#endif
