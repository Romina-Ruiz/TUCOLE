#include <iostream>
#include "MateriaArchivo.h"
#include "Materia.h"
using namespace std;


const char *RUTA_MATERIA="Materia.dat";


void leerMaterias(Materia materia[], int cantidad)
{
    FILE* p;
    p= fopen(RUTA_MATERIA,"rb");

    if(p==nullptr)
    {
        return;
    }

    fread(materia, sizeof(Materia),cantidad,p);
    fclose(p);
}


void MateriaArchivo::guardar(Materia materia)
{
    FILE* p;
    p = fopen(RUTA_MATERIA,"ab");

    if (p == nullptr)
    {
        cout<<"Error al abrir el archivo" <<endl;
        exit(1552);
    }
    else
    {
        fwrite(&materia, sizeof(Materia), 1, p);
        fclose(p);
    }
}


int MateriaArchivo::cantidadMaterias()
{
    FILE *p;
    int cantidad=0;
    Materia materia;
    p=fopen(RUTA_MATERIA,"rb");

    if (p==nullptr)
    {
        return 0;
    }

    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(Materia);
    fclose (p);

    return cantidad;
}


bool MateriaArchivo::agregar (Materia dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(RUTA_MATERIA,"ab");

    if (p!=NULL)
    {
        fwrite(&dto, sizeof (Materia),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}

int MateriaArchivo::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen(RUTA_MATERIA, "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(MateriaArchivo)*pos, 0);
    leyo=fread(this, sizeof(MateriaArchivo),1, p);
    fclose(p);
    return leyo;
}

bool MateriaArchivo::eliminar(Materia dto)
{
    Materia aux;
    bool eliminar = false;
    FILE *p;
    p = fopen(RUTA_MATERIA,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (Materia),1,p))
        {
            if(dto.getIdMateria()==aux.getIdMateria())
            {
                fseek(p,sizeof dto*(-1),SEEK_CUR);
                fwrite(&dto, sizeof (Materia),1,p);
                fclose (p);
                eliminar = true;
            }
        }
    }
    return eliminar;
}

