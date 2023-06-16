#ifndef PROFESORARCHIVO_H
#define PROFESORARCHIVO_H
#include <cstdio>
#include "Profesor.h"


class ProfesorArchivo
{
     public:

    bool eliminar (Profesor );
    Profesor leer(int nroRegistro);
    bool leerTodos(Profesor registros[], int cantidad);
    bool agregar(Profesor registro);
    bool modificar(Profesor registro, int nroRegistro);
    int getCantidad();
    int buscar(int dni);
};

#endif // PROFESORARCHIVO_H
