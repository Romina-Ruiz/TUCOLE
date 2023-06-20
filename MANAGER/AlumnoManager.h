#ifndef ALUMNOMANAGER_H
#define ALUMNOMANAGER_H
#include "Alumno.h"
#include"AlumnoArchivo.h"
#include "Persona.h"
class AlumnoManager {

private:
  char _ruta[30];
  AlumnoArchivo _archivo;
  	AlumnoArchivo _archivoBkp = AlumnoArchivo("alumnos.bkp");

public:
    AlumnoManager (char* ruta);
    AlumnoManager();

    int buscarDNI(int dni);
	void Cargar();
	int generarLegajo();
	void ListarTodos();
	void ListarXdni();
	void Editar();
	void Eliminar();
	void Listar(Alumno alumno);



	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();


};


#endif // ALUMNOMANAGER_H
