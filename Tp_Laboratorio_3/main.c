#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Titulo[30];
    char Genero[30];
    int Duracion;
    char Descripcion[50];
    int Puntaje;
    char LinkImagen[100];
    int Estado;
}ePelicula;



int main()
{
    ePelicula* pPelicula;
    char TituloEncontrar[50];
    char ConfirmarBorrar;
    ePelicula* pEncontrada;
    char out ='s';
    int salir=0;


    do
    {
        switch(MenuPrincipal())
        {
            case 1:
            do
            {
                AgregarPelicula(&pPelicula);
                GuardarPelicula(&pPelicula);
                out=getChar("Agregar mas peliculas? s/n: ");
            }while(out=='s');
            break;

            case 2:
            getString("Titulo de la pelicula: ",TituloEncontrar);
            pEncontrada = BuscarPelicula(TituloEncontrar);

            if(pEncontrada!=NULL)
            {
                printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n",pEncontrada->Titulo,pEncontrada->Genero,pEncontrada->Duracion,pEncontrada->Descripcion,pEncontrada->Puntaje,pEncontrada->LinkImagen);
                ConfirmarBorrar=getChar("Borrar? s/n: ");

                if(ConfirmarBorrar='s')
                {
                    pEncontrada->Estado=0;
                    GuardarPelicula(&pEncontrada);

                }
            }
            else
            {
                printf("El titulo ingresado no esta en el archivo");
            }
            break;

            case 3:
            pPelicula=ModificarPelicula();
            GuardarPelicula(&pPelicula);
            break;
            case 5:
            salir=1;
            break;
        }
        system("pause");
        system("cls");
    }while(salir==0);
    return 0;
}

