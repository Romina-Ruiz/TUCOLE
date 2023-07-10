#ifndef CURSOMANAGER_H
#define CURSOMANAGER_H
#include "Curso.h"
#include "CursoArchivo.h"

class CursoManager{

private:

  CursoArchivo _archivo;
  CursoArchivo _archivoBkp = CursoArchivo("curso.bkp");

public:

	void Cargar();
    int generarId();
	void ListarTodos();
	void ListarAlumnosxCurso(int anio);
	void ListarMateriasxCurso(int anio);
	int buscarDNI(int dni);

	void Editar();
//	void Eliminar();
	void Listar(Curso curso);
	void ModificarDatos(Curso curso, int posicion);
//	bool validarIngreso(int dni);

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};
#endif // CURSOMANAGER_H
