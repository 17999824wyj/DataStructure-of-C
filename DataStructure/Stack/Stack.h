#ifndef STACK_H
#define STACK_H

#include "../../config/status.h"
#define MAXLENGTH 100

typedef struct SqStack {
	ElemType * data; /* used to record the values in each space */
	int size; /* record the max length of this list */
	int length; /* used to record present length of this list */
} *Stack;

/**@Author    : wyj
 * @function  : to initialize a new Stack
 * @parameter : a Stack's address to recieve this new Stack
 * @return    : initialize successfully or not
 */
Status initStack(Stack *newStack);

/**@Author    : wyj
 * @function  : to free the space of the designative Stack
 * @parameter : the Stack to destroy
 * @return    : destroy successfully or not
 */
Status destroyStack(Stack *toDestroy);

/**@Author    : wyj
 * @function  : to make the given Stack to a new created Stack
 * @parameter : the Stack to clean up
 * @return    : clean successfully or not
 */
Status clearStack(const Stack toClear);

/**@Author    : wyj
 * @function  : to judge the Stack input is empty
 * @parameter : the Stack to judge
 * @return    : whether this Stack is empty
 */
Boolean isEmptyStack(const Stack toJudge);

/**@Author    : wyj
 * @function  : to show all data in this Stack
 * @parameter : the Stack to print
 * @return    : whether print successfully
 */
Status printStack(const Stack toPrint);

/**@Author    : wyj
 * @function  : to get how much data is in this Stack now
 * @parameter : the Stack to arrive , the carrier to read length
 * @return    : whether the carrier get the length
 */
Status getStackLength(const Stack toGet, int *carrier);

/**@Author    : wyj
 * @function  : to get the Size of this Stack
 * @parameter : the Stack to arrive , the carrier to read length
 * @return    : whether the carrier get the Size
 */
Status getSize(const Stack toGet, int *carrier);

/**@Author    : wyj
 * @function  : renew the Stack to make its maxLength changed , if new length is longer than data length ,
 *				those data will be thrown!
 * 				Actually , this makes "data" a new array.
 * @parameter : the Stack to change , the new Integer of maxLength
 * @return    : whether the length is successfully changed
 */
Status changeSize(const Stack toChange, const int newSize);

/**@Author 	  : wyj
 * @function  : add a dataNum to the present top of Stack
 * @parameter : the Stack to operate , the data that will be inserted
 * @return 	  : whether "push" successfully
 */
Status push(const Stack toAdd, const ElemType dataNum);

/**@Author    : wyj
 * @function  : pop a data from the top of Stack
 * @parameter : the Stack to operate , the carrier of the data
 * @return    : whether "pop" successfully
 */
Status pop(const Stack toPop, int *carrier);

/**@Author    : wyj
 * @function  : read the data from the top of the stack
 * @parameter : the Stack to search , the carrier of the data
 * @return    : whether change successfully
 */
Status getTop(const Stack toGet, int *carrier);

/**@Author    : wyj
 * @function  : to search for a concrete num
 * @parameter : search on which Stack , find what , the index of whether get the number ,
 * 				if found, the index will be stored in the carrier; otherwise, it will be -1
 * @return    : whether it find successfully
 */
Boolean search(const Stack toSearch, const ElemType toFind, int *carrier);

#endif
