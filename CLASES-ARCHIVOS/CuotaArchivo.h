#ifndef CUOTAARCHIVO_H
#define CUOTAARCHIVO_H
#include "Cuota.h"
#include"CuotaManager.h"

class CuotaArchivo
{
private:

    char _ruta[30];

public:
    CuotaArchivo (const char *ruta);
    CuotaArchivo();

    bool agregar(Cuota registro);
    int getCantidad();
    Cuota leerReg(int nroRegistro);
    bool leerTodos(Cuota registros[], int cantidad);
    bool modificar(Cuota registro, int nroRegistro);
    int buscarReg(int dni);

};

#endif // CUOTAARCHIVO_H
