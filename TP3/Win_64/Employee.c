#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee=(Employee*)malloc(sizeof(Employee));

    if(pEmployee!=NULL)
    {
        return pEmployee;
    }
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;
    int auxId,auxHorasTrabajadas,auxSueldo;
    pEmployee=(Employee*)malloc(sizeof(Employee));

    if(pEmployee!=NULL)
    {
        auxId=atoi(idStr);
        auxHorasTrabajadas=atoi(horasTrabajadasStr);
        auxSueldo=atoi(sueldoStr);
        employee_setId(pEmployee,auxId);
        employee_setHorasTrabajadas(pEmployee,auxHorasTrabajadas);
        employee_setNombre(pEmployee,nombreStr);
        employee_setSueldo(pEmployee,auxSueldo);

        return pEmployee;
    }
}

int employee_setId(Employee* this,int id)
{
    this->id=id;
}
int employee_getId(Employee* this,int* id)
{
    *id=this->id;
}
int employee_setNombre(Employee* this,char* nombre)
{
    strcpy(this->nombre,nombre);
}

int employee_getNombre(Employee* this,char* nombre)
{
    strcpy(nombre,this->nombre);
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    this->horasTrabajadas=horasTrabajadas;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    *horasTrabajadas=this->horasTrabajadas;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    this->sueldo=sueldo;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    *sueldo=this->sueldo;
}


