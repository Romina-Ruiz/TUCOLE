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

    void Editar();
    void ModificarDatos(Pago pago, int posicion);
//	void Eliminar();
//	void Listar(Alumno alumno);



//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();


};

#endif // PAGOMANAGER_H
