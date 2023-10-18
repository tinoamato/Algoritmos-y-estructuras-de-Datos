#include "funciones.h"

double rFactorial(unsigned num)
{

    if(num <=1)
        return 1;

    return rFactorial(num-1)*num;

}
int mcd(int n,int m)
{
    if(!(n%m))
        return m;
    return mcd(m,(n%m));
}

char* rDarVuelta(char* cad)
{

    if(!*cad )
    {
        return;
    }
    rDarVuelta(cad+1);
    printf("\n%c",*(cad));
}
char* rDarVuelta2(char* cad)
{

    if(!*cad )
    {
        return;
    }
    printf("\n%c",*(cad));
    rDarVuelta2(cad+1);
    printf("\n%c",*(cad));
}
char* rDarVuelta3(char* cad)
{
    printf("\n%c",*(cad-1));
    if(!*cad)
    {
        return;
    }
    rDarVuelta3(cad+1);
    printf("\n%c",*(cad-1));
}
///-----------------------------------------------------------------///

void rDarVueltaNum (int n)
{

    if(!n)
        return;
    printf("%d",n%10);
     rDarVueltaNum(n/10);


}
int rDarVueltaNum2 (int n)
{

    if(n==0)
        return n;



    return rDarVueltaNum2(n/10);


}
void cad_ej5(char* cad)
{
    cad_ej5r(cad,0);
}
void cad_ej5r(char* cad,int esp)
{
    if(!*cad)
        return;
    if(!*(cad+1))
    {
        printf("%*s%c",esp,"");
        return;
    }
}



