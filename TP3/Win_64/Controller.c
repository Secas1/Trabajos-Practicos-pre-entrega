#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    int r;

    FILE* pFile;
    pFile=fopen(path,"r");

    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
    }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    char horasTrabajadas[20],sueldo[20],id[20],nombre[128];
    int auxId;

    printf("\nNombre: ");
    fflush(stdin);
    scanf("%s",&nombre);

    printf("\nHoras trabajadas: ");
    fflush(stdin);
    scanf("%s",&horasTrabajadas);

    printf("\nSueldo: ");
    fflush(stdin);
    scanf("%s",&sueldo);

    auxId=ll_len(pArrayListEmployee)+1;
    itoa(auxId,id,10);

    pEmployee=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
    ll_add(pArrayListEmployee,pEmployee);
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Node* pAuxNode;

    pAuxNode=pArrayListEmployee->pFirstNode;

    do
    {
        printf("\n %d",pAuxNode->pElement);
        pAuxNode=pAuxNode->pNextNode;
    }while(pArrayListEmployee->pFirstNode->pNextNode==NULL);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

