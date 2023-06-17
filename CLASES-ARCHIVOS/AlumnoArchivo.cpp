#include "AlumnoArchivo.h"
#include "Alumno.h"
#include <cstdio>
const char *RUTA_ALUMNO = "Alumno.dat";


bool AlumnoArchivo::eliminar(Alumno dto)
{
    Alumno aux;
    bool eliminar = false;
    FILE *p;
    p = fopen(RUTA_ALUMNO,"rb+");
    if (p!=NULL)
    {
        while(fread(&dto, sizeof (Alumno),1,p))
        {
            if(dto.getDni()==aux.getDni())
            {
                fseek(p,sizeof dto*(dto.getId()-1),SEEK_SET);
                fwrite(&dto, sizeof (Alumno),1,p);
                fclose (p);
                eliminar = true;
            }
        }
    }
    return eliminar;
}

/**/

Alumno AlumnoArchivo::leer(int nroRegistro)
{
    Alumno registro;
    FILE* pFile = fopen(RUTA_ALUMNO, "rb");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(Alumno), SEEK_SET);
        fread(&registro, sizeof(Alumno), 1, pFile);
        fclose(pFile);
    }
    return registro;
}

bool AlumnoArchivo::leerTodos(Alumno registros[], int cantidad)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_ALUMNO, "rb");
    if (pFile != NULL)
    {
        fread(registros, sizeof(Alumno), cantidad, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

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

bool AlumnoArchivo::modificar(Alumno registro, int nroRegistro)
{
    bool ok = false;
    FILE* pFile = fopen(RUTA_ALUMNO, "rb+");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(Alumno), SEEK_SET);
        fwrite(&registro, sizeof(Alumno), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

int AlumnoArchivo::getCantidad(){
  int cantidad = 0;
  FILE* pFile = fopen(RUTA_ALUMNO, "rb");
  if (pFile != NULL)
  {
    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(Persona);
    fclose(pFile);
  }
  return cantidad;
}

int AlumnoArchivo::buscar(int dni){
  int nroRegistro = -1;
  int cantidad = getCantidad();
  Alumno registro;
  for (int i = 0; i < cantidad; i++)
  {
    registro = leer(i);
    if (registro.getDni() == dni)
    {
      nroRegistro = i;
      break;
    }
  }
  return nroRegistro;
}

bool AlumnoArchivo::guardar(Alumno reg, int posicionAReemplazar)
{
    FILE *p = fopen(RUTA_ALUMNO,"rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Alumno), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Alumno), 1, p);
    fclose(p);
    return pudoEscribir;
}
