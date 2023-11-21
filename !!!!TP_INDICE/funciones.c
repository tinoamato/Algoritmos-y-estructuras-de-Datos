#include "func.h"
#include "Lista.h"
#include "indice.h"

#define ESBICIESTO(X) ((X%4==0 && X%100!=0) || X%400==0)? (1) : (0)

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
    while(!feof(pf) && estado)
    {
        memcpy((ind->reg_indice), &nro_Reg, sizeof(unsigned));
        memcpy((ind->reg_indice)+sizeof(unsigned), &(socio.nroSocio), sizeof(long));
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
    const char categorias[][10]= {{"MENOR"},{"CADETE"},{"ADULTO"},{"VITALICIO"},{"HONORARIO"},{"JUBILADO"}};
    int resultado;
    unsigned nro_RegAux;
    pf = fopen(rutaBin,"r+b");
    if(!pf)
    {
        return 0;
    }
    do
    {

        printf("\nIngrese el NroSocio del Socio para dar de ALTA: ");
        scanf("%ld", &(auxSocio.nroSocio));
        fflush(stdin);

    }
    while(!(auxSocio.nroSocio >= 1 && auxSocio.nroSocio <= 10000000));

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
        do
        {
            printf("\nIngrese el Apellido y nombre del nuevo socio: ");
            fgets(auxSocio.apyn,TAMNOMBRE,stdin);

            fflush(stdin);
        }
        while(!esCadena(auxSocio.apyn));


        do
        {
            printf("\nIngrese DNI del nuevo socio: ");
            scanf("%ld",&auxSocio.dni);
        }
        while(!(auxSocio.dni>=10000 && auxSocio.dni<=100000000));

        do
        {
            printf("\nIngrese la fecha de nacimiento del nuevo socio");
            printf("\nAnio: ");
            scanf("%d",&auxSocio.fecha_Nac.aa);

            printf("\nMes: ");
            scanf("%d",&auxSocio.fecha_Nac.mm);

            puts("\nDia: ");
            scanf("%d",&auxSocio.fecha_Nac.dd);

        }
        while(!esFechaValida(&auxSocio.fecha_Nac));


        do
        {
            printf("\nIngrese sexo del nuevo socio ('F' u 'M' u 'O'): ");
            fflush(stdin);
            scanf("%c",&auxSocio.sexo);
            auxSocio.sexo=toupper(auxSocio.sexo);
        }
        while(auxSocio.sexo != 'M' && auxSocio.sexo != 'F' && auxSocio.sexo != 'O');

        do
        {
            printf("\nIngrese la fecha de afiliacion del nuevo socio ");

            printf("\nAnio: ");
            scanf("%d",&auxSocio.fecha_Afil.aa);

            printf("\nMes: ");
            scanf("%d",&auxSocio.fecha_Afil.mm);

            printf("\nDia: ");
            scanf("%d",&auxSocio.fecha_Afil.dd);


        }
        while(!esFechaValida(&auxSocio.fecha_Afil));


        do
        {
            printf("\nIngrese la categoria del nuevo socio: ");
            fflush(stdin);
            scanf("%s", auxSocio.categoria);
            fflush(stdin);

        }
        while(!buscarCategoria(categorias,6,auxSocio.categoria));



        do
        {
            printf("\nIngrese la fecha de la ultima cuota paga del nuevo socio ");

            printf("\nAnio: ");
            scanf("%d",&auxSocio.fecha_Ultimo_Cuota_Paga.aa);

            printf("\nMes: ");
            scanf("%d",&auxSocio.fecha_Ultimo_Cuota_Paga.mm);

            printf("\nDia: ");
            scanf("%d",&auxSocio.fecha_Ultimo_Cuota_Paga.dd);

        }
        while(!esFechaValida(&auxSocio.fecha_Ultimo_Cuota_Paga));



        auxSocio.estado='A';
        auxSocio.fecha_De_Baja.aa = auxSocio.fecha_De_Baja.mm = auxSocio.fecha_De_Baja.dd = 0;
        fseek(pf,0,SEEK_END);
        nro_RegAux = (ftell(pf)/sizeof(t_Socio));
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
    int resultado, flag;
    unsigned nro_RegAux;
    pf = fopen(rutaBin,"r+b");
    if(!pf)
    {
        return 0;
    }

    do
    {

        printf("\nIngrese el NroSocio del Socio: ");
        scanf("%ld", &(auxSocio.nroSocio));
        fflush(stdin);

    }
    while(!(auxSocio.nroSocio >= 1 && auxSocio.nroSocio <= 10000000));

    resultado = ind_buscar(ind,&(auxSocio.nroSocio),&(nro_RegAux));
    if(resultado == 1)
    {
        fseek(pf,sizeof(t_Socio)*nro_RegAux,SEEK_SET);
        fread(&(auxSocio),sizeof(t_Socio),1,pf);
        do
        {
            printf("\nIngrese el nombre modificado: ");
            fflush(stdin);
            fgets(auxSocio.apyn,TAMNOMBRE,stdin);
            if((flag=!esCadena(auxSocio.apyn)))
                printf("\nEl nombre ingreasdo no es valido\n");
        }
        while(flag);


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

    do
    {

        printf("\nIngrese el NroSocio del Socio para dar de BAJA: ");
        scanf("%ld", &(auxSocio.nroSocio));
        fflush(stdin);

    }
    while(!(auxSocio.nroSocio >= 1 && auxSocio.nroSocio <= 10000000));


    fflush(stdin);
    resultado = ind_buscar(ind,&(auxSocio.nroSocio),&(nro_RegAux));
    if(resultado == 1)
    {
        fseek(pf,sizeof(t_Socio)*nro_RegAux,SEEK_SET);
        fread(&(auxSocio),sizeof(t_Socio),1,pf);
        if(auxSocio.estado == 'I')
        {
            printf("\n\nEl socio ya existe y esta Inactivo.\n");
        }
        else
        {

            auxSocio.estado = 'I';
            fseek(pf, (long)sizeof(t_Socio)*(-1),SEEK_CUR);

            do
            {
                printf("\nIngrese la fecha de baja ");

                printf("\nAnio: ");
                scanf("%d",&auxSocio.fecha_De_Baja.aa);
                printf("\nMes: ");
                scanf("%d",&auxSocio.fecha_De_Baja.mm);
                printf("\nDia: ");
                scanf("%d",&auxSocio.fecha_De_Baja.dd);

            }
            while(!esFechaValida(&auxSocio.fecha_De_Baja));




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
int listar_socios_baja(t_indice *ind, char *rutaBin)
{
    FILE *pf;
    int r;
    pf = fopen(rutaBin, "rb");
    if(!pf)
    {
        return 0;
    }
    r = recorrerLista(&(ind->lista),mostrar_Si_Baja,pf);
    return r;

}
int listar_socios_alta(t_indice *ind, char *rutaBin)
{

    FILE *pf;
    int r;
    pf = fopen(rutaBin, "rb");
    if(!pf)
    {
        return 0;
    }
    r = recorrerLista(&(ind->lista),mostrar_Si_Alta,pf);
    return r;

}
int listar_10_socios_mayor_retraso(char* rutaBin)
{
    t_lista aux_lista;
    int i=0;
    t_Socio aux_socio;
    t_Socio basura;

    FILE* pf = fopen(rutaBin,"rb");

    if(!pf)
        return 0;

    crearLista(&aux_lista);

    fread(&aux_socio,sizeof(t_Socio),1,pf);
    for(i = 0; i<10; i++)
    {
        insertarEnOrdenLista(&aux_lista,sizeof(t_Socio),&aux_socio,comp_mayor_retraso);
        fread(&aux_socio,sizeof(t_Socio),1,pf);

    }

    while(!feof(pf))
    {
        if(comp_mayor_retraso(&aux_socio,(aux_lista)->info)>0)
        {

            eliminarPrimeroLista(&aux_lista,sizeof(t_Socio),&basura); //no lo usas lo que eliminas
            insertarEnOrdenLista(&aux_lista,sizeof(t_Socio),&aux_socio,comp_mayor_retraso);
        }
        fread(&aux_socio,sizeof(t_Socio),1,pf);
    }

    if(!(ordenarListaInsercion(&(aux_lista),comp_mayor_retraso)))
        return 0;


    recorrerLista(&aux_lista,mostrar_Todos,0);

    return 1;

}

///FUNCIONES NECESARIAS`
int compararT_datos(const void* dato, const void* dato_lista)
{
    long auxA;
    long auxB;

    memcpy(&auxA,dato+sizeof(unsigned),sizeof(long));

    memcpy(&auxB,dato_lista+sizeof(unsigned),sizeof(long));

    return (auxA) - (auxB);
}
int comp_mayor_retraso(const void* dato,const void* dato_lista)
{
    t_Socio* auxB = (t_Socio*)dato;
    t_Socio* auxA = (t_Socio*)dato_lista;
    int comp;

    if(!(comp = (auxA->fecha_Ultimo_Cuota_Paga.aa - auxB->fecha_Ultimo_Cuota_Paga.aa)))
    {
        if(!(comp = (auxA->fecha_Ultimo_Cuota_Paga.mm - auxB->fecha_Ultimo_Cuota_Paga.mm)))
        {
            comp = (auxA->fecha_Ultimo_Cuota_Paga.dd - auxB->fecha_Ultimo_Cuota_Paga.dd);
        }
    }
    return comp;

}
void mostrar_Si_Baja(const void* dato, unsigned tam_RegIndice, void *arch)
{
    FILE *pf = (FILE*)arch;
    t_Socio aux;
    unsigned nro_reg;

    memcpy(&nro_reg,dato,sizeof(unsigned));

    fseek(pf,sizeof(t_Socio)*nro_reg,SEEK_SET);

    fread(&aux,sizeof(t_Socio),1,pf);

    if(aux.estado == 'I')
    {
        mostrarSocio(&aux);
    }

}
void mostrar_Si_Alta(const void* dato, unsigned tam_RegIndice, void *arch)
{
    FILE *pf = (FILE*)arch;
    t_Socio aux;
    unsigned nro_reg;

    memcpy(&nro_reg,dato,sizeof(unsigned));

    fseek(pf,sizeof(t_Socio)*nro_reg,SEEK_SET);

    fread(&aux,sizeof(t_Socio),1,pf);

    if(aux.estado == 'A')
    {
        mostrarSocio(&aux);
    }

}
void mostrar_Todos(const void* dato, unsigned tam_RegIndice, void *arch)
{
    t_Socio* aux = (t_Socio*)dato;

    mostrarSocio(aux);
}
void mostrarSocio(t_Socio *socio)
{
    puts("_________________________________________________________");
    printf("\nNro Socio: %li", socio->nroSocio);
    printf("\nApellido y Nombre: %s", socio->apyn);
    printf("\nDni: %li", socio->dni);
    printf("\nFecha Nac: %d - %d - %d", socio->fecha_Nac.dd, socio->fecha_Nac.mm, socio->fecha_Nac.aa);
    printf("\nSexo: %c", socio->sexo);
    printf("\nFecha Afil: %d - %d - %d", socio->fecha_Afil.dd, socio->fecha_Afil.mm, socio->fecha_Afil.aa);
    printf("\nCategoria: %s", socio->categoria);
    printf("\nFecha ultima Cuota Paga: %d - %d - %d", socio->fecha_Ultimo_Cuota_Paga.dd, socio->fecha_Ultimo_Cuota_Paga.mm, socio->fecha_Ultimo_Cuota_Paga.aa);
    printf("\nEstado: %c", socio->estado);
    if(socio->estado == 'I')
        printf("\nFecha de Baja: %d - %d - %d", socio->fecha_De_Baja.dd, socio->fecha_De_Baja.mm, socio->fecha_De_Baja.aa);
    printf("\n");

}
int esCadena(const char* cad)
{
    while(*cad)
    {
        if(!isalpha(*cad) && !isspace(*cad))
        {
            return 0;
        }
        cad++;

    }
    return 1;
}

int esFechaValida(const t_fecha* fec)
{
    const char dias[][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };

    return fec->mm > 0 && fec->mm <=12 &&
           fec->aa >=1600 && fec->aa <= 2024 &&
           fec->dd > 0 && fec->dd <=dias[ESBICIESTO(fec->aa)][fec->mm -1];
}
int buscarCategoria(const char vec[][10],int ce, const char* cat)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(strcmpi(vec[i],cat) == 0)
            return 1;

    }
    return 0;
}

