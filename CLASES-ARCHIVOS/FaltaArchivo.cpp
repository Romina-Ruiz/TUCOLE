#include <iostream>
#include "FaltaArchivo.h"
#include "Falta.h"

using namespace std;


const char *RUTA_FALTA="Persona.dat";


void FaltaArchivo::leerFaltas(Falta falta[], int cantidad)
{
    FILE* p;
    p= fopen(RUTA_FALTA,"rb");

    if(p==nullptr)
    {
        return;
    }

    fread(&falta, sizeof(Falta),cantidad,p);
    fclose(p);
}


void FaltaArchivo::guardar(Falta falta)
{
    FILE* p;
    p = fopen(RUTA_FALTA,"ab");

    if (p == nullptr)
    {
        cout<<"Error al abrir el archivo" <<endl;
        exit(1552);
    }
    else
    {
        fwrite(&falta, sizeof(Falta), 1, p);
        fclose(p);
    }
}


int FaltaArchivo::cantidadFaltas()
{
    FILE *p;
    int cantidad=0;
    Falta falta;
    p=fopen(RUTA_FALTA,"rb");

    if (p==nullptr)
    {
        return 0;
    }

    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(Falta);
    fclose (p);

    return cantidad;
}



bool FaltaArchivo::agregar (Falta dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(RUTA_FALTA,"ab");

    if (p!=NULL)
    {
        fwrite(&dto, sizeof (Falta),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}

bool FaltaArchivo:: modificar(Falta dto)
{
    Falta aux;
    bool modificar = false;
    FILE *p;
    p = fopen(RUTA_FALTA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (Falta),1,p))
        {
            if(dto.getidAlumno()==aux.getidAlumno())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (Falta),1,p);
                fclose (p);
                modificar = true;
            }
        }
    }
    return modificar;
}
bool FaltaArchivo::eliminar(Falta dto)
{
    Falta aux;
    bool eliminar = false;
    FILE *p;
    p = fopen(RUTA_FALTA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (Falta),1,p))
        {
            if(dto.getidAlumno()==aux.getidAlumno())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (Falta),1,p);
                fclose (p);
                eliminar = true;
            }
        }
    }
    return eliminar;
}


int FaltaArchivo::obtenerTamanio()
{
    int Resultado=0;
    int CantBytes=0;
    FILE *p;
    p = fopen(RUTA_FALTA,"rb");
    if (p!=NULL)
    {
        fseek(p,0,SEEK_END);
        CantBytes=ftell(p);
        Resultado=CantBytes/sizeof (Falta);
        fclose(p);
    }
    return Resultado;
}


int FaltaArchivo::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen(RUTA_FALTA, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(FaltaArchivo)*pos, 0);
    leyo=fread(this, sizeof(FaltaArchivo),1, p);
    fclose(p);
    return leyo;
}


