#include "funciones.h"

int compInt(const void*a,const void*b)
{
    t_resultado* auxA = (t_resultado*)a;
    t_resultado* auxB = (t_resultado*)b;

    return auxA->pos - auxB->pos;

}
int compChar(const void*a, const void* b)
{
    t_resultado* auxA = (t_resultado*)a;
    t_resultado* auxB = (t_resultado*)b;

    return strcmp(auxA->nomYAp,auxB->nomYAp);
}
void intercambio (const void*a, const void*b, int tam)
{
    char aux;
    int i;
    for (i=0;i<tam;i++)
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
        a++;
        b++;
    }

}
void* buscarMenor(void*vec,int ce, int tam, int cmp(const void*,const void*))
{
    void *menor;
    int i;

    menor = vec;
    vec+=tam;

    for(i=0;i<ce-1;i++)
    {
        if(cmp(vec,menor)<0)
        {
            menor = vec;
        }
        vec+=tam;
    }
    return menor;
}

void ordenar_generico(void*vec,int ce, int tam, int cmp(const void*,const void*))
{
    void*menor;
    int i;
    int ceaux =ce;

    for(i=0;i<ce;i++)
    {
        menor = buscarMenor(vec,ceaux,tam,cmp);
        if(menor!=vec)
        {
            intercambio(menor,vec,tam);
        }
        ceaux--;
        vec+=tam;
    }
}
void mostrar_tResultado(t_resultado *vec,int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        printf("Nombre:%s\tPuesto:%d\n",vec->nomYAp,vec->pos);
        vec++;
    }
}

///----------------------------------------------------------------------------------------------------///

void intercambiar(const void* a, const void*b,size_t tam)
{
    char aux;
    int i;
    char*  arg1 = (char*)a;
    char * arg2 = (char*)b;

    for(i=0;i<tam;i++)
    {
        aux = *arg1;
        *arg1 = *arg2;
        *arg2 = aux;

        arg1++;
        arg2++;
    }

}
void intercambiar_din( void* a,  void*b,size_t tam)
{
    void* aux = malloc(tam);
    if(!aux)
        return;
    memcpy(aux,a,tam);
    memcpy(a,b,tam);
    memcpy(b,aux,tam);
    free(aux);
}
void* buscarMen(void*vec,void*fin,size_t tam,int (*cmp)(const void*,const void*))
{
    void *menor = vec;
    vec+=tam;

    while(vec<=fin)
    {
        if(cmp(vec,menor)<0)
        {
            menor = vec;
        }
        vec+=tam;
    }
    return menor;
}

void ordenamiento_seleccion(void*vec,size_t ce, size_t tam, int cmp(const void*,const void*))
{
    void* fin = vec+(ce-1)*tam;
    void* menor;
    while(vec<fin)
    {
        ///(fin-vec)/tam -------> ce


        menor = buscarMen(vec,fin,tam,cmp);

        if(menor!=vec)
        {
            intercambiar(vec,menor,tam);
        }
        vec+=tam;
    }
}
