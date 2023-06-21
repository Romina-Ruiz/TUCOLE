#ifndef PROFESORARCHIVO_H
#define PROFESORARCHIVO_H
#include <cstdio>
#include "Profesor.h"
#include "ProfesorArchivo.h"


class ProfesorArchivo
{

     public:

    Profesor leerReg(int nroRegistro);
    void leer(Profesor *vec, int cantidadRegistrosALeer);
    bool agregar(Profesor registro);
    bool modificar(Profesor registro, int nroRegistro);
    int getCantidad();
    int buscarReg(int dni);
    bool guardar(Profesor reg, int posicionAReemplazar);
    bool guardar(Profesor *vec, int cantidadRegistrosAEscribir);
    void vaciar();
};

#endif // PROFESORARCHIVO_H
