#include "arbol_bin.h"
#include <time.h>

int main()
{
    int vec[]={6,9,13,14,15,17,20,26,64,72};
    int *v = vec;
    t_arbol arbol;


    crear_arbol(&arbol);

    cargar_arbol_vec(&arbol,v,10,sizeof(int));




    /*for(int i=0;i<10;i++)
    {

      num = vec[i];
    r_insertar_en_arbol(&arbol,&num,sizeof(int),compINT);

    }
*/
    int cant = contar_nodos(&arbol);
    printf("\nCANT NODOS %d\n",cant);

    cant = contar_nodos_hasta_nivel(&arbol,1);

    printf("\nCANT NODOS HASTA NIVEL 1 %d\n",cant);
    recorrer_arbol_en_orden(&arbol,printear,0);
    puts("\n");
    recorrer_arbol_pre_orden(&arbol,printear,0);
    puts("\n");
    recorrer_arbol_pos_orden(&arbol,printear,0);

    podar_hasta_nivel(&arbol,2);
    /// int h = altura_arbol(&arbol);
    puts("\nNUEVOS");
    recorrer_arbol_en_orden(&arbol,printear,0);
    puts("\n");
    recorrer_arbol_pre_orden(&arbol,printear,0);
    puts("\n");
    recorrer_arbol_pos_orden(&arbol,printear,0);

     cant = contar_nodos(&arbol);
    printf("\nCANT NODOS %d",cant);
    puts("\nARBOL VACIO\n");
    vaciar_arbol(&arbol);
    cant = contar_nodos(&arbol);
    printf("\nCANT NODOS %d",cant);

    return 0;
}
