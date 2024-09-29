#ifndef EXPERIMENT2_H
#define EXPERIMENT2_H

#include "../DataStructure/Stack/Stack.c"

char operSet[] = {'+','-','*','/'};
int OPER_NUM = 4;
Boolean inOperSet(const char toJudge);
int getIndex(const char toGet);
ElemType operater(const ElemType num1, const ElemType num2, int type);
Status printAsEq(const Stack toPrint);
Status calculate(const Stack eq, ElemType* carrier, const int signal);
void showProcess(const Stack numStack, const Stack operStack);
Status showOperStack(const Stack operStack);

#endif
