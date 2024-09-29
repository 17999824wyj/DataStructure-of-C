#ifndef EXPERIMENT1_C
#define EXPERIMENT1_C

#include "experiment1.h"

Status addListElem(const LinkedList toAdd) {
	int carrier = 0, index = 0;
	getListLength(toAdd,&carrier);
	ElemType data = 0;
	printf("������Ҫ��ӵ����ݣ�");
	scanf("%d",&data);
	if (findNum(toAdd,data,&index)) return ERROR;
	return addListNode(toAdd,data,++carrier);
}

Status mergeAB(const LinkedList A, const LinkedList B, const LinkedList ALLSet) {
	ListNode* a = A->next;
	ListNode* b = B->next;
	int length = 0, index = 0;
	while(a != NULL) {
		if(findNum(B,a->data,&index))
			if(!addListNode(ALLSet,a->data,++length))
				return ERROR;
		a = a->next;
	}
	return OK;
}

Status bingAB(const LinkedList A, const LinkedList B, const LinkedList ALLSet) {
	ListNode* a = A->next;
	ListNode* b = B->next;
	int length = 0;
	while(a != NULL) {
		if(!addListNode(ALLSet,a->data,++length)) return ERROR;
		a = a->next;
	}
	while(b != NULL) {
		int index = 0;
		if(findNum(ALLSet,b->data,&index)) {
			b = b->next;
			continue;
		}
		if(!addListNode(ALLSet,b->data,++length)) return ERROR;
		b = b->next;
	}
	return OK;
}

Status chaAB(const LinkedList A, const LinkedList B, const LinkedList ALLSet) {
	LinkedList jiao;
	initLinkedList(&jiao);
	if(!mergeAB(A,B,jiao)) return ERROR;
	ListNode* temp = jiao->next;
	while(temp != NULL) {
		if(!delListNode(ALLSet,temp->data,1)) return ERROR;
		temp = temp->next;
	}
	return destroyLinkedList(&jiao);
}

Status buAB(const LinkedList A, const LinkedList B, const LinkedList ALLSet) {
	LinkedList temp;
	ListNode* a = A->next;
	ListNode* b = B->next;
	initLinkedList(&temp);
	copyLinkedList(ALLSet,temp);
	printf("A�Ĳ����ǣ�");
	while(a != NULL) {
		if(!delListNode(temp,a->data,1)) return ERROR;
		a = a->next;
	}
	if(!printLinkedList(temp)) printf("ERROE!\n");
	puts("");
	clearLinkedList(temp->next);
	temp->next = NULL;
	copyLinkedList(ALLSet,temp);
	printf("B�Ĳ����ǣ�");
	while(b != NULL) {
		if(!delListNode(temp,b->data,1)) return ERROR;
		b = b->next;
	}
	if(!printLinkedList(temp)) printf("ERROE!\n");
	puts("");
	return destroyLinkedList(&temp);
}

Status delSet(const LinkedList toDel) {
	printLinkedList(toDel);
	printf("\n������Ҫɾ���������±꣬�����ݲ����ڣ��򽫷���\n");
	printf("��������Ϊ{2��3}������1��ɾ��2������2��ɾ��3������-1���˳�\n");
	int choice;
	printf("index >> ");
	scanf("%d",&choice);
	if(choice == -1) return OK;
	return delListNode(toDel, choice, 0);
}

#endif
