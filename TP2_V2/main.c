#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 3

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef eEmployee;

int main()
{
    int op;
    int out=0;
    int auxDel;

    eEmployee Employees [T];
    initEmployees(Employees,T);

    do
    {
        op = menu();

        switch(op)
        {
            case 1:
            employeeData(Employees,T,51,51);
            break;

            case 3:
            printEmployees(Employees,T);
            printf("Employee ID: ");
            scanf("%d",&auxDel);

            removeEmployee(Employees,T,auxDel);
            break;

            case 4:
            printEmployees(Employees,T);
            break;

            case 5:
            out=1;
            break;
        }

        system("pause");
        system("cls");
    }while(out==0);
    return 0;
}

int menu()
{
    int op;

    printf("\n1.Alta");
    printf("\n2.Modificacion");
    printf("\n3.Baja");
    printf("\n4.Informar");
    printf("\n5.Salir");
    printf("\nOption: ");
    scanf("%d",&op);

    return op;
}

int employeeData(eEmployee list[],int len,int lenName,int lenLastName)
{
    int auxId;
    char auxName[100];
    char auxLastName[100];
    float auxSalary;
    int auxSector;

    int out;

    printf("\nId: ");
    scanf("%d",&auxId);

    do
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==0&&list[i].id==auxId)
            {
                printf("\nPlease re-enter the ID: ");
                scanf("%d",&auxId);
            }
            else
            {
                out=1;
            }
        }
    }while(out==0);

    out=0;
    fflush(stdin);
    printf("\nName: ");
    gets(auxName);

    do
    {
        if(strlen(auxName)>lenName)
        {
            printf("Please re-enter the Name: ");
            gets(auxName);
        }
        else
        {
            out=1;
        }
    }while(out==0);

    out=0;
    fflush(stdin);
    printf("\nLast Name: ");
    gets(auxLastName);

    do
    {
        if(strlen(auxName)>lenName)
        {
            printf("Please re-enter the Last Name: ");
            gets(auxName);
        }
        else
        {
            out=1;
        }
    }while(out==0);

    fflush(stdin);
    printf("\nSalary: ");
    scanf("%f",&auxSalary);
    printf("\n####%d",auxSalary);
    fflush(stdin);
    printf("\nSector: ");
    scanf("%d",&auxSector);

    addEmployees(list,len,auxId,auxName,auxLastName,auxSalary,auxSector);
}

int initEmployees(eEmployee list [],int len)
{
    for(int i=0;i<len;i++)
    {
        list[i].isEmpty=1;
    }
}

void addEmployees(eEmployee list[],int len,int id,char name[],char lastName[],int salary,int sector)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            list[i].id=id;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            list[i].salary=salary;
            list[i].sector=sector;
            list[i].isEmpty=0;

            printf("\n####%d",salary);
            break;
        }
    }
}

int findEmployeeById(eEmployee list[], int len,int id)
{
    int index;

    for(int i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            index=i;
            break;
        }
    }

    return index;
}

int removeEmployee(eEmployee list[], int len, int id)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            list[i].isEmpty=1;
            break;
        }
    }
}

int printEmployees(eEmployee list[], int len)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("%d\t%s\t%s\t%.2f\t%d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
}



