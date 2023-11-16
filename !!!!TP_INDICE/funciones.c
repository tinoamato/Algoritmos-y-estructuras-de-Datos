#include "func.h"
#include "Lista.h"
#include "indice.h"

///FUNCIONES ARCHIVO
void trozado(char *linea, t_Socio *dato)
{
    char *aux = linea;
    ///FECHA DE BAJA
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    sscanf(aux+1,"%d-%d-%d",&(dato->fecha_De_Baja.aa),&(dato->fecha_De_Baja.mm),&(dato->fecha_De_Baja.dd));
    ///ESTADO
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    sscanf(aux+1,"%c", &(dato->estado));
    ///FECHA DE ULTIMA CUOTA PAGA
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    sscanf(aux+1,"%d-%d-%d",&(dato->fecha_Ultimo_Cuota_Paga.aa),&(dato->fecha_Ultimo_Cuota_Paga.mm),&(dato->fecha_Ultimo_Cuota_Paga.dd));
    ///CATEGORIA
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    strcpy(dato->categoria,aux+1);
    ///FECHA DE AFILIACION
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    sscanf(aux+1,"%d-%d-%d",&(dato->fecha_Afil.aa),&(dato->fecha_Afil.mm),&(dato->fecha_Afil.dd));
    ///SEXO
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    sscanf(aux+1,"%c",&(dato->sexo));
    ///FECHA DE NACIMIENTO
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    sscanf(aux+1,"%d-%d-%d",&(dato->fecha_Nac.aa),&(dato->fecha_Nac.mm),&(dato->fecha_Nac.dd));
    ///DNI
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    sscanf(aux+1,"%ld",&(dato->dni));
    ///APELLIDO Y NOMBRE
    aux = strrchr(linea, '|');
    if(!aux)
    {
        return;
    }
    *aux = '\0';
    strcpy(dato->apyn,aux+1);
    ///NRO SOCIO
    sscanf(linea,"%ld", &(dato->nroSocio));
}
void leerTxt_CargarBin(char *rutaTxt)
{
    FILE *pf, *pf2;
    char cad[1000];
    t_Socio aux;
    pf = fopen(rutaTxt, "rt");
    if(!pf)
    {
        return;
    }
    pf2 = fopen("socios.dat", "wb");
    if(!pf2)
    {
        fclose(pf);
        return;
    }
    while(fgets(cad, sizeof(cad)-1, pf))
    {
        trozado(cad, &aux);
        fwrite(&aux, sizeof(aux), 1, pf2);
    }
    fclose(pf);
    fclose(pf2);
    return;
}
void grabarArch(const void *dato, unsigned tamDato, void *arch)
{
    FILE *pf = (FILE*)arch;
    fwrite(dato, tamDato, 1, pf);
}

