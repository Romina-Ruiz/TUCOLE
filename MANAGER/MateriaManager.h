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
    void ModificarMateria();
    void OpModificar(Materia reg, int pos);
    void Listar(Materia materia);
    void BuscarxID(int id);
    void MenuUserMaterias(int dni);
    int generarId();


    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();

};

#endif // MATERIAMANAGER_H
