#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
    char nomYAp [30];
    int pos;
}t_resultado;


int compChar(const void*a,const void* b);
int compInt(const void*a,const void*b);
void intercambio (const void*a,const void*b, int tam);
void mostrar_tResultado(t_resultado *vec,int ce);
void* buscarMenor(void*vec,int ce, int tam, int cmp(const void*,const void*));
void ordenar_generico(void*vec,int ce, int tam, int cmp(const void*,const void*));





#endif // FUNCIONES_H_INCLUDED
