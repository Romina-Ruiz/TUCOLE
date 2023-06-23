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
    void ListarXdni(Pago pago);
    void Listar(Pago pago);
   int buscarDNI(int dni);
   void ListarTodos();

//	void Editar();
//	void Eliminar();
//	void Listar(Alumno alumno);



//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();


};

#endif // PAGOMANAGER_H
