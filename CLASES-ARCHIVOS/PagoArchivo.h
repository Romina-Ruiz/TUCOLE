#ifndef PAGOARCHIVO_H
#define PAGOARCHIVO_H
#include"Pago.h"

class PagoArchivo
{
   private:

    char _ruta[30];

public:
    PagoArchivo (const char *ruta);
    PagoArchivo();

    bool agregar(Pago registro);
    int getCantidad();
    Pago leerReg(int nroRegistro);
    bool modificarReg(Pago registro, int nroRegistro);
    bool leerTodos(Pago registros[], int cantidad);
    int buscarReg(int dni);
    bool guardar(Pago reg, int posicionAReemplazar);
    void leer(Pago *vec, int cantidadRegistrosALeer);
    bool guardar(Pago *vec, int cantidadRegistrosAEscribir);
    void vaciar();

};

#endif // PAGOARCHIVO_H
