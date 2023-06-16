#ifndef CUOTAARCHIVO_H
#define CUOTAARCHIVO_H
#include <cstdio>
#include "Cuota.h"

class CuotaArchivo
{
  public:

//    Cuota leer(int nroRegistro);
    bool leerTodos(Cuota registros[], int cantidad);
    bool agregar(Cuota registro);
    bool modificar(Cuota registro, int nroRegistro);
    int getCantidad();
};

#endif // CUOTAARCHIVO_H
