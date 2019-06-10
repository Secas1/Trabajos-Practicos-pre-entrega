#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu(char*);

int main()
{
    int out=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int s;
    do{
        switch(menu("\n1-Cargar los datos de los empleados desde el archivo data.csv(Modo texto)\n2-Cargar los datos de los empleados desde el archivo data.csv(Modo binario)\n3-Alta empleado\n4-Modificar empleado\n5-Baja Empleado\n6-Listar empleado\n7-Ordenar empleados\n8-Guardar los datos de los empleados en el archivo data.csv(Modo texto)\n9-Guardar los datos de los empleados en el archivo data.csv(Modo binario)\n10-Salir\nOpcion: "))
        {
            case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
            case 2:
            controller_loadFromBinary("data.csv",listaEmpleados);
            break;
            case 3:
            controller_addEmployee(listaEmpleados);
            break;
            case 4:
            controller_editEmployee(listaEmpleados);
            break;
            case 5:
            controller_removeEmployee(listaEmpleados);
            break;
            case 6:
            controller_ListEmployee(listaEmpleados);
            break;
            case 7:
            controller_sortEmployee(listaEmpleados);
            break;
            case 10:
            out=1;
            break;
            default:
            printf("\n\nPor favor ingresar una opcion valida\n\n");
            break;
        }
    system("pause");
    system("cls");
    }while(out==0);
    return 0;
}


