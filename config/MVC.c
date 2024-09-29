#ifndef MVC_C
#define MVC_C

#include <stdio.h>
#include <Windows.h>
#include "MVC.h"
#include "status.h"
#include "utils.c"

#include "../experiment1/experiment1.c"
#include "../experiment2/experiment2.c"
#include "../experiment3/experiment3.c"
#include "../experiment4/experiment4.c"

void Menu() {
	printStars(16);
	printf(" Experiment  Menu ");
	printStars(16);
	puts("");
	printf("**\t1: 实验1 基于单链表的集合运算\t\t**\n");
	printf("**\t2: 实验2 基于栈的中缀表达式运算\t\t**\n");
	printf("**\t3: 实验3 基于二叉树的建筑结构储存系统\t**\n");
	printf("**\t4: 实验4 基于图论的铁路运输规划系统\t**\n");
	printf("**\t\t0: 退出系统\t\t\t**\n");
	printStars(50);
	puts("");
}

void ExperimentUI_1() {
	printStars(3);
	printf(" 实验1 基于单链表的集合运算 ");
	printStars(3);
	puts("");
	printf("**\t1: 集合A数据输入\t**\n");
	printf("**\t2: 集合B数据输入\t**\n");
	printf("**\t3: 集合A数据删除\t**\n");
	printf("**\t4: 集合B数据删除\t**\n");
	printf("**\t5: 集合A和B的数据显示\t**\n");
	printf("**\t6: 集合A和集合B的并集\t**\n");
	printf("**\t7: 集合A和集合B的交集\t**\n");
	printf("**\t8: 集合A和集合B的差集\t**\n");
	printf("**\t9: 集合A和集合B的补集\t**\n");
	printf("**\t0: 返回上一级\t\t**\n");
	printStars(34);
	puts("");
}

void ExperimentUI_2() {
	printStars(2);
	printf(" 实验2 基于栈的中缀表达式运算 ");
	printStars(2);
	puts("");
	printf("**\t1: 表达式数据输入\t**\n");
	printf("**\t2: 打印当前表达式\t**\n");
	printf("**\t3: 重置当前表达式\t**\n");
	printf("**\t4: 计算当前表达式\t**\n");
	printf("**\t5: 展示计算的过程\t**\n");
	printf("**\t0: 返回上一级\t\t**\n");
	printStars(34);
	puts("");
}

void ExperimentUI_3() {
	printStars(2);
	printf(" 实验3 基于树的医院建筑结构存储 ");
	printStars(2);
	puts("");
	printf("**\t  1: 打印存储情况\t  **\n");
	printf("**\t  2: 导入文件数据\t  **\n");
	printf("**\t  3: 从命令行提问\t  **\n");
	printf("**\t  4: 文件自动提问\t  **\n");
	printf("**\t   0: 返回上一级\t  **\n");
	printStars(36);
	puts("");
}

void ExperimentUI_4() {
	printStars(2);
	printf("实验4 基于图论的铁路运输规划系统");
	printStars(2);
	puts("");
	printf("**\t  1: 打印邻接矩阵\t  **\n");
	printf("**\t  2: 价格最小生成树\t  **\n");
	printf("**\t  3: 距离最小生成树\t  **\n");
	printf("**\t  4: 价格最低路径\t  **\n");
	printf("**\t  5: 距离最短路径\t  **\n");
	printf("**\t   0: 返回上一级\t  **\n");
	printStars(36);
	puts("");
}


void Controller() {
	Boolean flag = TRUE;
	system("cls"); 
	do {
		Menu();
		int choice = getChoice();
		system("cls");
		switch(choice) {
			case 1:
				ExperimentController_1();
				break;
			case 2:
				ExperimentController_2();
				break;
			case 3:
				ExperimentController_3();
				break;
			case 4:
				ExperimentController_4();
				break;
			case 0:
				flag = FALSE;
				break;
			default:
				printf("输入错误，请重新操作！\n");
				system("pause");
		}
	} while(flag);
}


void ExperimentController_1() {
	Boolean flag = TRUE;
	LinkedList aSet,bSet,ALLSet;
	initLinkedList(&aSet);
	initLinkedList(&bSet);
	do {
		initLinkedList(&ALLSet);
		ExperimentUI_1();
		int choice = getChoice();
		system("cls");
		switch(choice) {
			case 1:
				if(!addListElem(aSet)) printf("add ERROR!\n");
				break;
			case 2:
				if(!addListElem(bSet)) printf("add ERROR!\n");
				break;
			case 3:
				printf("集合A的元素有：");
				if(!delSet(aSet)) printf("del ERROR!\n");
				break;
			case 4:
				printf("集合B的元素有：");
				if(!delSet(bSet)) printf("del ERROR!\n");
				break;
			case 5:
				printf("集合A的元素有：");
				if(!printLinkedList(aSet)) printf("ERROR!\n");
				puts("");
				printf("集合B的元素有：");
				if(!printLinkedList(bSet)) printf("ERROR!\n");
				puts("");
				break;
			case 6:
				printf("集合A、B的并集是：");
				if(!bingAB(aSet,bSet,ALLSet)) printf("ERROR!\n");
				if(!printLinkedList(ALLSet)) printf("ERROR!\n");
				puts("");
				clearLinkedList(ALLSet->next);
				ALLSet->next = NULL;
				break;
			case 7:
				printf("集合A、B的交集是：");
				if(!mergeAB(aSet,bSet,ALLSet)) printf("ERROR!\n");
				if(!printLinkedList(ALLSet)) printf("ERROR!\n");
				puts("");
				clearLinkedList(ALLSet->next);
				ALLSet->next = NULL;
				break;
			case 8:
				printf("集合A与B的差集是：");
				if(!copyLinkedList(aSet,ALLSet)) printf("ERROR!\n");
				if(!chaAB(aSet,bSet,ALLSet)) printf("ERROR!\n");
				if(!printLinkedList(ALLSet)) printf("ERROR!\n");
				puts("");
				clearLinkedList(ALLSet->next);
				ALLSet->next = NULL;
				break;
			case 9:
				printf("全集采用集合A、B的并集，即：");
				if(!bingAB(aSet,bSet,ALLSet)) printf("ERROR!\n");
				if(!printLinkedList(ALLSet)) printf("ERROR!\n");
				puts("");
				if(!buAB(aSet,bSet,ALLSet)) printf("ERROR!\n");
				clearLinkedList(ALLSet->next);
				ALLSet->next = NULL;
				break;
			case 0:
				flag = FALSE;
				break;
			default:
				puts("输入错误，请重新操作！\n");
		}
		destroyLinkedList(&ALLSet);
		system("pause");
		system("cls");
	} while(flag);
	destroyLinkedList(&aSet);
	destroyLinkedList(&bSet);
}

