#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
        char str1[30],str2[128],str3[30],str4[30];
        int r;

        r=fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]",str1,str2,str3,str4);

        do
        {
            r=fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]",str1,str2,str3,str4);
            if(r==4)

            ll_add(pArrayListEmployee,employee_newParametros(str1,str2,str3,str4));

        }while(!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
