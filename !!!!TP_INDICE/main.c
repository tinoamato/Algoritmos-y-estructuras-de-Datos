#include "func.h"
#include "Lista.h"
#include "indice.h"




int main()
{
    t_indice ind;
    ind_crear(&ind, sizeof(long),compararT_datos);
    if(!ind_cargar(&ind, "socios.idx"))
    {
        leerTxt_CargarBin("socios.txt");
        ind_cargarBin(&ind, "socios.dat");
    }

    char accesoMenu;

    do
    {
        printf("\n------------------------------------------MENU------------------------------------------\n\n");
        printf("(A) Dar de alta a un nuevo socio\n");
        printf("(M) Modificar Nombre y Apeliido de un Socio\n");
        printf("(B) Dar de baja a un socio\n");
        printf("(L) Listar todos los socios dados de baja\n");
        printf("(V) Visualizar todos los socios dados de alta\n");
        printf("(P) Listar a los 10 socios con mayor retraso en la fecha de pago de la cuota\n");
        printf("(S) Salir\n");
        printf("\nIngrese una de las opciones del Menu:  ");
        scanf("%c", &accesoMenu);
        fflush(stdin);
        accesoMenu = toupper(accesoMenu);
        switch(accesoMenu)
        {
        case 'A':
            nuevoSocio(&ind,"socios.dat");
            break;
        case 'M':
            modificar_Nom_Apellido(&ind,"socios.dat");
            break;
        case 'B':
            darDeBaja(&ind,"socios.dat");
            break;
        case 'L':
            listar_socios_baja(&ind, "socios.dat");
            break;
        case 'V':
            listar_socios_alta(&(ind), "socios.dat");
            break;
        case 'P':
            listar_10_socios_mayor_retraso("socios.dat");
            break;
        case 'S':
            printf("\nSaliendo....\n\n");
            break;
        default :
            printf("\n LA LETRA QUE PUSO NO ES NINGUNA DE LAS OPCIONES DEL MENU\n\n");
        }
        fflush(stdin);
        printf("\n\nToque cualquier tecla para continuar\n");
        system("pause");
        system("cls");
    }
    while(accesoMenu != 'S');
    ind_grabar(&ind, "socios.idx");
    return 0;
}