int ind_cargarBin(t_indice *ind, const char *ruta)
{
    FILE *pf;
    int estado = 1;
    unsigned nro_Reg = 0;
    t_Socio socio;
    pf = fopen(ruta,"rb");
    if(!pf)
    {
        return 0;
    }
    fread(&socio, sizeof(t_Socio), 1, pf);
    while(!feof(pf) && estado)  ///Tal vez estado no va
    {
        memcpy((ind->reg_indice), &nro_Reg, sizeof(unsigned)); ///Esto deberia hacerse en una funcion?
        memcpy((ind->reg_indice)+sizeof(unsigned), &(socio.nroSocio), sizeof(long)); ///Esto deberia hacerse en una funcion?
        estado = insertarEnOrdenLista(&(ind->lista), ind->tamClave+ sizeof(unsigned), (ind->reg_indice), ind->cmp);
        nro_Reg++;
        fread(&socio, sizeof(t_Socio), 1, pf);
    }
    fclose(pf);
    return estado;
}
///FUNCIONES DE MENU
int nuevoSocio(t_indice *ind, char *rutaBin)
{
    FILE *pf;
    t_Socio auxSocio;
    int resultado;
    unsigned nro_RegAux;
    pf = fopen(rutaBin,"r+b");
    if(!pf)
    {
        return 0;
    }
    printf("\nIngrese el NroSocio del Socio para dar de ALTA: ");
    scanf("%ld", &(auxSocio.nroSocio));
    fflush(stdin);
    resultado = ind_buscar(ind,&(auxSocio.nroSocio),&(nro_RegAux));
    if(resultado == 1)
    {
        fseek(pf,sizeof(t_Socio)*nro_RegAux,SEEK_SET);
        fread(&(auxSocio),sizeof(t_Socio),1,pf);
        if(auxSocio.estado == 'A')
        {
            printf("El socio ya existe y esta activo\n");
        }
        else
        {
            printf("El socio ya existe y su estado se cambio a Activo\n");
            auxSocio.estado = 'A';
            fseek(pf, (long)sizeof(t_Socio)*(-1),SEEK_CUR);
            auxSocio.fecha_De_Baja.aa = auxSocio.fecha_De_Baja.mm = auxSocio.fecha_De_Baja.dd = 0;
            fwrite(&auxSocio,sizeof(t_Socio),1,pf);
        }
    }
    else
    {
        puts("\nIngrese el Apellido y nombre del nuevo socio: ");
        fgets(auxSocio.apyn,TAMNOMBRE,stdin);

        fflush(stdin);

        puts("\nIngrese DNI del nuevo socio: ");
        scanf("%ld",&auxSocio.dni);

        puts("\nIngrese la fecha de nacimiento del nuevo socio \n");
        puts("\nAnio: ");
        scanf("%d",&auxSocio.fecha_Nac.aa);

        puts("\nMes: ");
        scanf("%d",&auxSocio.fecha_Nac.mm);

        puts("\nDia: ");
        scanf("%d",&auxSocio.fecha_Nac.dd);

        do
        {
            puts("\nIngrese sexo del nuevo socio ('F' u 'M' u 'O'): ");
            fflush(stdin);
            scanf("%c",&auxSocio.sexo);
            auxSocio.sexo=toupper(auxSocio.sexo);
        }
        while(auxSocio.sexo != 'M' && auxSocio.sexo != 'F' && auxSocio.sexo != 'O');

        puts("\nIngrese la fecha de afiliacion del nuevo socio ");

        puts("\nAnio: ");
        scanf("%d",&auxSocio.fecha_Afil.aa);

        puts("\nMes: ");
        scanf("%d",&auxSocio.fecha_Afil.mm);

        puts("\nDia: ");
        scanf("%d",&auxSocio.fecha_Afil.dd);

        puts("\nIngrese la categoria del nuevo socio: ");
        fflush(stdin);
        fgets(auxSocio.categoria,TAMNOMBRE,stdin);
        fflush(stdin);



        puts("\nIngrese la fecha de la ultima cuota paga del nuevo socio ");

        puts("\nAnio: ");
        scanf("%d",&auxSocio.fecha_Ultimo_Cuota_Paga.aa);

        puts("\nMes: ");
        scanf("%d",&auxSocio.fecha_Ultimo_Cuota_Paga.mm);

        puts("\nDia: ");
        scanf("%d",&auxSocio.fecha_Ultimo_Cuota_Paga.dd);

        auxSocio.estado='A';
        auxSocio.fecha_De_Baja.aa = auxSocio.fecha_De_Baja.mm = auxSocio.fecha_De_Baja.dd = 0;
        fseek(pf,0,SEEK_END);
        nro_RegAux = (ftell(pf)/sizeof(t_Socio))+1;
        ind_insertar(ind,&(auxSocio.nroSocio),nro_RegAux);
        fwrite(&auxSocio,sizeof(t_Socio),1,pf);
    }
    fclose(pf);
    return 1;
}
int modificar_Nom_Apellido(t_indice *ind, char *rutaBin)
{

    FILE *pf;
    t_Socio auxSocio;
    int resultado;
    unsigned nro_RegAux;
    pf = fopen(rutaBin,"r+b");
    if(!pf)
    {
        return 0;
    }
    printf("\nIngrese el NroSocio del Socio: ");
    scanf("%ld", &(auxSocio.nroSocio));
    //fflush(stdin);
    resultado = ind_buscar(ind,&(auxSocio.nroSocio),&(nro_RegAux));
    if(resultado == 1)
    {
        fseek(pf,sizeof(t_Socio)*nro_RegAux,SEEK_SET);
        fread(&(auxSocio),sizeof(t_Socio),1,pf);

        printf("\nIngrese el nombre modificado: ");
        fflush(stdin);
        fgets(auxSocio.apyn,TAMNOMBRE,stdin);


        fseek(pf, (long)sizeof(t_Socio)*(-1),SEEK_CUR);
        fwrite(&auxSocio,sizeof(t_Socio),1,pf);

        printf("\nSe modifico el nombre y apellido correctamente...\n");

    }
    else
    {
        printf("\nNo se encontro el socio...\n");
    }

    fclose(pf);
    return 1;

}
int darDeBaja(t_indice *ind, char *rutaBin) ///RUTINA (B)
{
    FILE *pf;
    t_Socio auxSocio;
    int resultado;
    unsigned nro_RegAux;
    pf = fopen(rutaBin,"r+b");
    if(!pf)
    {
        return 0;
    }
    printf("\nIngrese el NroSocio del Socio para dar de BAJA: ");
    scanf("%ld", &(auxSocio.nroSocio));
    fflush(stdin);
    resultado = ind_buscar(ind,&(auxSocio.nroSocio),&(nro_RegAux));
     if(resultado == 1)
    {
        fseek(pf,sizeof(t_Socio)*nro_RegAux,SEEK_SET);
        fread(&(auxSocio),sizeof(t_Socio),1,pf);
        if(auxSocio.estado == 'B') ///cambiar la B por I
        {
            printf("\n\nEl socio ya existe y esta Inactivo.\n");
        }
        else
        {

            auxSocio.estado = 'B';
            fseek(pf, (long)sizeof(t_Socio)*(-1),SEEK_CUR);

            printf("\nIngrese la fecha de baja ");

            printf("\nAnio: ");
            scanf("%d",&auxSocio.fecha_De_Baja.aa);
            printf("\nMes: ");
            scanf("%d",&auxSocio.fecha_De_Baja.mm);
            printf("\nDia: ");
            scanf("%d",&auxSocio.fecha_De_Baja.dd);



            fwrite(&auxSocio,sizeof(t_Socio),1,pf);
            printf("\nSe modifico su estado a Inactivo\n\n");
        }
    }
    else
    {
        printf("\nNo existe el socio ingresado...\n");
        return 0;
    }
    fclose(pf);
    return 1;
}

///FUNCIONES NECESARIAS
int compararT_datos(const void* dato, const void* dato_lista)
{
    long auxA;
    long auxB;
    memcpy(&auxA,dato+sizeof(unsigned),sizeof(long));
    memcpy(&auxB,dato_lista+sizeof(unsigned),sizeof(long));
    return (auxA) - (auxB);
}

