#include "func.h"
void crear_pila(Pila *pp)
{
    *pp=NULL;
}

int apilar(Pila *pp, const void* elem, size_t tamElem)
{
    Nodo *nue=malloc(sizeof(Nodo));
    void *elemNodo =malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return 0;
    }

    nue->elem= elemNodo;
    nue->tamElem= tamElem;
    memcpy(elemNodo,elem,tamElem);



    nue->sig=*pp; // 1
    *pp=nue; //2

    return 1;
}



int desapilar(Pila *pp, void* elem, size_t tamElem)
{
      if(!*pp)
        return 0;

    Nodo *nae=*pp;
    *pp=nae->sig;

    memcpy(elem,nae->elem,MIN(tamElem,nae->tamElem));
    free(nae->elem);
    free(nae);

    return 1;
}


void calculadora(char *nomArch)
{
    char aux,num1,num2;
    int carry=0,res;
    FILE *pf;
    int dato_sacado, flag1,flag2;

    pf=fopen(nomArch,"r");

    Pila pila1,pila2,resultado;


    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&resultado);


    fscanf(pf,"%c",&aux);
    while(aux!='\n')
    {
        if(aux >= '0' && aux<='9')
        {

            apilar(&pila1,&aux,sizeof(char));    // CARGO PILA 1 DEL TXT
        }
        fscanf(pf,"%c",&aux);

    }

    fscanf(pf,"%c",&aux);
    while(aux!='\n')
    {
        if(aux >= '0' && aux<='9')
        {

            apilar(&pila2,&aux,sizeof(char));    // CARGO PILA 1 DEL TXT
        }
        fscanf(pf,"%c",&aux);

    }

fclose(pf);


    flag1=desapilar(&pila1,&num1,sizeof(num1));     // FLAG 1 AVISA SI SE TERMINO LA PILA
    flag2=desapilar(&pila2,&num2,sizeof(num2));

    while(flag1 || flag2)
    {
         if(!flag1)
         {
             num1='0';
         }
         if(!flag2)
         {
             num2='0';
         }
            res=(num1-'0')+(num2-'0')+carry;
            if(res>=10)
            {
                res-=10;
                carry=1;
            }
            else
            {
                carry =0;
            }
    apilar(&resultado,&res,sizeof(res));
    flag1=desapilar(&pila1,&num1,sizeof(num1));
    flag2=desapilar(&pila2,&num2,sizeof(num2));
    }
    if(carry!=0)
    {
        res+=1;
        if(res>=10)
            {
                res-=10;
                carry=1;
            }
        apilar(&resultado,&res,sizeof(int));
    }



pf=fopen(nomArch,"a");
if(carry!=0)
{
    apilar(&resultado,&carry,sizeof(int));
}

while(desapilar(&resultado,&dato_sacado,sizeof(int)))
{
    fprintf(pf,"%d",dato_sacado);
}


    fclose(pf);
}

void crearLotePrueba(char* nomArch)
{
    FILE *pf=fopen(nomArch,"w");

    fputs("99922228111133333038\n", pf);
    fputs("444432222222222222222222\n", pf);

    fclose(pf);
}

int verTopeDePila(const Pila* pp, void* elem)
{
    if(!*pp)
        return 0;
    Nodo *tope=*pp;
    memcpy(elem,tope->elem,tope->tamElem);
    return 1;
}

int pilaVacia(const Pila* pp)
{
    if(!*pp)
        return 1;
    else return 0;
}

int pilaLlena(const Pila* pp, size_t tamElem);


