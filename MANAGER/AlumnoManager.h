#ifndef ALUMNOMANAGER_H
#define ALUMNOMANAGER_H
#include "Alumno.h"
#include "AlumnoArchivo.h"

class AlumnoManager {

private:
	AlumnoArchivo _archivo;
	bool ExisteId(int id);
	int GenerarId();

public:
    void buscarDNI(Alumno obj, int dni);
	void Cargar();
	void ListarTodos();
	void ListarXId();
	void Editar();
	void Eliminar();
	void Listar(Alumno alumno);

//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();


};

#endif // ALUMNOMANAGER_H
