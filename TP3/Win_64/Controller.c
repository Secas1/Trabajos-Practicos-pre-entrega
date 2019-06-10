#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funciones.h"



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
    int idMod,verificar;
    Employee* pEmployee;

    int auxInt;
    char auxStr[100];

    printf("Id de empleado a modificar: ");
    fflush(stdin);
    scanf("%d",&idMod);
    idMod--;

    pEmployee=ll_get(pArrayListEmployee,idMod);
    printf("%10d%20s%10d%10d",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);

    printf("ModificaR?\n1.Si\n2.No\nOpcion: ");
    fflush(stdin);
    scanf("%d",&verificar);

    if(verificar==0)
    {
        printf("\nModificacion cancelada.\n");
    }
    else
    {
        switch(menu("\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\nOpcion: "))
        {
            case 1:
            printf("\nNuevo Nombre: ");
            fflush(stdin);
            scanf("%s",&auxStr);
            employee_setNombre(pEmployee,auxStr);
            break;
            case 2:
            printf("\nHoras trabajadas: ");
            fflush(stdin);
            scanf("%d",&auxInt);
            employee_setHorasTrabajadas(pEmployee->horasTrabajadas,auxInt);
            break;
            case 3:
            printf("\nSueldo: ");
            fflush(stdin);
            scanf("%d",auxInt);
            employee_setSueldo(pEmployee,auxInt);
            break;
        }
    }


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
    int idDelete,eliminar;
    Employee* pEmployee;

    if(pArrayListEmployee!=NULL)
    {
        printf("Id empleado a eliminar: ");
        fflush(stdin);
        scanf("%d",&idDelete);

        idDelete--;

        pEmployee=ll_get(pArrayListEmployee,idDelete);

        printf("%10d%20s%10d%10d",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
        printf("\nSeguro de eliminar?\n1.Si\n2.No\nOpcion: ");
        fflush(stdin);
        scanf("%d",&eliminar);

        if(eliminar==1)
        {
            ll_remove(pArrayListEmployee,idDelete);
            printf("\nEliminacion completada\n");
        }

    }
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
    Employee* pEmployee;

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);

            printf("%10d%20s%10d%10d\n",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
        }
    }

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

