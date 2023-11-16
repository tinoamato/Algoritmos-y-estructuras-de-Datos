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
//    listar_socios_baja(&ind, "socios.dat");
            break;
        case 'V':
//    mostrar_socios_Activos(&(ind), "socios.dat");
            break;
        case 'P':
//    listar_10_socios_mayor_retraso(&ind, "socios.dat");
            break;
        case 'S':
            printf("\nSaliendo....\n\n");
            break;
        default :
            printf("\n LA LETRA QUE PUSO NO ES NINGUNA DE LAS OPCIONES DEL MENU\n\n");
        }
        fflush(stdin);
        printf("Toque cualquier tecla para continuar\n");
        system("pause");
        system("cls");
    }
    while(accesoMenu != 'S');
//    ind_grabar(&ind, "socios.idx");
    return 0;
}
/*
    Que usemos primivitvas de lista dentro de las prmitivas de indice haria que indice deje de ser generico? /// NO FALLA

    La forma de lectura en el trozado de las Tfechas es valida o no serviria? /// NO FALLA

    La lista dentro de t_inidice debe ser una lista o un puntero a lista?

    En insertar_indice estaria mal usar reg_indice ya que el usuario tiene acceso a el y no lo pide?

    Porque tira ese warning en la funcion de comparacion? (solucion con long long pero no deberia funcionar)

    Preguntar porque cuando guarda la clave y lo casteamos a long aparece con un nuermo mas del Nro_socio

    Preguntar que hace con el const en el caso de buscar ya que deberia devolver sobre el indice pero no podemos editarlo

    Preguntar que hace el unsigned en la funcion accion que pasamos por parametro en ind_Recorrer

    Preguntar lo de ind_Buscar (esta la pregunta en la implementacion)

    Preguntar si en recorrer_lista no deberia haber una flag para salir del while si no se pudo hacer la accion

    En la funcion (A) lo que se fija es el dni o el nro_socio?

    Mirar duda en IND_CARGAR

*/
