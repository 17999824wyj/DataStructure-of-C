#ifndef EXPERIMENT2_C
#define EXPERIMENT2_C

#include "experiment2.h"

Boolean inOperSet(const char toJudge)
{
	Boolean flag = FALSE;
	int temp;
	for (temp = 0; temp < OPER_NUM; ++temp)
		if (operSet[temp] == toJudge)
			flag = TRUE;
	return flag;
}

int getIndex(const char toGet)
{
	int temp;
	for (temp = 0; temp < OPER_NUM; ++temp)
		if (operSet[temp] == toGet)
			return temp;
	return -1;
}

ElemType operater(const ElemType num1, const ElemType num2, int type)
{
	switch (type)
	{
	case 0:
		return num1 + num2;
	case 1:
		return num2 - num1;
	case 2:
		return num1 * num2;
	case 3:
		if (num1 != 0)
			return num2 / num1;
		else
			puts("divide 0 !!!");
		return -1;
	default:
		puts("ERROR!");
		return -1;
	}
}

Status printAsEq(const Stack toPrint)
{
	if (toPrint->data == NULL)
		return ERROR;
	int i;
	for (i = 1; i <= toPrint->length; i++)
	{
		printf("%c", toPrint->data[i - 1]);
	}
	return OK;
}

Status calculate(const Stack eq, ElemType *carrier, const int singal)
{
	Stack numS, operS;
	initStack(&numS);
	initStack(&operS);
	int i;
	for (i = 0; i < eq->length; ++i)
	{
		char temp = eq->data[i];
		if (inOperSet(temp))
		{
			int index = getIndex(temp);
			if (isEmptyStack(operS))
				push(operS, index);
			else
			{
				int flag = 0;
				do
				{
					if (isEmptyStack(operS))
					{
						if (!push(operS, index))
							return ERROR;
						break;
					}
					int type;
					flag = 0;
					if (!getTop(operS, &type))
						return ERROR;
					if ((type / 2) >= (index / 2))
					{
						pop(operS, &type);
						if (numS->length < 2)
							return ERROR;
						int num1, num2;
						pop(numS, &num1);
						pop(numS, &num2);
						if (!push(numS, operater(num1, num2, type)))
							return ERROR;
						flag = 1;
					}
					else
						push(operS, index);
				} while (flag);
			}
		}
		else
		{
			int res = 0;
			do
			{
				temp = eq->data[i];
				res = res * 10 + (temp - '0');
				if (inOperSet(eq->data[i + 1]) || i + 1 == eq->length)
					break;
				++i;
			} while (i < eq->length);
			push(numS, res);
		}
		if (singal)
			showProcess(numS, operS);
	}
	while (!isEmptyStack(operS))
	{
		int type;
		pop(operS, &type);
		if (numS->length < 2)
			return ERROR;
		int num1, num2;
		pop(numS, &num1);
		pop(numS, &num2);
		if (!push(numS, operater(num1, num2, type)))
			return ERROR;
	}
	pop(numS, carrier);
	destroyStack(&numS);
	destroyStack(&operS);
	return OK;
}

void showProcess(const Stack numStack, const Stack operStack)
{
	printf("当前数栈：");
	printStack(numStack);
	printf("  ||  ");
	printf("当前符号栈：");
	showOperStack(operStack);
	puts("");
}

Status showOperStack(const Stack operStack)
{
	if (operStack->data == NULL)
		return ERROR;
	int i;
	for (i = 1; i <= operStack->length; i++)
	{
		printf("%c\t", operSet[operStack->data[i - 1]]);
		if (i % 10 == 1 && i != 1)
			puts("");
	}
	return OK;
}

#endif
