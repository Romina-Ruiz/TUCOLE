#include <iostream>
#include "ComunicadosArchivo.h"
#include <cstring>


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
//bool ComunicadosArchivo::eliminar(Comunicados dto)
//{
//   Comunicados aux;
//    bool eliminar = false;
//    FILE *p;
//    p = fopen(_ruta,"rb+");
//    if (p!=NULL)
//    {
//        while(fread(&dto, sizeof (Comunicados),1,p))
//        {
//            if(dto.getIdComunicado()==aux.getIdComunicado())
//            {
//                fseek(p,sizeof dto*(-1),SEEK_CUR);
//                fwrite(&dto, sizeof (Comunicados),1,p);
//                fclose (p);
//                eliminar = true;
//            }
//        }
//    }
//    return eliminar;
//}
void ComunicadosArchivo::vaciar(){
	FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);
}
