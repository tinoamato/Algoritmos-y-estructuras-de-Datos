#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "indice.h"
#include "Lista.h"

#define TAMNOMBRE 61
#define TAMCATEGORIA 11
typedef struct
{
    int aa;
    int mm;
    int dd;
} t_fecha;

typedef struct
{
    long nroSocio;
    char apyn[TAMNOMBRE];
    long dni;
    t_fecha fecha_Nac;
    char sexo;
    t_fecha fecha_Afil;
    char categoria[TAMCATEGORIA];
    t_fecha fecha_Ultimo_Cuota_Paga;
    char estado;
    t_fecha fecha_De_Baja;
} t_Socio;




///FUNCIONES ARCHIVO
void trozado(char *linea, t_Socio *dato); ///PREGUNTAR SI TIENE QUE SER VOID * EL DATO
///BAJAR EL TXT A UNA LISTA ORDENADA Y CARGARLO AL BIN (PARA AGILIZAR CARGAR INDICE)
void leerTxt_CargarBin(char *rutaTxt); ///ADENTRO PONER LA DIRECCION DEL BIN
void grabarArch(const void *dato, unsigned tamDato, void *arch);
int ind_cargarBin(t_indice* ind, const char* path);

///FUNCIONES DE MENU
int nuevoSocio(t_indice *ind, char *rutaBin); ///RUTINA (A)
int modificar_Nom_Apellido(t_indice *ind, char *rutaBin); ///RUTINA (M)
int darDeBaja(t_indice *ind, char *rutaBin); ///RUTINA (B)
int listar_socios_baja(t_indice *ind, char *rutaBin);///RUTINA (L)
int listar_socios_alta(t_indice *ind, char *rutaBin);///RUTINA(V)
int listar_10_socios_mayor_retraso(char *rutaBin); ///RUTINA (P)

///FUNCIONES NECESARIAS
int compararT_datos(const void*, const void*);
int comp_mayor_retraso(const void* dato,const void* dato_lista);
void mostrar_Si_Baja(const void* dato, unsigned tam_RegIndice, void *arch);
void mostrar_Si_Alta(const void* dato, unsigned tam_RegIndice, void *arch);
void mostrar_Todos(const void* dato, unsigned tam_RegIndice, void *arch);
void mostrarSocio(t_Socio *socio);
int esCadena(const char* cad);
int esFechaValida(const t_fecha* fec);
int buscarCategoria(const char vec[][10] ,int ce, const char* cat);

#endif // FUNC_H_INCLUDED
