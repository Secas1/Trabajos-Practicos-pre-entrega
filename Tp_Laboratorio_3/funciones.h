#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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

int MenuPrincipal();
void AgregarPelicula(ePelicula* p);
void GuardarPelicula(ePelicula* p);
ePelicula* BuscarPelicula(char* TituloPelicula);
ePelicula* ModificarPelicula();
void getString(char mensaje[],char input[]);
int getInt(char* mensaje);
char getChar(char* mensaje);
int getInt(char* mensaje);

#endif // FUNCIONES_H_INCLUDED
