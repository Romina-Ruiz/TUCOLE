#ifndef MATERIAMANAGER_H
#define MATERIAMANAGER_H
#include "Materia.h"
#include "MateriaArchivo.h"

class MateriaManager
{
private:

     MateriaArchivo _archivo;
     MateriaArchivo _archivoBkp = MateriaArchivo("Materias.bkp");

public:


	void Cargar();
	void ListarTodos();
//	void Editar();
//	void Eliminar();
	void Listar(Materia materia);
    void ListarXanioLectivo();


//	int buscarDNI(int dni);
	int generarId();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // MATERIAMANAGER_H
