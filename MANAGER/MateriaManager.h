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
    void ListarXanioLectivo(int anio);
    void MenuUserMaterias(int dni);
    int generarId();
    void cargarCadena(char *pal, int tam);

    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();

};

#endif // MATERIAMANAGER_H
