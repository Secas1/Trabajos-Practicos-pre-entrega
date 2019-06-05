#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
        switch(menu("\n1-\n2-\n3-\n4-\n5-\n6-\n7-\n8-\n9-\n10-\n"))
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
            s=ll_len(listaEmpleados);
            printf("--%d--",s);
            break;
            case 6:
            controller_ListEmployee(listaEmpleados);
            break;
            case 10:
            out=1;
            break;
        }
    system("pause");
    system("cls");
    }while(out==0);
    return 0;
}

int menu(char* OptMenu)
{
    int option=-1;

    printf("%s",OptMenu);
    fflush(stdin);
    scanf("%d",&option);

    return option;
}
