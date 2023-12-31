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
    int generarId(int curso);
	void ListarTodos();
	void ListarAlumnosxCurso(int anio);
	void ListarMateriasxCurso(int anio);
	int buscarDNI(int dni);

	void Editar();
	void Listar(Curso curso);
	void ModificarDatos(Curso curso, int posicion);

	void InformeCursos();
	void InformePromedioCursos();
	void InformeMateriasAprobadas();
	void InformePromedioAlumno();
	float InformePromedioCurso1();
	float InformePromedioCurso2();
	float InformePromedioCurso3();
	void InformePromedioNotas1();
	void InformePromedioNotas2();
	void InformePromedioNotas3();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};
#endif // CURSOMANAGER_H
