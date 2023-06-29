#ifndef PROFESORMANAGER_H
#define PROFESORMANAGER_H
#include "Profesor.h"
#include "ProfesorArchivo.h"

class ProfesorManager
{
private:


    ProfesorArchivo _archivo;
	ProfesorArchivo _archivoBkp = ProfesorArchivo("Profesor.bkp");

public:



    void Cargar();
    void ListarTodos();
    void ListarXdni();
    void Editar();
    void Eliminar();
    void Listar(Profesor profe);
	void ModificarDatos(Profesor Profesor, int posicion);
	int generarLegajo();
	int buscarDNI(int dni);

    void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // PROFESORMANAGER_H
