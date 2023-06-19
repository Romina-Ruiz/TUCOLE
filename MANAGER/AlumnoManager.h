#ifndef ALUMNOMANAGER_H
#define ALUMNOMANAGER_H
#include "Alumno.h"
#include"AlumnoArchivo.h"

class AlumnoManager {

private:
	//AlumnoArchivo _archivo;

public:
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

#endif // ALUMNOMANAGER_H
