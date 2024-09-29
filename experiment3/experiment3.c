#ifndef EXPERIMENT_C
#define EXPERIMENT_C

#include "../config/utils.c"
#include "department.c"
#include "experiment3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Status addNode(Tree toAdd, Department* carrier) {
	if (toAdd == NULL) return ERROR;
	Tree t = toAdd->child;
	if (t == NULL) {
		initTree(&t);
		t->d = carrier;
		toAdd->child = t;
	} else {
		while (t->brother) {
			t = t->brother;
		}
		initTree(&(t->brother));
		t->brother->d = carrier;
	}
	return OK;
}

Boolean searchTree(const Tree root, const char* toSearch, Tree* carrier) {
	if(root == NULL) return FALSE;
	if(strcmp(root->d->name,toSearch) == 0) {
		*carrier = root;
		return TRUE;
	}
	if (searchTree(root->child, toSearch, carrier)) return TRUE;
	return searchTree(root->brother, toSearch, carrier);
}

Status createArchitecture(Tree root) {
	FILE* fptr = fopen("./datas/definitions.txt", "r");
	char parent[30];
	int account;
	char name[30];

	while (fscanf(fptr, "%29s %d %29s", parent, &account, name) == 3) {
		printString(parent);
		printf(" %d ", account);
		printString(name);
		puts("");

		Department* deP = NULL;
		initDepartment(&deP);
		setDepartment(&deP, name, account);

		showDepartment(deP);
		printf(" Parent is: ");
		printString(parent);
		puts("");

		Tree carrier = NULL;
		if (!searchTree(root, parent, &carrier)) {
			free(deP);
			fclose(fptr);
			return ERROR;
		}

		if (!carrier) return ERROR;
		if (!addNode(carrier, deP)) {
			free(deP);
			fclose(fptr);
			return ERROR;
		}

		showDepartment(carrier->d);
		puts(" **Debug: department");

		printStars(20);
		puts("");
		printTree(0, root);
		puts("");
	}
	fclose(fptr);
	return OK;
}

Status parseQuestion(char* question, Tree root) {
	int type = countWords(question);
	if (type == 0) return ERROR;
	Tree carrier;
	char* result;
	if (type == 3) {
		char* qtype = getWord(question, 1);
		if (strcmp("howmany ", qtype) != 0) return ERROR;
		char* object = getWord(question, 2);
		removeLastChar(object);
		char* searchWhat = getWord(question, 3);
		if(!searchTree(root, searchWhat, &carrier)) return ERROR;
		printString(searchWhat);
		int count = 1;
		if (!calculateNums(carrier->child, object, &count)) printf(" has 0 ");
		else printf(" has %d ", count);
		printString(object);
		puts("");
		free(searchWhat);
		free(object);
		free(qtype);
	} else if (type == 2) {
		char* qType = getWord(question, 1);
		if (strcmp("whatis ", qType) != 0) return ERROR;
		char* toKnow = getWord(question, 2);
		if(!searchTree(root, toKnow, &carrier)) {
			puts("Î´ÕÒµ½Ä¿±ê£¡");
			return ERROR;
		}
		printf("part ");
		printString(toKnow);
		printf(" subparts are:\n");
		Node* lchild = carrier->child;
		while (lchild != NULL) {
			printf("    %d %20s\n", lchild->d->account, lchild->d->name);
			lchild = lchild->brother;
		}
		free(lchild);
		free(qType);
	} else return ERROR;
	return OK;
}
Status fileQuestion(Tree root) {
	FILE *fptr;
	char question[100];
	fptr = fopen("./datas/queries.txt", "r");
	if (fptr == NULL) {
		printf("Failed to open file\n");
		return ERROR;
	}
	while (fgets(question, 100, fptr)) {
		puts("#####################");
		printString(question);
		parseQuestion(question, root);
		puts("");
	}
	fclose(fptr);
	return OK;
}
Boolean calculateNums(const Tree root, const char* toSearch, int* num) {
	if (root == NULL) return FALSE;
	if(strcmp(root->d->name, toSearch) == 0) {
		*num = root->d->account;
		return TRUE;
	}
	if (calculateNums(root->child, toSearch, num)) {
		*num *= root->d->account;
		return TRUE;
	}
	Tree brother = root->brother;
	if (calculateNums(brother, toSearch, num)) return TRUE;
	return FALSE;
}

#endif
