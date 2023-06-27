#ifndef CURSOMANAGER_H
#define CURSOMANAGER_H
#include "Curso.h"
#include "CursoArchivo.h"

class CursoManager{

private:

  CursoArchivo _archivo;
 CursoArchivo _archivoBkp = CursoArchivo("curso.bkp");

public:


    int buscarDNI(int dni);
	void Cargar();
    int generarId();
	void ListarTodos();
	void ListarAlumnosxCurso();

//	void Editar();
//	void Eliminar();
	void Listar(Curso curso);
//	void ModificarDatos(Curso curso, int posicion);
//	bool validarIngreso(int dni);
//
//
//
//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();

};
#endif // CURSOMANAGER_H
