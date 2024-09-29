#ifndef EXPERIMENT3_H
#define EXPERIMENT3_H

#include "../DataStructure/Tree/Tree.c"

/**@Author    : wyj
 * @function  : to add a node to the given Tree
 * @parameter : the Tree to add , the address of Department
 * @return    : whether the carrier get the length
 */
Status addNode(const Tree toAdd, Department *carrier);

/* @Author    : wyj
 * @function  : to search the node by concrete name on the given tree
 * @parameter : the tree to search on, the name to find, the carrier
 * @return    : whether find or not
 */
Boolean searchTree(const Tree root, const char* name, Tree* carrier);

/* @Author    : wyj
 * @function  : to create the architecture by the given file
 * @parameter : the tree to build on
 * @return    : whether find or not
 */
Status createArchitecture(Tree initTree);

/* @Author    : wyj
 * @function  : to parse the question by the given question
 * @parameter : the question we want to parse, the Tree to search on
 * @return    : whether finished successfully
 */
Status parseQuestion(char* question, Tree root);

/* @Author    : wyj
 * @function  : to parse the question by the given file
 * @parameter : the Tree to search on
 * @return    : whether finished successfully
 */
Status fileQuestion(Tree root);

/* @Author    : wyj
 * @function  : to search the node by concrete name on the given tree, and calculate num
 * @parameter : the tree to search on, the name to find, the carrier of num
 * @return    : whether find or not
 */
Boolean calculateNums(const Tree root, const char* toSearch, int* num);

#endif
