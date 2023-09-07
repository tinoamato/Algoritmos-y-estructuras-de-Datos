#include "funciones.h"


int main()
{
    FILE* pf,*pMayor,*pMenor;
    tPedido pedido;
    tPedido sacado;
    int cod_aux;
    float total;
    int r;

    t_cola pc;

    crear_lote(ARCH);
    crear_cola(&pc);

    pMayor = fopen("pedidos_de_mas_de_100","wb");
    pMenor = fopen("pedidos_de_menos_de_100","wb");

    pf = fopen(ARCH,"rb");
    if(!pf || !pMenor || !pMayor)
    {
        printf("\nError al abrir algun archivo...");
        exit(1);
    }

    fread(&pedido,sizeof(tPedido),1,pf);


    while(!feof(pf))
    {
        cod_aux = pedido.nro_pedido;
        total = 0;
        while(pedido.nro_pedido == cod_aux && !feof(pf))
        {
            poner_en_cola(&pc,&pedido,sizeof(pedido));

            total+=(pedido.precio*pedido.cant);
            fread(&pedido,sizeof(tPedido),1,pf);

        }
        if(total>=100)
        {
            r = sacar_de_cola(&pc,&sacado,sizeof(sacado));
            while(r)
            {
                fwrite(&sacado,sizeof(tPedido),1,pMayor);
                r = sacar_de_cola(&pc,&sacado,sizeof(sacado));
            }

        }
        else
        {
            r = sacar_de_cola(&pc,&sacado,sizeof(sacado));
            while(r)
            {
                fwrite(&sacado,sizeof(tPedido),1,pMenor);
                r = sacar_de_cola(&pc,&sacado,sizeof(sacado));
            }

        }



    }

fclose(pMayor);
fclose(pMenor);

///MOSTRAR ARCHIVOS
puts("\nPEDIDOS DE MAS DE $100\n\n");
mostrar_archivo("pedidos_de_mas_de_100");
puts("\nPEDIDOS DE MENOS DE $100\n\n");
mostrar_archivo("pedidos_de_menos_de_100");





    fclose(pf);


    return 0;
}
