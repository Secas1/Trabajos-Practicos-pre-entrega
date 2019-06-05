#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int Menu_Inicial()
{
    int Opcion_Menu;

    printf("\n--------- MENU ---------");
    printf("\n1.Agregar persona");
    printf("\n2.Borrar Persona");
    printf("\n3.Imprimir lista");
    printf("\n4.Imprimir grafico de edades");
    printf("\n5.Salir");
    printf("\n\nOpcion a elegir: ");

    fflush(stdin);
    scanf("%d",&Opcion_Menu);

    return Opcion_Menu;
}

void Inicializar_Estado(ePersona iPersona[],int Tam)
{
    for(int i=0;i<Tam;i++)
    {
        iPersona[i].Estado=0;
    }
}
void Agregar_Persona(ePersona iPersona[],int Tam)
{
    int Cant_Agregar;
    int Aux_DNI;
    char Aux_Nombre[100];
    int Opcion_Error;
    int Error=0;
    int Error_Nombre;

    printf("\nQuedan %d espacios",Contador_Persona(iPersona,Tam));
    printf("\nA cuantos agregara?\n");
    fflush(stdin);
    scanf("%d",&Cant_Agregar);

    if(Cant_Agregar>Contador_Persona(iPersona,Tam))
    {
        printf("Cantidad invalida");
    }
    else
    {
        for(int i=0;i<Cant_Agregar;i++)
        {
            if(iPersona[i].Estado==0)
            {
                printf("\nNombre: ");
                fflush(stdin);
                gets(Aux_Nombre);

                Error_Nombre=Verificar_Nombre(Aux_Nombre,CANT_NOMBRE);

                while(Error_Nombre==1)
                {
                    printf("Nombre demasiado largo");
                    printf("\n1.Reingresar Nombre");
                    printf("\n2.Cancelar Ingreso");
                    printf("\n\nOpcion a elegir: ");
                    fflush(stdin);
                    scanf("%d",&Opcion_Error);

                    switch(Opcion_Error)
                    {
                        case 1:
                        printf("\nNombre: ");
                        fflush(stdin);
                        gets(Aux_Nombre);
                        Error_Nombre=Verificar_Nombre(Aux_Nombre,CANT_NOMBRE);
                        break;

                        case 2:
                        Error=2;
                        iPersona[i].Estado=0;
                        break;
                    }

                }

                if(Error_Nombre==0)
                    {
                        iPersona[i].Estado=1;
                        strcpy(iPersona[i].Nombre,Aux_Nombre);
                    }
                printf("\nEdad: ");
                fflush(stdin);
                scanf("%d",&iPersona[i].Edad);

                printf("\nDNI: ");
                fflush(stdin);
                scanf("%d",&Aux_DNI);

                Error=Verificar_DNI(Aux_DNI,iPersona,Tam);

                while(Error==1)
                {
                    printf("\nDNI ya ocupado");
                    printf("\n1.Reingresar DNI");
                    printf("\n2.Cancelar Ingreso");
                    printf("\n\nOpcion a elegir: ");
                    fflush(stdin);
                    scanf("%d",&Opcion_Error);

                    switch(Opcion_Error)
                    {
                        case 1:
                        printf("\nDNI: ");
                        fflush(stdin);
                        scanf("%d",&Aux_DNI);
                        Error=Verificar_DNI(Aux_DNI,iPersona,Tam);
                        break;

                        case 2:
                        Error=2;
                        iPersona[i].Estado=0;
                        break;
                    }
                }

                if(Error==0)
                {
                    iPersona[i].Estado=1;
                    iPersona[i].DNI=Aux_DNI;
                }
            }
            else
            {
                Cant_Agregar++;
            }
        }
    }
    system("pause");
}

int Contador_Persona(ePersona iPersona[],int Tam)
{
    int Contador=0;

    for(int i=0;i<Tam;i++)
    {
        if(iPersona[i].Estado==0)
            {
                Contador++;
            }
    }

    return Contador;
}

int Verificar_Nombre(char Aux_Nombre[],int Tam_Nombre)
{
    int Error=0;
    int Nombre_Long=0;

    Nombre_Long=strlen(Aux_Nombre);

    if(Nombre_Long>Tam_Nombre)
    {
        Error=1;
    }

    return Error;
}

int Verificar_DNI(int Aux_DNI,ePersona iPersona[],int Tam)
{
    int Verificar=0;

    for(int i=0;i<Tam;i++)
        {
            if(Aux_DNI==iPersona[i].DNI&&iPersona[i].Estado==1)
            {
                Verificar=1;
                break;
            }
        }

    return Verificar;
}

void Borrar_Persona(ePersona iPersona[],int Tam)
{
    int Num_Persona;
    int Opcion;
    int Ubicacion;

    printf("Numero de documento: ");
    fflush(stdin);
    scanf("%d",&Num_Persona);

    printf("\nSeguro de querer eliminar a %s",iPersona[Buscar_DNI(Num_Persona,iPersona,Tam)].Nombre);
    printf("\n1,Si");
    printf("\n2.No");
    fflush(stdin);
    scanf("%d",&Opcion);

    if(Opcion==1)
    {
        iPersona[Buscar_DNI(Num_Persona,iPersona,Tam)].Estado=0;
        printf("Se elimino exitosamente");
        system("pause");
    }
}

int Buscar_DNI(int Num_DNI,ePersona iPersona[],int Tam)
{
    int Posicion;

    for(int i=0;i<Tam;i++)
    {
        if(iPersona[i].DNI==Num_DNI)
        {
            Posicion=i;
            break;
        }
    }

    return Posicion;
}

void Imprimir_Lista(ePersona iPersona[],int Tam)
{
    ePersona Aux;

    for(int i=0;i<Tam;i++)
    {
        for(int j=0;j<Tam-1;j++)
        {
            if(strcmp(iPersona[j].Nombre,iPersona[j+1].Nombre)>0)
            {
                Aux=iPersona[j];
                iPersona[j]=iPersona[j+1];
                iPersona[j+1]=Aux;
            }
        }
    }

    for(int i=0;i<Tam;i++)
    {
        if(iPersona[i].Estado==1)
        {
            printf("\n\nNombre: %s",iPersona[i].Nombre);
            printf("\nEdad: %d",iPersona[i].Edad);
            printf("\nDNI: %d",iPersona[i].DNI);
        }
    }
    system("pause");
}

void Grafico_Edades(ePersona iPersona[],int Tam)
{
    int Columnas_Edad[3]={0,0,0};
    int max;
    max = 0;

    for(int i=0;i<Tam;i++)
    {
        if(iPersona[i].Estado==1)
        {
            if(iPersona[i].Edad<=18)
            {
                Columnas_Edad[0]++;
            }
            else if(iPersona[i].Edad>=19&&iPersona[i].Edad<=35)
            {
                Columnas_Edad[1]++;
            }
            else if(iPersona[i].Edad>=35)
            {
                Columnas_Edad[2]++;
            }
        }
    }

    for(int i=0;i<3;i++)
    {
        if(Columnas_Edad[i]>max)
        {
            max=Columnas_Edad[i];
        }
    }

    for (int i=max;i>0;i--)
    {
        for (int j = 0; j < 3; j++)
        {
            if(Columnas_Edad[j]>=i)
            {
                printf("\t *\t");
            }
            else
            printf("  ");
        }

        putchar('\n');
    }

    printf("\t<18\t19-35\t>35\n");

    system("pause");
}
