#include <iostream>
#include "MateriaArchivo.h"
#include "Materia.h"
#include<cstring>

using namespace std;


MateriaArchivo::MateriaArchivo(const char *ruta){

    strcpy(_ruta,ruta);
}

 MateriaArchivo::MateriaArchivo(){

    strcpy(_ruta,"Materias.dat");

 }

bool MateriaArchivo::agregar (Materia registro)
{
    bool agregar = false;
    FILE *p;
    p = fopen(_ruta,"ab");

    if (p!=NULL)
    {
        fwrite(&registro, sizeof (Materia),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}

 int MateriaArchivo::getCantidad()
{
    FILE *p;
    int cantidad=0;

    p=fopen(_ruta,"rb");

    if (p==nullptr)
    {
        return 0;
    }

    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(Materia);
    fclose (p);

    return cantidad;
}

 Materia MateriaArchivo::leerReg(int nroRegistro)
{
    Materia registro;
    FILE* p = fopen(_ruta, "rb");
    if (p != NULL)
    {
        fseek(p, nroRegistro * sizeof(Materia), SEEK_SET);
        fread(&registro, sizeof(Materia), 1, p);
        fclose(p);
    }
    return registro;
}


void MateriaArchivo::leerTodos(Materia materia[], int cantidad)
{
    FILE* p;
    p= fopen(_ruta,"rb");

    if(p==nullptr)
    {
        return;
    }

    fread(materia, sizeof(Materia),cantidad,p);
    fclose(p);
}

bool MateriaArchivo::modificar (Materia registro, int nroRegistro)
{
    bool ok = false;
    FILE* p = fopen(_ruta, "rb+");
    if (p != NULL)
    {
        fseek(p, nroRegistro * sizeof(Materia), SEEK_SET);
        fwrite(&registro, sizeof(Materia), 1, p);
        fclose(p);
        ok = true;
    }
    return ok;
}

int MateriaArchivo::buscarReg(int id){
  int nroRegistro = -1;
  int cantidad =this->getCantidad();

  Materia registro;

  for (int i = 0; i < cantidad; i++)
  {
    registro =this->leerReg(i);

    if (registro.getIdMateria() == id)
    {
      nroRegistro = i;
      break;
            }
  }
  return nroRegistro;
}

void MateriaArchivo::vaciar(){
	FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);
}
