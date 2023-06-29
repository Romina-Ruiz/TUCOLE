#ifndef CUOTAMANAGER_H
#define CUOTAMANAGER_H
#include "Cuota.h"
#include "CuotaArchivo.h"


class CuotaManager
{


public:


    int buscarDNI(int dni);
    void Cargar();
    int generarFactura();
    void ListarTodos();
    void ListarxDNI(int dni);
//	void Editar();
//	void Eliminar();
    void Listar(Cuota cuota);
//	int buscarDNI(int dni);


    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();




};

#endif // CUOTAMANAGER_H
