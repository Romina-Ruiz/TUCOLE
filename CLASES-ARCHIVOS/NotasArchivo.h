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
    bool modificar(Notas registro, int nroRegistro);
    bool guardar(Notas *vec, int cantidadRegistrosAEscribir);
    void leer(Notas *vec, int cantidadRegistrosALeer);
    int buscarReg(int dni);
    int buscarReg(int dni, int id);
    void vaciar();



};

#endif // NOTASARCHIVO_H
