#ifndef LIST_C
#define LIST_C

#include "List.h"
#include <stdio.h>
#include <stdlib.h>

Status initLinkedList(LinkedList *newLinkedList) {
	*newLinkedList = (ListNode *) malloc (sizeof(ListNode));
	(*newLinkedList)->next = NULL;
	return OK;
}

Status destroyLinkedList(LinkedList *toDestroy) {
	if (*toDestroy == NULL)
		return ERROR;
	clearLinkedList((*toDestroy)->next);
	free(*toDestroy);
	*toDestroy = NULL;
	return OK;
}

Status clearLinkedList(ListNode *firstData) {
	if (firstData == NULL)
		return OK;
	clearLinkedList(firstData->next);
	free(firstData);
	firstData = NULL;
	return OK;
}

Boolean isEmptyList(const LinkedList toJudge) {
	if (toJudge == NULL)
		return ERROR;
	if (toJudge->next == NULL)
		return TRUE;
	return FALSE;
}

Status printLinkedList(const LinkedList toPrint) {
	if (toPrint == NULL)
		return ERROR;
	ListNode *temp = toPrint->next;
	while(temp != NULL) {
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	free(temp);
	return OK;
}

Status getListLength(LinkedList toGetLength, int *carrier) {
	LinkedList p = toGetLength;
	if (p == NULL) return ERROR;
	*carrier = -1;
	while (p != NULL) {
		*carrier += 1;
		p = p->next;
	}
	return OK;
}

Status createListNode(LinkedList *carrier, const ElemType dataNum) {
	*carrier = (ListNode *) malloc (sizeof(ListNode));
	(*carrier)->data = dataNum;
	(*carrier)->next = NULL;
	return OK;
}

Status addListNode(const LinkedList toAdd, const ElemType dataNum, const int location) {
	if (location < 1)
		return ERROR;
	int i;
	ListNode* present = toAdd;
	for (i = 1; i < location; i++) {
		if (present == NULL)
			return ERROR;
		present = present->next;
	}
	ListNode* temp = present->next;
	ListNode* newNode;
	if (!createListNode(&newNode, dataNum))
		return ERROR;
	present->next = newNode;
	newNode->next = temp;
	return OK;
}

Status delListNode(const LinkedList toDelete, const int indexOrNum, const int mode) {
	if (toDelete == NULL || toDelete->next == NULL)
		return ERROR;
	ListNode* present = toDelete;
	switch (mode) {
		case 0: {
			if (indexOrNum < 1)
				return ERROR;
			int i;
			for (i = 1; i < indexOrNum; i++) {
				if (present == NULL)
					return ERROR;
				present = present->next;
			}
			if (present == NULL || present->next == NULL)
				return ERROR;
			ListNode* temp = present->next;
			present->next = temp->next;
			free(temp);
			break;
		}
		case 1: {
			int i = 1;
			Boolean flag = FALSE;
			present = present->next;
			while (present != NULL) {
				if (present->data == indexOrNum) {
					flag = TRUE;
					return delListNode(toDelete, i, 0);
				}
				present = present->next;
				++i;
			}
			if (!flag)
				return ERROR;
			else
				return OK;
		}
		default:
			return ERROR;
	}
	return OK;
}

Status setToLinkedList(const LinkedList toChange, const int transTo, const int index) {
	if (toChange == NULL || toChange->next == NULL || index < 1)
		return ERROR;
	ListNode* present = toChange;
	int i;
	for (i = 0; i < index; i++) {
		if (present == NULL)
			return ERROR;
		present = present->next;
	}
	if (present == NULL)
		return ERROR;
	present->data = transTo;
	return OK;
}

Boolean findNum(const LinkedList toSearch, const ElemType toFind, int *carrier) {
	*carrier = -1;
	if (toSearch == NULL || toSearch->next == NULL)
		return FALSE;
	ListNode* present = toSearch->next;
	int i = 0, length;
	getListLength(toSearch,&length);
	Boolean flag = FALSE;
	while (present != NULL) {
		if (i >= length) return FALSE;
		if (present->data == toFind) {
			flag = TRUE;
			*carrier = i;
			break;
		}
		present = present->next;
		++i;
	}
	return flag;
}

Boolean findWhat(const LinkedList toSearch, const int index, ElemType *carrier) {
	if (toSearch == NULL || toSearch->next == NULL || index < 1)
		return FALSE;
	ListNode* present = toSearch;
	int i;
	for (i = 0; i < index; i++) {
		if (present == NULL)
			return FALSE;
		present = present->next;
	}
	if (present == NULL)
		return FALSE;
	*carrier = present->data;
	return TRUE;
}

Status copyLinkedList(const LinkedList toCopy, const LinkedList toPaste) {
	ListNode* temp = toCopy->next;
	if(!clearLinkedList(toPaste->next)) return ERROR;
	int length = 0;
	while (temp != NULL) {
		if(!addListNode(toPaste,temp->data,++length)) return ERROR;
		temp = temp->next;
	}
	return OK;
}

#endif
