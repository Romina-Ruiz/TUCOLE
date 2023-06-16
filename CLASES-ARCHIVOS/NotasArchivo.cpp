#include <iostream>
#include "NotasArchivo.h"
#include "Notas.h"
using namespace std;


const char *RUTA_NOTAS="Notas.dat";


void NotasArchivo::leerNotas(Notas nota[], int cantidad)
{
    FILE* p;
    p= fopen(RUTA_NOTAS,"rb");

    if(p==nullptr)
    {
        return;
    }

    fread(nota, sizeof(Notas),cantidad,p);
    fclose(p);
}


void NotasArchivo::guardar(Notas nota)
{
    FILE* p;
    p = fopen(RUTA_NOTAS,"ab");

    if (p == nullptr)
    {
        cout<<"Error al abrir el archivo" <<endl;
        exit(1552);
    }
    else
    {
        fwrite(&nota, sizeof(Notas), 1, p);
        fclose(p);
    }
}


int NotasArchivo::cantidadNotas()
{
    FILE *p;
    int cantidad=0;
    Notas nota;
    p=fopen(RUTA_NOTAS,"rb");

    if (p==nullptr)
    {
        return 0;
    }

    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(Notas);
    fclose (p);

    return cantidad;
}


bool NotasArchivo::agregar (Notas dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(RUTA_NOTAS,"ab");

    if (p!=NULL)
    {
        fwrite(&dto, sizeof (Notas),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}

int NotasArchivo::obtenerTamanio()
{
    int Resultado=0;
    int CantBytes=0;
    FILE *p;
    p = fopen(RUTA_NOTAS,"rb");
    if (p!=NULL)
    {
        fseek(p,0,SEEK_END);
        CantBytes=ftell(p);
        Resultado=CantBytes/sizeof (Notas);
        fclose(p);
    }
    return Resultado;
}


int NotasArchivo::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen(RUTA_NOTAS, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(NotasArchivo)*pos, 0);
    leyo=fread(this, sizeof(NotasArchivo),1, p);
    fclose(p);
    return leyo;
}

//bool NotasArchivo::eliminar(Notas dto)
//{
//    Notas aux;
//    bool eliminar = false;
//    FILE *p;
//    p = fopen(RUTA_NOTAS,"rb+");
//    if (p!=NULL)
//    {
//        while(fread(&dto, sizeof (Persona),1,p))
//        {
//            if(dto.getDni()==aux.getDni())
//            {
//                fseek(p,sizeof dto*(-1),SEEK_CUR);
//                fwrite(&dto, sizeof (Persona),1,p);
//                fclose (p);
//                eliminar = true;
//            }
//        }
//    }
//    return eliminar;
//}

