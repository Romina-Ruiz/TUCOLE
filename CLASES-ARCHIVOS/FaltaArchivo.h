#ifndef FALTAARCHIVO_H
#define FALTAARCHIVO_H
#include "Falta.h"

class FaltaArchivo
{
private:
    char _ruta[30];

public:
    FaltaArchivo (const char *ruta);
    FaltaArchivo();

    bool agregar(Falta reg);
    int getCantidad();
    Falta leerReg(int nroReg);
    bool leerTodos(Falta falta[], int cantidad);
    bool modificar (Falta registro, int nroRegistro);
    int buscarReg(int dni);
    bool guardar(Falta reg, int posicionAReemplazar);
    void vaciar();

};

#endif // FALTAARCHIVO_H
