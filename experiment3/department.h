#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#define NAME_MAX_LENGTH 30

#include "../config/status.h"

typedef struct{
	char* name;
	int account;
}Department;

/**@Author    : wyj
 * @function  : to initialize a new Department
 * @parameter : a ptr of Department's address to recieve this new Department
 * @return    : initialize successfully or not
 */
Status initDepartment(Department **newDepartment);

/**@Author    : wyj
 * @function  : to set new datas to a Department
 * @parameter : a Department's address to set, newName, newAccount
 * @return    : set successfully or not
 */
Status setDepartment(Department **toSet, const char* newName, const int newAccount);

/**@Author    : wyj
 * @function  : to show a Department's datas
 * @parameter : a Department's address to be shown
 * @return    : show successfully or not
 */
Status showDepartment(const Department *toShow);

#endif
