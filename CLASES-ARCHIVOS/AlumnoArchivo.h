#ifndef ALUMNOARCHIVO_H
#define ALUMNOARCHIVO_H
#include <cstdio>
#include<cstring>
#include"Alumno.h"

class AlumnoArchivo
{
private:
    char _ruta[30];

   public:
    AlumnoArchivo (const char *ruta);
    AlumnoArchivo ();

    bool agregar(Alumno registro);
    int getCantidad();
    Alumno leerReg(int nroRegistro);
    bool leerTodos(Alumno registros[], int cantidad);
    bool modificarReg(Alumno registro, int nroRegistro);
    int buscarReg(int dni);


};

#endif // ALUMNOARCHIVO_H
