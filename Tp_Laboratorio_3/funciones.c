#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/** \brief Menu Principal
 *
 *
 *
 * \return Regresa la opcion elegida del menu
 *
 */

int MenuPrincipal()
{
    int* pOpcion;

    pOpcion = (int*) malloc (sizeof(int));

    if(pOpcion==NULL)
    {
        printf("\nError al reservar memoria.Se vuelve al menu principal.\n");
    }

    printf("\tMENU PRINCIPAL\n");
    printf("1-Agregar Pelicula\n");
    printf("2-Borrar Pelicula\n");
    printf("3-Modificar Pelicula\n");
    printf("4-Generar Pagina Web\n");
    printf("5-Salir\n");
    printf("Opcion a elegir: ");
    fflush(stdin);
    scanf("%d",&pOpcion);

    return pOpcion;

    free(pOpcion);
}

/** \brief Modifica desde el archivo la pelicula
 *
 *
 *
 * \return Regresa el puntero de la estructura modificada
 *
 */

ePelicula* ModificarPelicula()
{
    int salirMod=0;
    ePelicula* pEncontrada;

    char TituloBuscar[50];
    getString("Titulo de la pelicula: ",TituloBuscar);
    pEncontrada = BuscarPelicula(TituloBuscar);
    if(pEncontrada!=NULL)
    {
        printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n",pEncontrada->Titulo,pEncontrada->Genero,pEncontrada->Duracion,pEncontrada->Descripcion,pEncontrada->Puntaje,pEncontrada->LinkImagen);
    }
    else
    {
        printf("El titulo ingresado no esta en el archivo");
    }
    do
    {
        switch(MenuModificar())
        {
            case 1:
            getString("Titulo: ",pEncontrada->Titulo);
            break;
            case 2:
            getString("Genero: ",pEncontrada->Genero);
            break;
            case 3:
            pEncontrada->Duracion=getInt("Duracion: ");
            break;
            case 4:
            getString("Descripcion",pEncontrada->Descripcion);
            break;
            case 5:
            pEncontrada->Puntaje=getInt("Puntaje");
            break;
            case 6:
            getString("Link de imagen: ",pEncontrada->LinkImagen);
            break;
            case 7:
            salirMod=1;
            break;
            default:
            printf("Opcion Invalida");
            break;
        }
    }while(salirMod==0);

    return pEncontrada;
}

/** \brief Menu de opciones a modificar
 *
 *
 *
 * \return Regresa la opcion elegida
 *
 */

int MenuModificar()
{
    int Opcion;

    printf("\tMENU MODIFICAR\n");
    printf("1-Titulo\n");
    printf("2-Genero\n");
    printf("3-Duracion\n");
    printf("4-Descripcion\n");
    printf("5-Puntaje\n");
    printf("6-Link de Imagen\n");
    printf("7-Salir\n");

    Opcion=getInt("Opcion a elegigr: ");

    return Opcion;
}

/** \brief Guarda los datos ingresados en un puntero de estructura
 *
 * \param Puntero de la estructura
 *
 * \return void
 *
 */

void AgregarPelicula(ePelicula* p)
{
    getString("Titulo: ",p->Titulo);
    getString("Genero: ",p->Genero);
    p->Duracion=getInt("Duracion: ");
    getString("Descripcion: ",p->Descripcion);
    p->Puntaje=getInt("Puntaje: ");
    getString("Link de Imagen: ",p->LinkImagen);
    p->Estado=1;
}

/** \brief Guarda en archivo la estructura
 *
 * \param Puntero a estructura
 *
 * \return void
 *
 */

void GuardarPelicula(ePelicula* p)
{
    FILE* pFile;
    pFile = fopen("DatosPeliculas.bin","ab");

    if(pFile==NULL)
    {
        printf("\nError al abrir el archivo\n");
    }

    fwrite(p,sizeof(ePelicula),1,pFile);

    fclose(pFile);
}

/** \brief Busca la pelicula segun el titulo ingresado
 *
 *
 * \param Titulo de la pelicula
 * \return Regresa un puntero de estructura con la informacion desde el archivo
 *
 */

ePelicula* BuscarPelicula(char* TituloPelicula)
{
    FILE* pFile;
    int flagFound=0;

    pFile = fopen("DatosPeliculas.bin","rb");

    if(pFile==NULL)
    {
        printf("\nError al abrir el archivo\n");
    }
    else
    {
        ePelicula* pPelicula = (ePelicula*) malloc(sizeof(ePelicula));


        while(fread(pPelicula,sizeof(ePelicula),1,pFile)!=0)
        {
            if(strcmp(TituloPelicula,pPelicula->Titulo)==0&&pPelicula->Estado==1)
            {
                flagFound=1;
                break;
            }
        }

        if(flagFound)
        {
            return pPelicula;
        }
        else
        {
            return NULL;
        }
        fclose(pFile);
    }
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    auxiliar=tolower(auxiliar);
    return auxiliar;
}


