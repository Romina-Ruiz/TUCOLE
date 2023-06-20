#ifndef MATERIAMANAGER_H
#define MATERIAMANAGER_H
#include "Materia.h"
#include "MateriaArchivo.h"

class MateriaManager
{
private:
      char _ruta[30];
     MateriaArchivo _archivo;
public:

    MateriaManager (char* ruta);
    MateriaManager();

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

#endif // MATERIAMANAGER_H
