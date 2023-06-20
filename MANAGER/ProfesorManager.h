#ifndef PROFESORMANAGER_H
#define PROFESORMANAGER_H
#include "Profesor.h"
#include "ProfesorArchivo.h"

class ProfesorManager
{

public:
    ProfesorManager (char* ruta);
    ProfesorManager();

    void Cargar();
    void ListarTodos();
    void ListarXId();
    void Editar();
    void Eliminar();
    void Listar(Profesor profe);
//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();

private:
    char _ruta[30];


    ProfesorArchivo _archivo;
//	AlumnoArchivo _archivoBkp = AlumnoArchivo("alumno.bkp");
    bool ExisteId(int id);
    int GenerarId();
};

#endif // PROFESORMANAGER_H
