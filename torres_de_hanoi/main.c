#include "funciones.h"
#define CANTANILLOS 3

int main()
{
    int num;
    int i;
    int anillos= CANTANILLOS;
    int mov_max;
    int pos=1;
    int aux;
    int tope1,tope2,tope3;
    int contmovimientos=0;
    int flag=0;

    pila pila1,pila2,pila3;

    mov_max = max_mov(anillos);
    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pila3);

    for(i=0; i<CANTANILLOS; i++)
    {
        apilar(&pila1,&anillos,sizeof(anillos));
        anillos--;
    }

    /*for(i=0;i<CANTANILLOS;i++)
    {
        desapilar(&pila1,&num,sizeof(num));
        printf("%d \n",num);
    }*/

    ///-----------------------------------------------///

    puts("\nINICIO\n");
    printf("\nMov %d",contmovimientos);
                puts("\nPILA 1---------");
                mostrarPilaEnteros(&pila1);
                puts("\nPILA 2---------");
                mostrarPilaEnteros(&pila2);
                puts("\nPILA3---------");
                mostrarPilaEnteros(&pila3);
            puts("\n\n");

    ver_tope_de_pila(&pila1,&tope1,sizeof(tope1));
    ver_tope_de_pila(&pila2,&tope2,sizeof(tope2));
    ver_tope_de_pila(&pila3,&tope3,sizeof(tope3));
    while(mov_max--)
    {
        if(flag==0) ///PRIMERA ENTRADA
        {
            //mover a la derecha
            desapilar(&pila1,&aux,sizeof(aux));
            apilar(&pila2,&aux,sizeof(aux));
            pos=2;

            //cambio topes
            ver_tope_de_pila(&pila1,&tope1,sizeof(tope1));
            ver_tope_de_pila(&pila2,&tope2,sizeof(tope2));

            contmovimientos++;
            flag=1;

            printf("\nMov %d",contmovimientos);
                puts("\nPILA 1---------");
                mostrarPilaEnteros(&pila1);
                puts("\nPILA 2---------");
                mostrarPilaEnteros(&pila2);
                puts("\nPILA3---------");
                mostrarPilaEnteros(&pila3);
        }
        if(pos==2)
        {
            if(!pila_vacia(&pila3) && ((tope1>tope3) || pila_vacia(&pila1)))
            {
                desapilar(&pila3,&aux,sizeof(aux));
                apilar(&pila1,&aux,sizeof(aux));

                ver_tope_de_pila(&pila1,&tope1,sizeof(tope1));
                ver_tope_de_pila(&pila3,&tope3,sizeof(tope3));
                pos=1;

                contmovimientos++;

                printf("\nMov %d",contmovimientos);
                puts("\nPILA 1---------");
                mostrarPilaEnteros(&pila1);
                puts("\nPILA 2---------");
                mostrarPilaEnteros(&pila2);
                puts("\nPILA3---------");
                mostrarPilaEnteros(&pila3);


            }
            else if(!pila_vacia(&pila3) && ((tope2>tope3) || pila_vacia(&pila2)))
            {
                desapilar(&pila3,&aux,sizeof(aux));
                apilar(&pila2,&aux,sizeof(aux));

                ver_tope_de_pila(&pila2,&tope2,sizeof(tope2));
                ver_tope_de_pila(&pila3,&tope3,sizeof(tope3));
                pos=2;

                contmovimientos++;
                printf("\nMov %d",contmovimientos);
                puts("\nPILA 1---------");
                mostrarPilaEnteros(&pila1);
                puts("\nPILA 2---------");
                mostrarPilaEnteros(&pila2);
                puts("\nPILA3---------");
                mostrarPilaEnteros(&pila3);
            }
            else
            {
                pos=3;
            }


        }
        if(pos==3)
        {
            if(!pila_vacia(&pila1) && ((tope2>tope1) ||  pila_vacia(&pila2)))
            {
                desapilar(&pila1,&aux,sizeof(aux));
                apilar(&pila2,&aux,sizeof(aux));

                ver_tope_de_pila(&pila1,&tope1,sizeof(tope1));
                ver_tope_de_pila(&pila2,&tope2,sizeof(tope2));
                pos=2;

                contmovimientos++;
                printf("\nMov %d",contmovimientos);
                puts("\nPILA 1---------");
                mostrarPilaEnteros(&pila1);
                puts("\nPILA 2---------");
                mostrarPilaEnteros(&pila2);
                puts("\nPILA3---------");
                mostrarPilaEnteros(&pila3);
            }
            else if(!pila_vacia(&pila1) && ((tope3>tope1) || pila_vacia(&pila3)))
            {
                desapilar(&pila1,&aux,sizeof(aux));
                apilar(&pila3,&aux,sizeof(aux));

                ver_tope_de_pila(&pila1,&tope1,sizeof(tope1));
                ver_tope_de_pila(&pila3,&tope3,sizeof(tope3));
                pos=3;

                contmovimientos++;
                printf("\nMov %d",contmovimientos);
                puts("\nPILA 1---------");
                mostrarPilaEnteros(&pila1);
                puts("\nPILA 2---------");
                mostrarPilaEnteros(&pila2);
                puts("\nPILA3---------");
                mostrarPilaEnteros(&pila3);
            }
            else
                pos=1;


        }
        if(pos==1)
        {
            if(!pila_vacia(&pila2) && ((tope3>tope2) ||  pila_vacia(&pila3)))
            {
                desapilar(&pila2,&aux,sizeof(aux));
                apilar(&pila3,&aux,sizeof(aux));

                ver_tope_de_pila(&pila3,&tope3,sizeof(tope3));
                ver_tope_de_pila(&pila2,&tope2,sizeof(tope2));
                pos=3;

                contmovimientos++;
               printf("\nMov %d",contmovimientos);
                puts("\nPILA 1---------");
                mostrarPilaEnteros(&pila1);
                puts("\nPILA 2---------");
                mostrarPilaEnteros(&pila2);
                puts("\nPILA3---------");
                mostrarPilaEnteros(&pila3);

            }
            else if(!pila_vacia(&pila2) && ((tope1>tope2) || pila_vacia(&pila1)))
            {
                desapilar(&pila2,&aux,sizeof(aux));
                apilar(&pila1,&aux,sizeof(aux));

                ver_tope_de_pila(&pila1,&tope1,sizeof(tope1));
                ver_tope_de_pila(&pila2,&tope2,sizeof(tope2));
                pos=1;

                contmovimientos++;
                printf("\nMov %d",contmovimientos);
                puts("\nPILA 1---------");
                mostrarPilaEnteros(&pila1);
                puts("\nPILA 2---------");
                mostrarPilaEnteros(&pila2);
                puts("\nPILA3---------");
                mostrarPilaEnteros(&pila3);
            }
            else
                pos=2;

        }



    }

    ///MOSTRAR FINAL
    puts("\n\n--------FINAL--------\n\n");

    if(!pila_vacia(&pila3))
    {

        for(i=0; i<CANTANILLOS; i++)
        {
            desapilar(&pila3,&num,sizeof(num));
            printf("NULL NULL %d \n",num);
        }

    }
    else if(!pila_vacia(&pila2))
    {
        for(i=0; i<CANTANILLOS; i++)
        {
            desapilar(&pila2,&num,sizeof(num));
            printf("NULL %d NULL\n",num);
        }
    }


    printf("\nCANTIDAD TOTAL DE MOVIMIENTOS EFECTUADOS: %d",contmovimientos);



    return 0;
}
