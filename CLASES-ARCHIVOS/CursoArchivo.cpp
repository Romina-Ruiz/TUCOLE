#include <iostream>
#include "CursoArchivo.h"
#include <cstring>


CursoArchivo::CursoArchivo(const char *ruta){

    strcpy(_ruta,ruta);
}
 CursoArchivo::CursoArchivo(){

    strcpy(_ruta,"Curso.dat");

 }

bool CursoArchivo::agregar(Curso registro)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "ab");
    if (pFile != NULL)
    {
        fwrite(&registro, sizeof(Curso), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

int CursoArchivo::getCantidad(){
  int cantidad = 0;
  FILE* pFile = fopen(_ruta, "rb");
  if (pFile != NULL)
  {
    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(Curso);
    fclose(pFile);
  }
  return cantidad;
}


Curso CursoArchivo::leerReg(int nroRegistro){

Curso obj;
    FILE* pFile = fopen(_ruta, "rb");

    if (pFile == NULL){
            {
        return obj;
                }

        fseek(pFile, nroRegistro * sizeof(Curso), SEEK_SET);
        fread(&obj, sizeof(Curso), 1, pFile);
        fclose(pFile);

    return obj;
    }
}

bool CursoArchivo::modificarReg(Curso registro, int nroRegistro)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "rb+");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(Curso), SEEK_SET);
        fwrite(&registro, sizeof(Curso), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

bool CursoArchivo::leerTodos(Curso registros[], int cantidad)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "rb");
    if (pFile != NULL)
    {
        fread(registros, sizeof(Curso), cantidad, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}



int CursoArchivo::buscarReg(int dni){

  int nroRegistro = -1;
  int cantidad = this->getCantidad();

  Curso registro;
  for (int i = 0; i < cantidad; i++)
  {
    registro =this->leerReg(i);
    if (registro.getDniAlumno() == dni)
    {
      nroRegistro = i;
      break;
    }
  }
  return nroRegistro;
}

void CursoArchivo::vaciar(){

FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);


}
