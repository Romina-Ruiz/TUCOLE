#ifndef FALTAMANAGER_H
#define FALTAMANAGER_H
#include"Falta.h"
#include"FaltaArchivo.h"

class FaltaManager
{
private:
     char _ruta[30];
    FaltaArchivo _archivo;

public:
    FaltaManager(const char *ruta);
    FaltaManager();

    int buscarDNI(int dni);
    int Cargar();
//	void ListarTodos();
//	void ListarXId();
//	void Editar();
//	void Eliminar();
//	void Listar(Alumno alumno);


//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();

};

#endif // FALTAMANAGER_H
