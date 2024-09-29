#ifndef TREE_H
#define TREE_H

#include "../../config/status.h"
#include "../../experiment3/department.h"

typedef struct CBTree {
	Department * d; /* the data to be stored */
	struct CBTree * child; /* the pointer to its left child */
	struct CBTree * brother; /* the pointer to its next brother */
} Node, *Tree;

/**@Author    : wyj
 * @function  : to initialize a new Tree
 * @parameter : a Tree's address to recieve this new Tree
 * @return    : initialize successfully or not
 */
Status initTree(Tree *newTree);

/**@Author    : wyj
 * @function  : to free the space of the Tree
 * @parameter : the root of the Tree to destroy
 * @return    : destroy successfully or not
 */
Status destroyTree(Tree *root);

/**@Author    : wyj
 * @function  : to make the given Tree to a new created Tree
 * @parameter : the root of the Tree to clean up
 * @return    : clean successfully or not
 */
Status clearTree(Node* toClear);

/**@Author    : wyj
 * @function  : to judge the Tree input is empty
 * @parameter : the Tree to judge
 * @return    : whether this Tree is empty
 */
Boolean isEmptyTree(const Tree toJudge);

/**@Author    : wyj
 * @function  : to show all data in this Tree
 * @parameter : the depth of the tree, the Tree to print
 * @return    : whether print successfully
 */
Status printTree(const int blanket, const Tree toPrint);

/**@Author    : wyj
 * @function  : to get how much data is in this Tree now
 * @parameter : the Tree to arrive , the carrier to read length
 * @return    : whether the carrier get the length
 */
Status getDepth(const Tree toGet, int *carrier);

#endif
