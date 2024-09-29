#ifndef DEPARTMENT_C
#define DEPARTMENT_C

#include "../config/utils.c"
#include "department.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Status initDepartment(Department **newDepartment) {
	*newDepartment = (Department*) malloc (sizeof(Department));
	if(!(*newDepartment)) exit(OVERFLOW);
	(*newDepartment)->name = (char*) malloc (sizeof(char) * (NAME_MAX_LENGTH + 1));
	if(!((*newDepartment)->name)) exit(OVERFLOW);
	(*newDepartment)->name[0] = '\0';
	(*newDepartment)->account = 0;
	return OK;
}

Status setDepartment(Department **toSet, const char* newName, const int newAccount) {
	if (*toSet) {
		free((*toSet)->name);
	} else {
		*toSet = (Department*) malloc(sizeof(Department));
		if (!*toSet)  exit(OVERFLOW);
	}

	(*toSet)->account = newAccount;
	(*toSet)->name = (char*) malloc(strlen(newName) + 1);
	if (!(*toSet)->name) {
		free(*toSet);
		*toSet = NULL;
		return OVERFLOW;
	}
	strcpy((*toSet)->name, newName);
	return OK;
}

Status showDepartment(const Department *toShow) {
	if (toShow == NULL) return ERROR;
	printf("this is ");
	printString(toShow->name);
	printf(", its account is %d",toShow->account);
	return OK;
}

#endif
