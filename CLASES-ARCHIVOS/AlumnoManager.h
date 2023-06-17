#ifndef ALUMNOMANAGER_H
#define ALUMNOMANAGER_H
#include "Alumno.h"
#include "AlumnoArchivo.h"

class AlumnoManager {
public:
	void Cargar();
	void ListarTodos();
	void ListarXId();
	void Editar();
	void Eliminar();
	void Listar(Alumno alumno);
//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();

private:
	AlumnoArchivo _archivo;
//	AlumnoArchivo _archivoBkp = AlumnoArchivo("alumno.bkp");
	bool ExisteId(int id);
	int GenerarId();
};

#endif // ALUMNOMANAGER_H
