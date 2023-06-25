#ifndef CURSOARCHIVO_H
#define CURSOARCHIVO_H
#include "Curso.h"

class CursoArchivo
{
    private:

    char _ruta[30];

public:
    CursoArchivo (const char *ruta);
    CursoArchivo();

    bool agregar(Curso registro);
    int getCantidad();
    Curso leerReg(int nroRegistro);
    bool modificarReg(Curso registro, int nroRegistro);
    bool leerTodos(Curso registros[], int cantidad);
    int buscarReg(int dni);
    void vaciar();
};

#endif // CURSOARCHIVO_H
