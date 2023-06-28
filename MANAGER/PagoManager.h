#ifndef PAGOMANAGER_H
#define PAGOMANAGER_H
#include "Pago.h"
#include "PagoArchivo.h"

class PagoManager
{
private:

    PagoArchivo _archivo;


public:


    int buscarReg(int dni);
    void Cargar();
    int generarPago();
    void ListarXdni();
    void Listar(Pago pago);
    int buscarDNI(int dni);
    void ListarTodos();
    void ListarOrdenadosPorFecha(int mes);
    void Ordenar(Pago *vec, int cantidadRegistros, int mes);
    void MenuInformePagos();
    void Editar();
    void ModificarDatos(Pago pago, int posicion);




//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();


};

#endif // PAGOMANAGER_H
