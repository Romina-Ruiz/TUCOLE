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
    void leer(Curso *vec, int cantidadRegistrosALeer);
    bool guardar(Curso *vec, int cantidadRegistrosAEscribir);
    bool guardar(Curso reg, int posicionAReemplazar);
    int buscarCurso(int curso);
    int buscarIDcurso(int id);

    void vaciar();
};

#endif // CURSOARCHIVO_H
