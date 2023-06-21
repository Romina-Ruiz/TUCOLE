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
    void ListarXdni();
    void Editar();
    void Eliminar();
    void Listar(Profesor profe);
//	void HacerCopiaDeSeguridad();
//	void RestaurarCopiaDeSeguridad();
	void ModificarDatos(Profesor Profesor, int posicion);
	int generarLegajo();
	int buscarDNI(int dni);

private:
    char _ruta[30];


    ProfesorArchivo _archivo;
//	ProfesorArchivo _archivoBkp = ProfesorArchivo("profesor.bkp");


};

#endif // PROFESORMANAGER_H
