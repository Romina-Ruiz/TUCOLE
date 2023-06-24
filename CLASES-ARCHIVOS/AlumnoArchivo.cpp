#include "AlumnoArchivo.h"
#include "Alumno.h"
#include <cstdio>


AlumnoArchivo::AlumnoArchivo(const char *ruta){

    strcpy(_ruta,ruta);
}
 AlumnoArchivo::AlumnoArchivo(){

    strcpy(_ruta,"Alumno.dat");

 }


bool AlumnoArchivo::agregar(Alumno registro)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "ab");
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
  FILE* pFile = fopen(_ruta, "rb");

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
    FILE* pFile = fopen(_ruta, "rb");

    if (pFile == NULL){
        return obj;
       }

        fseek(pFile, nroRegistro * sizeof(Alumno), SEEK_SET);
        fread(&obj, sizeof(Alumno), 1, pFile);
        fclose(pFile);

    return obj;
}


///revisar
//bool AlumnoArchivo::leerTodos(Alumno registros[], int cantidad)
//{
//    bool ok = false;
//    FILE* pFile = fopen(_ruta, "rb");
//   if (pFile == NULL){
//        return 0;
//       }
//        fread(registros, sizeof(Alumno), cantidad, pFile);
//        fclose(pFile);
//        ok = true;
//
//    return ok;
//}
bool AlumnoArchivo::guardar(Alumno reg, int posicionAReemplazar)
{
    FILE *p = fopen(_ruta, "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Alumno), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Alumno), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool AlumnoArchivo::modificarReg(Alumno registro, int nroRegistro)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "rb+");

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
  int cantidad = this->getCantidad();
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
void AlumnoArchivo::leer(Alumno *vec, int cantidadRegistrosALeer){
	FILE *p = fopen(_ruta, "rb");
	if (p == NULL)
	{
		return ;
	}

	fread(vec, sizeof(Alumno), cantidadRegistrosALeer, p);
	fclose(p);
}

bool AlumnoArchivo::guardar(Alumno *vec, int cantidadRegistrosAEscribir){
	FILE *p = fopen(_ruta, "ab");
	if (p == NULL)
	{
		return false;
	}

	int cantidadRegistrosEscritos = fwrite(vec, sizeof(Alumno), cantidadRegistrosAEscribir, p);
	fclose(p);
	return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void AlumnoArchivo::vaciar(){
	FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);
}
