#include "funciones.h"

void crear_cola (t_cola* pc)
{
    pc->pri = pc->ult =NULL;
}
int poner_en_cola(t_cola* pc,const void* pd, size_t tam)
{
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));

    if(!nue)
        return 0; //cola llena FALSE
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return  0;//cola llena
    }

    nue->tam = tam;
    memcpy(nue->info,pd,tam);
    nue->sig = NULL;

    if(pc->ult)
        pc->ult->sig = nue;
    else
        pc->pri = nue;
    pc->ult = nue;

    return 1;
}

int sacar_de_cola (t_cola* pc, void* pd,size_t tam)
{
    t_nodo* elim = pc->pri;

    if (!pc->pri)
    {
        return 0;//cola vacia
    }

    memcpy(pd,elim->info,MENOR(tam,elim->tam));

    pc->pri = elim->sig;

    if(!pc->pri)
        pc->ult =NULL;
    free(elim->info);
    free(elim);

    return 1;

}

void crear_lote(const char* nomArch)
{
    FILE* pf;
    tPedido pedidos[7] = {{01,"a",10,6},{01,"b",2,5},{02,"c",50,20},{03,"a",10,10},{04,"d",100,50},{04,"e",50,2},{04,"f",20,5}};

    pf = fopen(nomArch,"wb");
    if(!pf)
    {
        printf("\nError al crear el archivo...\n");
        exit(1);
    }
    fwrite(&pedidos,sizeof(pedidos),1,pf);
    fclose(pf);
}
void mostrar_archivo(const char* nomArch)
{
    tPedido ped;
    FILE *pf = fopen(nomArch,"rb");
    if(!pf)
    {
        printf("\nError al abrir el archivo\n");
        exit(2);
    }



    fread(&ped,sizeof(tPedido),1,pf);
    while(!feof(pf))
    {
        printf("\n%d - %s - %d - %f",ped.nro_pedido,ped.cod_prod,ped.cant,ped.precio);
        fread(&ped,sizeof(tPedido),1,pf);
    }

    fclose(pf);

}

