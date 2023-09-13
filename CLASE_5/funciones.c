#include "funciones.h"
void crear_cola (t_cola *pc)
{
    pc->tam_disp = TAM_COLA;
    pc->fondo = pc->frente = 0;
}
int poner_en_cola(t_cola *pc,const void* pd, size_t tam)
{
    int ini, fin;
    if(pc->tam_disp < sizeof(size_t)+tam) ///Entra en el vector
        return 0; ///cola llena


    ///copia tam dato
    if((ini =( MENOR(TAM_COLA - pc->fondo,sizeof(size_t))))) //ini!=0 donde entra cada parte
    {
        memcpy(pc->vec + pc->fondo,&tam,ini);
    }
    if((fin = (sizeof(size_t)-ini)))
    {
        memcpy(pc->vec,((char*)&tam)+ini,fin);
    }
    pc->fondo = fin ? fin : pc->fondo+ini;

    ///copia dato
    if((ini =( MENOR(TAM_COLA - pc->fondo,tam))))
        memcpy(pc->vec + pc->fondo,pd,ini);

    if((fin = tam-ini))
        memcpy(pc->vec,((const char*) pd)+ini,fin);

    pc->fondo = fin ? fin:pc->fondo+ini;
    ///

    memcpy(pc->vec + pc->fondo, &tam,sizeof(size_t));
    pc->fondo += sizeof(size_t);

    memcpy(pc->vec + pc->fondo,&pd,tam);
    pc->fondo+= tam;

    pc->tam_disp -= sizeof(size_t)+tam;

    return 1;

}

int sacar_de_cola(t_cola* pc,void*pd,size_t tam)
{
    int tam_dato_cola,ini,fin;

    /////////////////////////////////////////////////////
    if(pc->tam_disp == TAM_COLA)
        return 0; ///cola vacia

    if((ini = MENOR(TAM_COLA - pc->frente,sizeof(size_t))))
        memcpy(&tam_dato_cola,pc->vec+pc->frente,ini);
    if((fin = sizeof(size_t)-ini))
        memcpy(((char*)&tam_dato_cola)+ini,pc->vec,fin);

    pc->frente = fin ? fin : pc->frente+sizeof(size_t);

    /////////////////////////////////////////////////////
    if((ini = MENOR(TAM_COLA-pc->frente,tam_dato_cola)))
        memcpy(pd,pc->vec+pc->frente,MENOR(ini,tam));
    if((fin = tam_dato_cola - ini) && tam>ini)
        memcpy(((char*)pd)+ini,pc->vec,MENOR(tam-ini,fin));

    pc->frente = fin ? fin: pc->frente+tam_dato_cola;

    pc->tam_disp+=sizeof(size_t)+tam_dato_cola;

    return 1;
    /////////////////////////////////////////////////////
}
int cola_llena(t_cola *pc, size_t tam)
{
    if(pc->tam_disp < sizeof(size_t)+tam)
        return 0;
    return 1;

}
int cola_vacia(t_cola *pc)
{
    if(pc->tam_disp != TAM_COLA)
        return 0;
    return 1;
}
int frente_de_cola(const t_cola* pc, void* elem,size_t tam)
{
    int tam_dato_cola, ini,fin;
    if(pc->tam_disp ==TAM_COLA)
        return 0;

    memcpy(pc->frente+sizeof(size_t),&elem,)



}
