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
    bool modificarReg(Alumno registro, int nroRegistro);
    int buscarReg(int dni);
     bool guardar(Alumno reg, int posicionAReemplazar);
     void leer(Alumno *vec, int cantidadRegistrosALeer);
     bool guardar(Alumno *vec, int cantidadRegistrosAEscribir);
     void vaciar();


};

#endif // ALUMNOARCHIVO_H
