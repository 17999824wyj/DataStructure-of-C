#ifndef STACK_C
#define STACK_C

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

Status initStack(Stack *newStack) {
	*newStack = (Stack) malloc (sizeof(struct SqStack));
	(*newStack)->data = (ElemType *) malloc (sizeof(ElemType) * MAXLENGTH);
	if (!(*newStack)->data)
		exit(OVERFLOW);
	(*newStack)->size = MAXLENGTH;
	(*newStack)->length = 0;
	return OK;
}

Status destroyStack(Stack *toDestroy) {
	if (toDestroy == NULL)
		return ERROR;
	if ((*toDestroy)->data != NULL)
		free((*toDestroy)->data);
	(*toDestroy)->data = NULL;
	(*toDestroy)->length = 0;
	(*toDestroy)->size = 0;
	free(*toDestroy);
	*toDestroy = NULL;
	return OK;
}

Status clearStack(const Stack toClear) {
	if (toClear == NULL || toClear->data == NULL)
		return ERROR;
	toClear->length = 0;
	return OK;
}

Boolean isEmptyStack(const Stack toJudge) {
	if (toJudge == NULL)
		return ERROR;
	return toJudge->length == 0;
}

Status printStack(const Stack toPrint) {
	if (toPrint->data == NULL)
		return ERROR;
	int i;
	for (i = 1; i <= toPrint->length; i++) {
		printf("%d\t", toPrint->data[i-1]);
		if (i % 10 == 1 && i != 1)
			puts("");
	}
	return OK;
}

Status getStackLength(const Stack toGet, int *carrier) {
	if (toGet == NULL)
		return ERROR;
	*carrier = toGet->length;
	return OK;
}

Status getSize(const Stack toGet, int *carrier) {
	if (toGet == NULL)
		return ERROR;
	*carrier = toGet->size;
	return OK;
}

Status changeSize(const Stack toChange, const int newSize) {
	if (!toChange)
		return ERROR;
	ElemType *tempStore = (ElemType *)malloc(sizeof(ElemType) * toChange->length);
	int t;
	if (tempStore) for (t = 1; t <= toChange->length; t++) tempStore[t-1] = toChange->data[t-1];
	if (clearStack(toChange)) {
		toChange->size = newSize;
		free(toChange->data);
		toChange->data = (ElemType *) malloc (sizeof(ElemType) * newSize);
		if (!toChange->data)
			exit(OVERFLOW);
		if (tempStore) {
			int i;
			for (i = 1; i < (t <= newSize + 1 ? t : newSize + 1); i++) {
				toChange->data[i-1] = tempStore[i-1];
				toChange->length ++;
			}
			free(tempStore);
		}
		return OK;
	} else return ERROR;
}

Status push(const Stack toAdd, const ElemType dataNum) {
	if (toAdd == NULL || toAdd->data == NULL)
		return ERROR;
	if (toAdd->length == toAdd->size)
		exit(OVERFLOW);
	toAdd->data[(toAdd->length)++] = dataNum;
	return OK;
}

Status pop(const Stack toPop, int *carrier) {
	if (toPop == NULL || toPop->data == NULL)
		return ERROR;
	*carrier = toPop->data[--(toPop->length)];
	return OK;
}

Status getTop(const Stack toGet, int *carrier) {
	if (toGet == NULL || toGet->data == NULL)
		return ERROR;
	*carrier = toGet->data[toGet->length-1];
	return OK;
}

Boolean search(const Stack toSearch, const ElemType toFind, int *carrier) {
	*carrier = -1;
	Boolean flag = FALSE;
	if (toSearch == NULL || toSearch->data == NULL)
		return ERROR;
	int i;
	for (i = 1; i <= toSearch->length; ++i) {
		if (toSearch->data[i-1] == toFind) {
			flag = TRUE;
			*carrier = i;
			break;
		}
	}
	return flag;
}

#endif
