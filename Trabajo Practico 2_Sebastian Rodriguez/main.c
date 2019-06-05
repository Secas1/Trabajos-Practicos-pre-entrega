#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

#define CANT 5


int main()
{
    ePersona iPersona[CANT];

    int Salir=0;

    Inicializar_Estado(iPersona,CANT);

    do
    {
        system("cls");

        switch(Menu_Inicial())
        {
            case 1:
            Agregar_Persona(iPersona,CANT);
            break;

            case 2:
            Borrar_Persona(iPersona,CANT);
            break;

            case 3:
            Imprimir_Lista(iPersona,CANT);
            break;

            case 4:
            printf("\n\n");
            Grafico_Edades(iPersona,CANT);
            break;

            case 5:
            Salir=1;
            break;

            default:
            printf("\nOpcion invalida\n");
            system("pause");
            break;
        }
    }while(Salir==0);

    return 0;
}

