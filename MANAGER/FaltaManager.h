#ifndef FALTAMANAGER_H
#define FALTAMANAGER_H
#include"Falta.h"
#include"FaltaArchivo.h"

class FaltaManager
{
private:

    FaltaArchivo _archivo;
    FaltaArchivo _archivoBkp = FaltaArchivo("faltas.bkp");

public:


    int buscarDNI(int dni);
    void Cargar();
	void ListarTodos();
	void Listar(Falta falta);
	void ListarXdni();
    void Editar();
    void ModificarDatos(Falta obj, int posicion);
    void AusenciasXfecha();
    void ListarOrdenadosPorFecha();
    void Ordenar(Falta *vec, int cantidadRegistros);
    int BuscarFalta(int dia,int mes,int anio);

//	void Eliminar();
//	void Listar(Alumno alumno);


	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // FALTAMANAGER_H
