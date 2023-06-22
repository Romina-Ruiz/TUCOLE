#ifndef NOTASARCHIVO_H
#define NOTASARCHIVO_H
#include "Notas.h"
#include"NotasArchivo.h"

class NotasArchivo
{
private:
    char _ruta[30];

public:
    NotasArchivo (const char *ruta);
    NotasArchivo();

    bool agregar(Notas dto);
    int getCantidad();
    Notas leerReg(int nroRegistro);
    void leerTodos(Notas nota[], int cantidad);
    bool modificar(Notas registro, int nroRegistro);
    bool guardarTodos(Notas*vec, int cantidadRegistrosAEscribir);
    int buscarReg(int dni);
    void vaciar();

};

#endif // NOTASARCHIVO_H
