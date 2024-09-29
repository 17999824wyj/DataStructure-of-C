#ifndef TREE_C
#define TREE_C

#include "Tree.h"
#include "../../config/utils.c"
#include "../../experiment3/department.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Status initTree(Tree *newTree) {
	*newTree = (Tree) malloc (sizeof(Node));
	(*newTree)->d = NULL;
	(*newTree)->child = NULL;
	(*newTree)->brother = NULL;
	return OK;
}

Status destroyTree(Tree *root) {
	if ((*root) == NULL)
		return ERROR;
	clearTree(*root);
	*root = NULL;
	return OK;
}

Status clearTree(Node* toClear) {
	if(toClear == NULL) return OK;
	Department* de = toClear->d;
	if (de->name) {
		free(de->name);
		de->name = NULL;
	}
	free(toClear->d);
	toClear->d = NULL;
	if(toClear->child) {
		clearTree(toClear->child);
		toClear->child = NULL;
	}
	if(toClear->brother) {
		clearTree(toClear->brother);
		toClear->brother = NULL;
	}
	free(toClear->d);
	toClear->d = NULL;
	de = NULL;
	return OK;
}

Boolean isEmptyTree(const Tree toJudge) {
	if(toJudge == NULL) {
		puts("NULL Tree Node!");
		return ERROR;
	}
	if(toJudge->child == NULL && toJudge->brother == NULL)
		return TRUE;
	return FALSE;
}

Status printTree(const int blanket, const Tree toPrint) {
	if(toPrint == NULL || (toPrint->d) == NULL) return OK;
	Department* de = toPrint->d;
	if(de != NULL) {
		printStars(blanket * 2);
		printf(" ");
		showDepartment(de);
		puts("");
	}
	printTree(blanket, toPrint->brother);
	printTree(blanket+1, toPrint->child);
	return OK;
}

#endif
