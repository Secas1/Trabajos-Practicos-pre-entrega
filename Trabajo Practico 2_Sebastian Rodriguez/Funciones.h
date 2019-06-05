#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANT_NOMBRE 50

typedef struct
{
    char Nombre[CANT_NOMBRE];
    int Edad;
    int DNI;
    int Estado;
}ePersona;

int Menu_Inicial();
void Inicializar_Estado(ePersona [],int Tam);
void Agregar_Persona(ePersona [],int Tam);
int Contador_Persona(ePersona [],int Tam);
int Verificar_Nombre(char A[],int Tam_Nombre);
int Verificar_DNI(int ,ePersona [],int Tam);
void Borrar_Persona(ePersona [],int Tam);
int Buscar_DNI(int Num_DNI,ePersona [],int Tam);
void Imprimir_Lista(ePersona [],int Tam);
void Grafico_Edades(ePersona [],int Tam);


#endif // FUNCIONES_H_INCLUDED
