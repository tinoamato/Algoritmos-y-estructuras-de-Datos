#include "funciones.h"

typedef struct
{
    //int n1;
    char b;
    int n2;


   // double a;

}t_dato;


int main()
{
    printf("struct: %d  ",sizeof(t_dato));
    printf("%d ",sizeof(int));
    printf("%d ",sizeof(double));
    printf("%d",sizeof(char));


    puts("\n---------");
     printf("%d ",sizeof(void*));
    printf("%d ",sizeof(size_t));
    printf("%d",sizeof( struct s_nodo*));
    printf ("\ntotal: %d ",sizeof(t_nodo));
    return 0;
}
