#include <iostream>
#include "ComunicadosArchivo.h"
#include <cstring>
#include"Comunicados.h"

ComunicadosArchivo::ComunicadosArchivo(const char *ruta)
{
    strcpy(_ruta,ruta);
}

ComunicadosArchivo::ComunicadosArchivo(){

    strcpy(_ruta,"Comunicados.dat");

}

bool ComunicadosArchivo::agregar (Comunicados dto)
{
    bool agregar = false;
    FILE *p;
    p = fopen(_ruta,"ab");

    if (p!=NULL)
    {
        fwrite(&dto, sizeof (Comunicados),1,p);
        fclose (p);
        agregar = true;
    }
    return agregar;
}
int ComunicadosArchivo::getCantidad(){
  int cantidad = 0;
  FILE* pFile = fopen(_ruta, "rb");
  if (pFile != NULL)
  {
    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(Comunicados);
    fclose(pFile);
  }
  return cantidad;
}

Comunicados ComunicadosArchivo::leerReg(int nroRegistro)
{
Comunicados obj;
    FILE* pFile = fopen(_ruta, "rb");

    if (pFile == NULL){
        return obj;
       }

        fseek(pFile, nroRegistro * sizeof(Comunicados), SEEK_SET);
        fread(&obj, sizeof(Comunicados), 1, pFile);
        fclose(pFile);

    return obj;

}

 bool ComunicadosArchivo::modificarReg(Comunicados registro, int nroRegistro){

 bool ok = false;
    FILE* pFile = fopen(_ruta, "rb+");

   if (pFile == NULL){
        return false;
       }
        fseek(pFile, nroRegistro * sizeof(Comunicados), SEEK_SET);
        fwrite(&registro, sizeof(Comunicados), 1, pFile);
        fclose(pFile);
        ok = true;

    return ok;
  }

int ComunicadosArchivo::buscarReg(int id){

  int nroRegistro = -1;

  int cantidad = this->getCantidad();
  Comunicados registro;
  for (int i = 0; i < cantidad; i++)
  {
    registro =this->leerReg(i);
    if (registro.getIdComunicado() == id)
    {
      nroRegistro = i;
      break;
    }
  }
  return nroRegistro;

  }
bool ComunicadosArchivo::guardar(Comunicados reg, int posicionAReemplazar){

   FILE *p = fopen(_ruta, "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Comunicados), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Comunicados), 1, p);
    fclose(p);
    return pudoEscribir;

  }
void ComunicadosArchivo::leer(Comunicados *vec, int cantidadRegistrosALeer){
	FILE *p = fopen(_ruta, "rb");
	if (p == NULL)
	{
		return ;
	}

	fread(vec, sizeof(Comunicados), cantidadRegistrosALeer, p);
	fclose(p);
}

bool ComunicadosArchivo::guardar(Comunicados *vec, int cantidadRegistrosAEscribir){
	FILE *p = fopen(_ruta, "ab");
	if (p == NULL)
	{
		return false;
	}

	int cantidadRegistrosEscritos = fwrite(vec, sizeof(Comunicados), cantidadRegistrosAEscribir, p);
	fclose(p);
	return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


void ComunicadosArchivo::vaciar(){
	FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);
}
