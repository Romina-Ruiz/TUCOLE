#include <iostream>
#include "Profesor.h"
#include "ProfesorArchivo.h"


const char *RUTA_PROFESOR = "Profesor.dat";


//bool ProfesorArchivo::eliminar(Profesor dto)
//{
//    Profesor aux;
//    bool eliminar = false;
//    FILE *p;
//    p = fopen(RUTA_PROFESOR,"rb+");
//    if (p!=NULL)
//    {
//        while(fread(&dto, sizeof (Profesor),1,p))
//        {
//            if(dto.getDni()==aux.getDni())
//            {
//                fseek(p,sizeof dto*(dto.getId()-1),SEEK_SET);
//                fwrite(&dto, sizeof (Profesor),1,p);
//                fclose (p);
//                eliminar = true;
//            }
//        }
//    }
//    return eliminar;
//}

Profesor ProfesorArchivo::leer(int nroRegistro)
{
    Profesor registro;
    FILE* p = fopen(RUTA_PROFESOR, "rb");
    if (p != NULL)
    {
        fseek(p, nroRegistro * sizeof(Profesor), SEEK_SET);
        fread(&registro, sizeof(Profesor), 1, p);
        fclose(p);
    }
    return registro;
}

bool ProfesorArchivo::leerTodos(Profesor registros[], int cantidad)
{
    bool ok = false;
    FILE* p = fopen(RUTA_PROFESOR, "rb");
    if (p != NULL)
    {
        fread(registros, sizeof(Profesor), cantidad, p);
        fclose(p);
        ok = true;
    }
    return ok;
}

bool ProfesorArchivo::agregar(Profesor registro)
{
    bool ok = false;
    FILE* p = fopen(RUTA_PROFESOR, "ab");
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
    FILE* p = fopen(RUTA_PROFESOR, "rb+");
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
  FILE* p = fopen(RUTA_PROFESOR, "rb");
  if (p != NULL)
  {
    fseek(p, 0, SEEK_END);
    cantidad = ftell(p) / sizeof(Profesor);
    fclose(p);
  }
  return cantidad;
}
/*
int ProfesorArchivo::buscar(int dni){
  int nroRegistro = -1;
  int cantidad = getCantidad();
  Profesor registro;
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

bool ProfesorArchivo::guardar(Profesor reg, int posicionAReemplazar)
{
    FILE *p = fopen(RUTA_PROFESOR,"rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Profesor), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Profesor), 1, p);
    fclose(p);
    return pudoEscribir;
}
*/
