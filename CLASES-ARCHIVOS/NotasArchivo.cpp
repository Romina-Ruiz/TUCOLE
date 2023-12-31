#include <iostream>
#include "NotasArchivo.h"
#include "Notas.h"
#include<cstring>
using namespace std;


NotasArchivo::NotasArchivo(const char *ruta)
{
    strcpy(_ruta,ruta);
}

NotasArchivo::NotasArchivo()
{

    strcpy(_ruta,"Notas.dat");

}


bool NotasArchivo::agregar (Notas dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(_ruta,"ab");

    if (p!=NULL)
    {
        fwrite(&dto, sizeof (Notas),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}

int NotasArchivo::getCantidad()
{
    FILE *p;
    int cantidad=0;

    p=fopen(_ruta,"rb");

    if (p==nullptr)
    {
        return 0;
    }

    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(Notas);
    fclose (p);

    return cantidad;
}

Notas NotasArchivo::leerReg(int nroRegistro)
 {

  Notas registro;
    FILE* p = fopen(_ruta, "rb");
    if (p != NULL)
    {
        fseek(p, nroRegistro * sizeof(Notas), SEEK_SET);
        fread(&registro, sizeof(Notas), 1, p);
        fclose(p);
    }
    return registro;

}


bool NotasArchivo::modificar(Notas registro, int nroRegistro)
{
    bool ok = false;
    FILE* p = fopen(_ruta, "rb+");
    if (p != NULL)
    {
        fseek(p, nroRegistro * sizeof(Notas), SEEK_SET);
        fwrite(&registro, sizeof(Notas), 1, p);
        fclose(p);
        ok = true;
    }
    return ok;

}


/// SOLO MUESTRA 1 REGISTRO  HACER UN FOR SI QUIERO MOSTRAR TODO EL REGISTRO DE NOTAS?


int NotasArchivo::buscarReg(int dni, int id){

    int nroRegistro = -1;
   int cantidad =this->getCantidad();

  Notas registro;

  for (int i = 0; i < cantidad; i++)
  {
    registro =this->leerReg(i);

    if (registro.getDNIalumno() == dni&& registro.getIDNota()==id )
    {
      nroRegistro = i;
      break;
            }
  }
  return nroRegistro;


}


int NotasArchivo::buscarReg(int dni)
{
    int nroRegistro = -1;
   int cantidad =this->getCantidad();

  Notas registro;

  for (int i = 0; i < cantidad; i++)
  {
    registro =this->leerReg(i);

    if (registro.getDNIalumno() == dni)
    {
      nroRegistro = i;
      break;
            }
  }
  return nroRegistro;

}


void NotasArchivo::leer(Notas *vec, int cantidadRegistrosALeer){
	FILE *p = fopen(_ruta, "rb");
	if (p == NULL)
	{
		return ;
	}

	fread(vec, sizeof(Notas), cantidadRegistrosALeer, p);
	fclose(p);
}

bool NotasArchivo::guardar(Notas *vec, int cantidadRegistrosAEscribir){
	FILE *p = fopen(_ruta, "ab");
	if (p == NULL)
	{
		return false;
	}

	int cantidadRegistrosEscritos = fwrite(vec, sizeof(Notas), cantidadRegistrosAEscribir, p);
	fclose(p);
	return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}




void NotasArchivo::vaciar()
{
    FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);

}
