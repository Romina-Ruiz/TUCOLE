#include <iostream>
#include "Profesor.h"
#include "ProfesorArchivo.h"


ProfesorArchivo::ProfesorArchivo(const char *ruta)
{
    strcpy(_ruta,ruta);
}

ProfesorArchivo::ProfesorArchivo()
{

    strcpy(_ruta,"Profesor.dat");

}
Profesor ProfesorArchivo::leerReg(int nroRegistro)
{
    Profesor registro;
    FILE* p = fopen(_ruta, "rb");
    if (p != NULL)
    {
        fseek(p, nroRegistro * sizeof(Profesor), SEEK_SET);
        fread(&registro, sizeof(Profesor), 1, p);
        fclose(p);
    }
    return registro;
}
bool ProfesorArchivo::guardar(Profesor *vec, int cantidadRegistrosAEscribir){
	FILE *p = fopen(_ruta, "ab");
	if (p == NULL)
	{
		return false;
	}

	int cantidadRegistrosEscritos = fwrite(vec, sizeof(Profesor), cantidadRegistrosAEscribir, p);
	fclose(p);
	return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void ProfesorArchivo::leer(Profesor *vec, int cantidadRegistrosALeer){
	FILE *p = fopen(_ruta, "rb");
	if (p == NULL)
	{
		return ;
	}

	fread(vec, sizeof(Profesor), cantidadRegistrosALeer, p);
	fclose(p);
}

bool ProfesorArchivo::agregar(Profesor registro)
{
    bool ok = false;
    FILE* p = fopen(_ruta, "ab");
    if (p != NULL)
    {
        fwrite(&registro, sizeof(Profesor), 1, p);
        fclose(p);
        ok = true;
    }
    return ok;
}

bool ProfesorArchivo::modificar(Profesor registro, int nroRegistro)
{
    bool ok = false;
    FILE* p = fopen(_ruta, "rb+");
    if (p != NULL)
    {
        fseek(p, nroRegistro * sizeof(Profesor), SEEK_SET);
        fwrite(&registro, sizeof(Profesor), 1, p);
        fclose(p);
        ok = true;
    }
    return ok;
}

int ProfesorArchivo::getCantidad(){
  int cantidad = 0;
  FILE* p = fopen(_ruta, "rb");

  if (p != NULL)
  {
    fseek(p, 0, SEEK_END);
    cantidad = ftell(p) / sizeof(Profesor);
    fclose(p);
  }
  return cantidad;
}

int ProfesorArchivo::buscarReg(int dni){
  int nroRegistro = -1;
  int cantidad = getCantidad();
  Profesor registro;
  for (int i = 0; i < cantidad; i++)
  {
    registro = leerReg(i);
    if (registro.getDni() == dni)
    {
      nroRegistro = i;
      break;
    }
  }
  return nroRegistro;
}

bool ProfesorArchivo::guardar(Profesor reg, int posicionAReemplazar)
{
    FILE *p = fopen(_ruta,"rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Profesor), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Profesor), 1, p);
    fclose(p);
    return pudoEscribir;
}

void ProfesorArchivo::vaciar(){
	FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);
}

