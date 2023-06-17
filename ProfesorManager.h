#ifndef PROFESORMANAGER_H
#define PROFESORMANAGER_H
#include "Profesor.h"
#include "ProfesorArchivo.h"


class ProfesorManager
{
    public:
	void Cargar();
	void ListarTodos();
	void ListarXId();
	void Editar();
	void Eliminar();
	void Listar(Profesor profe);
//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();

private:
	ProfesorArchivo _archivo;
//	AlumnoArchivo _archivoBkp = AlumnoArchivo("alumno.bkp");
	bool ExisteId(int id);
	int GenerarId();
};


#endif // PROFESORMANAGER_H
