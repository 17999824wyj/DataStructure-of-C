#ifndef LIST_H
#define LIST_H

#include "../../config/status.h"

typedef struct ListNode {
	ElemType data; /* used to record values */
	struct ListNode * next; /* used to record the address of next location */
} ListNode, *LinkedList;

/* functions define are as bellow */

/**@Author    : wyj
 * @function  : to initialize a new LinkedList
 * @parameter : a LinkedList's address to recieve this new LinkedList
 * @return    : initialize successfully or not
 */
Status initLinkedList(LinkedList *newLinkedList);

/**@Author    : wyj
 * @function  : to free all the space of input LinkedList, including its headPtr!
 * @parameter : the LinkedList to destroy
 * @return    : destory successfully or not
 */
Status destroyLinkedList(LinkedList *toDestroy);

/**@Author    : wyj
 * @function  : just reserve the LinkedList, clear all other ListNodes
 * @parameter : the first data ListNode of the LinkedList to operate
 * @return    : operate successfully or not
 */
Status clearLinkedList(ListNode *firstData);

/**@Author    : wyj
 * @function  : to judge the LinkedList input is empty
 * @parameter : the LinkedList to judge
 * @return    : whether this LinkedList is empty
 */
Boolean isEmptyList(const LinkedList toJudge);

/**@Author    : wyj
 * @function  : to show all data in this LinkedList
 * @parameter : the headPtr of the LinkedList to print
 * @return    : void
 */
Status printLinkedList(const LinkedList toPrint);

/**@Author    : wyj
 * @function  : to get how much data is in this LinkedList now
 * @parameter : the LinkedList to arrive , the carrier to read length
 * @return    : whether the carrier get the length
 */
Status getListLength(const LinkedList toGetLength, int *carrier) ;

/**@Author 	  : wyj
 * @function  : create a new ListNode on the carrier, and this is the prototype to implement Queue or Stack!
 * @parameter : the address of carrier to receive the new created ListNode , the initial data of the new ListNode
 * @return 	  : whether create successfully
 */
Status createListNode(LinkedList *carrier, const ElemType dataNum);

/**@Author 	  : wyj
 * @function  : add a dataNum to concrete location
 * @parameter : the LinkedList to operate , the data that will be inserted , the location of where it will be write
 * @return 	  : whether add successfully
 */
Status addListNode(const LinkedList toAdd, const ElemType dataNum, const int location);

/**@Author    : wyj
 * @function  : mode0 -- delete a data of the {{index}} from the input LinkedList
 *				mode1 -- delete the first data which equals to {{Num}} from the begining of the LinkedList
 * @parameter : the SqList to operate , the location of where the data will be deleted or the index of
 * 				the first element to be deleted or the number at the end of the list , the deleting mode
 * @return    : whether delete successfully
 */
Status delListNode(const LinkedList toDelete, const int indexOrNum, const int mode);

/**@Author    : wyj
 * @function  : change the data of concrete index
 * @parameter : the LinkedList to change , data will change to what , the index of the element to be changed
 * @return    : whether change successfully
 */
Status setToLinkedList(const LinkedList toChange, const int transTo, const int index);

/**@Author    : wyj
 * @function  : to search for a concrete num
 * @parameter : search on which LinkedList , find what , the index of whether get the number ,
 * 				if found, the index will be stored in the carrier; otherwise, it will be -1
 * @return    : whether it finds successfully
 */
Boolean findNum(const LinkedList toSearch, const ElemType toFind, int *carrier);

/**@Author    : wyj
 * @function  : to get the data on the index
 * @parameter : search on which LinkedList , where to get data , the carrier of data
 * @return    : whether get data successfully
 */
Boolean findWhat(const LinkedList toSearch, const int index, ElemType *carrier);

/**@Author    : wyj
 * @function  : to copy the data in the first list to the second
 * @parameter : copy on which LinkedList , copy to which LinkedList
 * @return    : whether copy data successfully
 */
Status copyLinkedList(const LinkedList toCopy, const LinkedList toPaste);

#endif
