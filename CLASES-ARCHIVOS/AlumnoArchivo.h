#ifndef ALUMNOARCHIVO_H
#define ALUMNOARCHIVO_H
#include <cstdio>
#include "Alumno.h"

class AlumnoArchivo
{
   public:
    bool eliminar (Alumno);
    Alumno leer(int nroRegistro);
    bool leerTodos(Alumno registros[], int cantidad);
    bool agregar(Alumno registro);
    bool modificar(Alumno registro, int nroRegistro);
    int getCantidad();
    int buscar(int dni);

};

#endif // ALUMNOARCHIVO_H
