#include "AlumnoArchivo.h"
#include "Alumno.h"
#include <cstdio>

const char *RUTA_ALUMNO = "Alumno.dat";

bool AlumnoArchivo::agregar(Alumno registro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_ALUMNO, "ab");
    if (pFile != NULL)
    {
        fwrite(&registro, sizeof(Alumno), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

int AlumnoArchivo::getCantidad(){

int cantidad=0;
  FILE* pFile = fopen(RUTA_ALUMNO, "rb");

    if (pFile == NULL){
        return 0;
  }
    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(Alumno);
    fclose(pFile);
  return cantidad;
}

Alumno AlumnoArchivo::leerReg(int nroRegistro)
{
  Alumno obj;
    FILE* pFile = fopen(RUTA_ALUMNO, "rb");

    if (pFile == NULL){
        return obj;
       }

        fseek(pFile, nroRegistro * sizeof(Alumno), SEEK_SET);
        fread(&obj, sizeof(Alumno), 1, pFile);
        fclose(pFile);

    return obj;
}
///revisar
bool AlumnoArchivo::leerTodos(Alumno registros[], int cantidad)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_ALUMNO, "rb");
   if (pFile == NULL){
        return 0;
       }
        fread(registros, sizeof(Alumno), cantidad, pFile);
        fclose(pFile);
        ok = true;

    return ok;
}

bool AlumnoArchivo::modificarReg(Alumno registro, int nroRegistro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_ALUMNO, "rb+");

   if (pFile == NULL){
        return false;
       }
        fseek(pFile, nroRegistro * sizeof(Alumno), SEEK_SET);
        fwrite(&registro, sizeof(Alumno), 1, pFile);
        fclose(pFile);
        ok = true;

    return ok;
}


int AlumnoArchivo::buscarReg(int dni){
  int nroRegistro = -1;
  int cantidad = getCantidad();
  Alumno registro;
  for (int i = 0; i < cantidad; i++)
  {
    registro =this->leerReg(i);
    if (registro.getDni() == dni)
    {
      nroRegistro = i;
      break;
    }
  }
  return nroRegistro;
}
