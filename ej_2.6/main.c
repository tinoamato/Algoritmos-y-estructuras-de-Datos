#include "funciones.h"
///Ordenar una sucesion de numeros brindadas por un archivo utilizando 'pilas'.
int main()
{
    t_producto prod,aux1,aux2,desap;
    t_pila pila1,pila2;
    FILE*pf;

    ///CREACION---------------///
    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_lote(ARCH);

    pf = fopen(ARCH,"rb");

    if(!pf)
    {
        printf("\nError al abrir el archivo...");
        exit(1);
    }

    while(fread(&prod,sizeof(t_producto),1,pf))
    {
        ///printf("\n%d--%c--%f",prod.cod,prod.sector,prod.precio);
        ver_tope_pila(&pila1,&aux1);
        ver_tope_pila(&pila2,&aux2);

        if(pila_vacia(&pila1) && pila_vacia(&pila2)) ///Si es el primer elemento
        {
            apilar(&pila1,&prod,sizeof(prod));
        }
        else if (aux1.cod > prod.cod)
        {
            if(pila_vacia(&pila2) || (aux2.cod < prod.cod))
            {
                apilar(&pila2,&prod,sizeof(prod));
            }
            else                             ///sacar de pila en bucle hasta que quede en orden
            {
                desapilar(&pila2,&desap,sizeof(desap));
                apilar(&pila1,&desap,sizeof(desap));

                ver_tope_pila(&pila2,&aux2);
                while(aux2.cod > prod.cod && !pila_vacia(&pila2))
                {
                    desapilar(&pila2,&desap,sizeof(desap));
                    apilar(&pila1,&desap,sizeof(desap));

                    ver_tope_pila(&pila2,&aux2);
                }
                apilar(&pila2,&prod,sizeof(prod));
            }
        }
        else
        {
            desapilar(&pila1,&desap,sizeof(desap));
            apilar(&pila2,&desap,sizeof(desap));

            ver_tope_pila(&pila1,&aux1);



            while(aux1.cod < prod.cod && !pila_vacia(&pila1))
                {
                    desapilar(&pila1,&desap,sizeof(desap));
                    apilar(&pila2,&desap,sizeof(desap));

                    ver_tope_pila(&pila1,&aux1);
                }
                apilar(&pila1,&prod,sizeof(prod));
        }

    }

    ///COMENTAR UNO U OTRO

    ///PARA MOSTRAR DE FORMA DECRECIENTE (1)
/*
    while(!pila_vacia(&pila1))      ///paso todo a pila2
    {
        desapilar(&pila1,&desap,sizeof(desap));
        apilar(&pila2,&desap,sizeof(desap));

    }

    while(!pila_vacia(&pila2))      ///muestro ordenado
    {
        desapilar(&pila2,&desap,sizeof(desap));
        printf("\n%d--%c--%f",desap.cod,desap.sector,desap.precio);

    }*/

    ///PARA MOSTRAR DE FORMA CRECIENTE (2)

    while(!pila_vacia(&pila2))      ///paso todo a pila1
    {
        desapilar(&pila2,&desap,sizeof(desap));
        apilar(&pila1,&desap,sizeof(desap));

    }

    while(!pila_vacia(&pila1))      ///muestro ordenado
    {
        desapilar(&pila1,&desap,sizeof(desap));
        printf("\n%d--%c--%f",desap.cod,desap.sector,desap.precio);

    }


    fclose(pf);
    return 0;
}
