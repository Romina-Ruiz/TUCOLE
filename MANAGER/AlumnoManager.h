#ifndef ALUMNOMANAGER_H
#define ALUMNOMANAGER_H
#include "Alumno.h"
#include"AlumnoArchivo.h"

class AlumnoManager {

private:
  char _ruta[30];
  AlumnoArchivo _archivo;

public:
    AlumnoManager (char* ruta);
    AlumnoManager();

    int buscarDNI(int dni);
	void Cargar();
	void ListarTodos();
//	void ListarXId();
//	void Editar();
//	void Eliminar();
	void Listar(Alumno alumno);
//	int buscarDNI(int dni);
//	int GenerarId();

//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();


};


#endif // ALUMNOMANAGER_H
