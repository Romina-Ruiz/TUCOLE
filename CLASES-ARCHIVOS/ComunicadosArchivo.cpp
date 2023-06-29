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

void ComunicadosArchivo::vaciar(){
	FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);
}
