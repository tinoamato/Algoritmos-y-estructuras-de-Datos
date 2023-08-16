///CLASE 1

/// # son instrucciones al pre-procesador, copia el archivo.h
/// #ifndef MATE_H_INCLUDED
/// #define MATE_H_INCLUDED
/// #endif //MATE_H_INCLUDED




#include "funciones.h"

int main()
{


    t_resultado vec[]={{"HL",4},{"SM",2},{"JB",5},{"PB",3},{"JM",1},{"IU",6}};

    mostrar_tResultado(vec,6);
    puts("\n\n\n");
    //qsort(vec,6,sizeof(t_resultado),&compChar);
    //  mostrar_tResultado(vec,6);
   ordenar_generico(vec,6,sizeof(t_resultado),compInt);
   mostrar_tResultado(vec,6);



    return 0;
}

