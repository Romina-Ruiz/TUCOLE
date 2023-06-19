#include <cstdio>
#include"Cuota.h"
#include "CuotaArchivo.h"
#include"CuotaManager.h"

const char *RUTA_CUOTA = "Cuota.dat";

bool CuotaArchivo::agregar(Cuota registro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_CUOTA, "ab");
    if (pFile != NULL)
    {
        fwrite(&registro, sizeof(Cuota), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

int CuotaArchivo::getCantidad(){
  int cantidad = 0;
  FILE* pFile = fopen(RUTA_CUOTA, "rb");
  if (pFile != NULL)
  {
    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(Cuota);
    fclose(pFile);
  }
  return cantidad;
}

/*
Cuota CuotaArchivo::leerReg(int nroRegistro){

  Cuota obj;
    FILE* pFile = fopen(RUTA_CUOTA, "rb");

    if (pFile == NULL){
            {
        return obj;
                }

        fseek(pFile, nroRegistro * sizeof(Cuota), SEEK_SET);
        fread(&obj, sizeof(Cuota), 1, pFile);
        fclose(pFile);

    return obj;
    }
}*/

bool CuotaArchivo::leerTodos(Cuota registros[], int cantidad)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_CUOTA, "rb");
    if (pFile != NULL)
    {
        fread(registros, sizeof(Cuota), cantidad, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}


bool CuotaArchivo::modificar(Cuota registro, int nroRegistro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_CUOTA, "rb+");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(Cuota), SEEK_SET);
        fwrite(&registro, sizeof(Cuota), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}
/*
int CuotaArchivo::buscarReg(int dni){

  int nroRegistro = -1;
  int cantidad = this->getCantidad();

  Cuota registro;
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
}*/

