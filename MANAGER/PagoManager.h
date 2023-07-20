#ifndef PAGOMANAGER_H
#define PAGOMANAGER_H
#include "Pago.h"
#include "PagoArchivo.h"

class PagoManager
{
private:

    PagoArchivo _archivo;
    PagoArchivo _archivoBkp = PagoArchivo("Pagos.bkp");


public:


    int buscarReg(int dni);
    void Cargar();
    int generarPago();
    void Listar(Pago pago);
    int buscarDNI(int dni);
    void ListarTodos();
    void ListarOrdenadosPorFecha(int mes);
    void Ordenar(Pago *vec, int cantidadRegistros, int mes);
    void MenuInformePagos();
    void ListarxDNI(int dni);
    void EliminarPago();





    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();


};

#endif // PAGOMANAGER_H
