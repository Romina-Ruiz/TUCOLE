#include <iostream>
#include "PersonaArchivo.h"
#include "Persona.h"
using namespace std;


const char *RUTA_PERSONA="Persona.dat";


void PersonaArchivo::leerAlumnos(Persona alumno[], int cantidad)
{
    FILE* p;
    p= fopen(RUTA_PERSONA,"rb");

    if(p==nullptr)
    {
        return;
    }

    fread(alumno, sizeof(Persona),cantidad,p);
    fclose(p);
}


void PersonaArchivo::guardar(Persona alumno)
{
    FILE* p;
    p = fopen(RUTA_PERSONA,"ab");

    if (p == nullptr)
    {
        cout<<"Error al abrir el archivo" <<endl;
        exit(1552);
    }
    else
    {
        fwrite(&alumno, sizeof(Persona), 1, p);
        fclose(p);
    }
}


int PersonaArchivo::cantidadAlumnos()
{
    FILE *p;
    int cantidad=0;
    Persona alumno;
    p=fopen(RUTA_PERSONA,"rb");

    if (p==nullptr)
    {
        return 0;
    }

    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(Persona);
    fclose (p);

    return cantidad;
}


bool PersonaArchivo::existe (const char* R)
{
    bool existe = false;
    FILE *p;
    p = fopen(R,"rb");

    if (p!=NULL)
    {
        fclose (p);
        existe = true;
    }
    return existe;
}

bool PersonaArchivo::agregar (Persona dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"ab");

    if (p!=NULL)
    {
        fwrite(&dto, sizeof (Persona),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}
/*
bool PersonaArchivo::modificar(Persona dto)
{
    Persona aux;
    bool modificar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (Persona),1,p))
        {
            if(dto.getDni()==aux.getDni())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (Persona),1,p);
                fclose (p);
                modificar = true;
            }
        }
    }
    return modificar;
}*/

int PersonaArchivo::obtenerTamanio()
{
    int Resultado=0;
    int CantBytes=0;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb");
    if (p!=NULL)
    {
        fseek(p,0,SEEK_END);
        CantBytes=ftell(p);
        Resultado=CantBytes/sizeof (Persona);
        fclose(p);
    }
    return Resultado;
}

Persona PersonaArchivo::buscarRegistro(int a,int b)
{
    Persona dto;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb");
    if (p!=NULL)
    {
        fseek(p,-1*sizeof (Persona),b);
        fread(&dto,sizeof (Persona),1,p);
        fclose (p);
    }
    return dto;
}
/*
Persona PersonaArchivo::obtenerPorDNI (int DNI)
{
    bool encontro=false;
    Persona dto;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (Persona),1,p))
        {
            if(dto.getDni()==DNI)
            {
                encontro=true;
                break;
            }
        }
        if(!encontro)
        {
            dto.setDni(-1);
        }
    }
    else
    {
        dto.setDni(-1);
    }
    fclose (p);

    return dto;
}


int PersonaArchivo::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen(RUTA_PERSONA, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(PersonaArchivo)*pos, 0);
    leyo=fread(this, sizeof(PersonaArchivo),1, p);
    fclose(p);
    return leyo;
}

bool PersonaArchivo::eliminar(Persona dto)
{
    Persona aux;
    bool eliminar = false;
    FILE *p;
    p = fopen(RUTA_PERSONA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (Persona),1,p))
        {
            if(dto.getDni()==aux.getDni())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (Persona),1,p);
                fclose (p);
                eliminar = true;
            }
        }
    }
    return eliminar;
}
*/
