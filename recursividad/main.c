#include "funciones.h"

int main()
{
    int n=6;

    double fact;

    fact= rFactorial(n);

    printf("RES: %.0f",fact);

    int num1=81923432,num2=432334332;

    int res;
    res= mcd(num1,num2);

    printf("\nmcd: %d",res);
    ///--------------------------------------------//

    char* cadena="abcd";

    rDarVuelta(cadena);
    printf("\n-------");
    rDarVuelta2(cadena);
    printf("\n-------");
    rDarVuelta3(cadena);
        ///--------------------------------------------//
puts("\n");
        int numero=1234;

        rDarVueltaNum(numero);
        puts("\n-----------");
        rDarVueltaNum2(numero);




    return 0;
}