void ExperimentController_2() {
	Boolean flag = TRUE;
	ElemType data = 0;
	Stack carrier;
	initStack(&carrier);
	do {
		ExperimentUI_2();
		int choice = getChoice();
		system("cls");
		switch(choice) {
			case 1:
				do {
					system("cls");
					puts("允许的运算符仅为+-*/，输入\"#\"退出");
					printf("当前表达式：");
					if(!printAsEq(carrier)) puts("ERROR!");
					puts("");
					char temp = getChar();
					if(temp == '#') break;
					else if((temp - '0' > -1 && temp - '0' < 10) || inOperSet(temp))
						push(carrier,temp);
					else if(temp == '\n' || temp == '\r' || temp == ' ') continue;
					else {
						puts("非法输入！");
						system("pause");
					}
				} while(TRUE);
				break;
			case 2:
				printf("当前表达式：");
				if(!printAsEq(carrier)) puts("ERROR!");
				puts("");
				break;
			case 3:
				if(clearStack(carrier)) puts("已重置完毕");
				break;
			case 4:
				if(!calculate(carrier,&data,0)) puts("ERROR!");
				else printf("计算结果为：%d\n",data);
				break;
			case 5:
				if(!calculate(carrier,&data,1)) puts("ERROR!");
				else printf("计算结果为：%d\n",data);
				break;
			case 0:
				flag = FALSE;
				break;
			default:
				puts("输入错误，请重新操作！\n");
		}
		system("pause");
		system("cls");
	} while(flag);
	destroyStack(&carrier);
}

void ExperimentController_3() {
	Boolean flag = TRUE;
	char question[100];
	Tree carrier;
	initTree(&carrier);
	initDepartment(&(carrier->d));
	setDepartment(&(carrier->d),"hospital",1);
	do {
		ExperimentUI_3();
		int choice = getChoice();
		system("cls");
		switch(choice) {
			case 1:
				printf("*");
				printTree(0,carrier);
				break;
			case 2:
				if(!(createArchitecture(carrier))) puts("ERROR!");
				else puts("finished!");
				break;
			case 3:
				printf("请输入你的问题：\n>> ");
				scanf(" %99[^\n]", question);
				if(!parseQuestion(question, carrier)) puts("输入格式错误，请重新操作！");
				break;
			case 4:
				if(!fileQuestion(carrier)) puts("读取失败");
				else puts("Finish!");
				break;
			case 0:
				flag = FALSE;
				break;
			default:
				puts("输入错误，请重新操作！\n");
		}
		system("pause");
		system("cls");
	} while(flag);
	destroyTree(&carrier);
}

void ExperimentController_4() {
	Boolean flag = TRUE;
	char question[100];
	Graph distanceGraph;
	Graph priceGraph;
	initGraph(&distanceGraph);
	initGraph(&priceGraph);
	if (!loadGraphFromFile(&distanceGraph, &priceGraph)) puts("图初始化失败！");
	else puts("自动读取信息完毕！");
	system("pause");
	system("cls");
	do {
		ExperimentUI_4();
		int choice = getChoice();
		system("cls");
		switch(choice) {
			case 1:
				puts("距离邻接矩阵为：");
				if (!printGraph(distanceGraph)) puts("图初始化失败！");
				puts("价格邻接矩阵为：");
				if (!printGraph(priceGraph)) puts("图初始化失败！");
				break;
			case 2:
				if(!minTree(priceGraph)) puts("读取失败，请重新操作！");
				else puts("Finish!");
				break;
			case 3:
				if(!minTree(distanceGraph)) puts("读取失败，请重新操作！");
				else puts("Finish!");
				break;
			case 4:
				puts("主影响因素为价格：");
				if(!minRoute(priceGraph, distanceGraph)) puts("读取失败，请重新操作！");
				else puts("Finish!");
				break;
			case 5:
				puts("主影响因素为距离：");
				if(!minRoute(distanceGraph, priceGraph)) puts("读取失败，请重新操作！");
				else puts("Finish!");
				break;
			case 0:
				flag = FALSE;
				break;
			default:
				puts("输入错误，请重新操作！\n");
		}
		system("pause");
		system("cls");
	} while(flag);
}

#endif
