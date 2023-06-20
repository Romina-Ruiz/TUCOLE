#ifndef CUOTAMANAGER_H
#define CUOTAMANAGER_H
#include "Cuota.h"
#include "CuotaArchivo.h"

class CuotaManager
{
private:

  char _ruta[30];
 // CuotaArchivo _archivo;

public:

    CuotaManager (char* ruta);
    CuotaManager();


    int buscarDNI(int dni);
    int Cargar();
//	void ListarTodos();
//	void ListarXId();
//	void Editar();
//	void Eliminar();
//	void Listar(Alumno alumno);
//	int buscarDNI(int dni);
//	int GenerarId();

//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();




};

#endif // CUOTAMANAGER_H
