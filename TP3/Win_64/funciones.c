#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int menu(char* OptMenu)
{
    int option=-1;

    printf("%s",OptMenu);
    fflush(stdin);
    scanf("%d",&option);

    return option;
}

int sortEmployeeById(LinkedList* pArrayListEmployee,int i)
{
    Employee* pEmployee;
    pEmployee=ll_get(i);
    if(p)
}
