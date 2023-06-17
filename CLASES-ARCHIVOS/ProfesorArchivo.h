#ifndef PROFESORARCHIVO_H
#define PROFESORARCHIVO_H
#include <cstdio>
#include "Profesor.h"
#include "ProfesorArchivo.h"


class ProfesorArchivo
{
     public:

//    bool eliminar (Profesor );
    Profesor leer(int nroRegistro);
    bool leerTodos(Profesor registros[], int cantidad);
    bool agregar(Profesor registro);
    bool modificar(Profesor registro, int nroRegistro);
    int getCantidad();
    int buscar(int dni);
    bool guardar(Profesor reg, int posicionAReemplazar);
};

#endif // PROFESORARCHIVO_H
