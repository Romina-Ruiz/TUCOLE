#ifndef PROFESORARCHIVO_H
#define PROFESORARCHIVO_H
#include <cstdio>
#include "Profesor.h"
#include "ProfesorArchivo.h"


class ProfesorArchivo
{

private:
    char _ruta[30];

public:
    ProfesorArchivo (const char *ruta);
    ProfesorArchivo();

    bool agregar(Profesor registro);
     int getCantidad();
    Profesor leerReg(int nroRegistro);
    void leer(Profesor *vec, int cantidadRegistrosALeer);
    bool modificar(Profesor registro, int nroRegistro);
    int buscarReg(int dni);

    bool guardar(Profesor reg, int posicionAReemplazar);
    bool guardar(Profesor *vec, int cantidadRegistrosAEscribir);

    void vaciar();

};

#endif // PROFESORARCHIVO_H
