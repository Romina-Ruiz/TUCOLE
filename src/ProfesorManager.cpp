#include <iostream>
#include "ProfesorManager.h"
#include "Profesor.h"

using namespace std;



void ProfesorManager::Cargar()
{
    int idProfe;
	int idMateria;
	//char materiaAcargo[30];
	bool Activo;

//	cout << "Ingrese el ID: ";
//	cin >> id;

//    if (ExisteId(id))
//    {
//        cout << "ID repetido" << endl;
//        return;
//    }
    idProfe = GenerarId();
    cout << "ID Profesor #" << idProfe << endl;
    cout<<"Ingrese el nombre de la materia a cargo"<<endl;
    cin>>idMateria;
    cout<<"Estado"<<endl;
    cin>>Activo;

	Profesor aux;
	aux.setidprofesor(idProfe);
	aux.setIdMateria(idMateria);
	aux.setEstado(Estado);

	if (_archivo.agregar(aux))
	{
		cout << "Alumno guardada correctamente" << endl;
	}
	else
	{
		cout << "Ups! Algo salio mal :(" << endl;
	}
}

void ProfesorManager::ListarTodos()
{
	int cantidadRegistros = _archivo.getCantidad();

	for (int i = 0; i<cantidadRegistros; i++)
	{
		Profesor reg = _archivo.leer(i);
        if (reg.getActivo()==true)
        {
            Listar(reg);
            cout << endl;
        }
	}
}




void ProfesorManager::ListarXId()
{
	int id;

	cout << "Ingrese el ID: ";
	cin >> id;

	int posicion = _archivo.buscar(id);
	if (posicion >= 0)
	{
		Profesor reg = _archivo.leer(posicion);
		Listar(reg);
	}
	else
	{
		cout << "No existe el registro con ID #" << id << endl;
	}
}

void ProfesorManager::Listar(Profesor profe)
{
	cout << "ID PROFE         : " << Profesor.getidProfesor() << endl;
	cout << "ID MATERIA : " << Profesor.getIdMateria() << endl;
	cout << "Activo      : " << Profesor.getActivo() << endl;
}

void ProfesorManager::Editar()
{
	Profesor reg;
	int id, posicion;
	cout << "ID a buscar: ";
	cin >> id;
	cout << endl;

	posicion = _archivo.buscar(id);
	if (posicion >= 0)
	{
		reg = _archivo.leer(posicion);
		Listar(reg);
		cout << endl;

		int nuevoEstado;
		cout << "Nuevo estado: ";
		cin >> nuevoEstado;
		reg.setActivo(nuevoEstado);
		_archivo.guardar(reg, posicion);
	}
	else
	{
		cout << "No existe el registro con ID #" << id << endl;
	}
}

void ProfesorManager::Eliminar()
{
    /*
    pedir el id
    buscarlo
    cambiar el estado
    guardarlo
    */
	Profesor reg;
	int id, posicion;
	cout << "ID a buscar: ";
	cin >> id;
	cout << endl;

	posicion = _archivo.buscar(id);
	if (posicion >= 0)
	{
		reg = _archivo.leer(posicion);
		Listar(reg);
		cout << endl;
		reg.setActivo(false);
		_archivo.guardar(reg, posicion);
		cout << "Registro #" << id << " eliminado correctamente" << endl;
	}
	else
	{
		cout << "No existe el registro con ID #" << id << endl;
	}
}



bool ProfesorManager::ExisteId(int id)
{
    return _archivo.buscar(id) >= 0;
    /*
    if (_archivo.buscar(id) >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    */
}

int ProfesorManager::GenerarId()
{
    return _archivo.getCantidad() + 1;
    /*
    int proximoId = _archivo.getCantidadRegistros();
    proximoId++;
    return proximoId;
    */
}

//void AlumnoManager::HacerCopiaDeSeguridad(){
//	/*
//		ArchivoDAT = Archivo donde trabajan las acciones del men� (Cargar, Listar, Editar)
//		ArchivoBKP = Archivo de respaldo
//
//		Leer todos los registros ArchivoDAT en un vector din�mico X
//		Vaciar ArchivoBKP X
//		Guardar todos los registros del vector en ArchivoBKP
//
//	*/
//	int cantidadRegistros = _archivo.getCantidadRegistros();
//	Alumno *vec = new Alumno[cantidadRegistros];
//
//	if (vec == nullptr){
//		cout << "Falla al realizar backup" << endl;
//		return;
//	}
//
//	_archivo.leer(vec, cantidadRegistros);
//	_archivoBkp.vaciar();
//	if (_archivoBkp.guardar(vec, cantidadRegistros)){
//		cout << "Backup realizado correctamente" << endl;
//	}
//	else{
//		cout << "Falla al realizar backup" << endl;
//	}
//
//	delete []vec;
//}

//void AlumnoManager::RestaurarCopiaDeSeguridad(){
//	/*
//	ArchivoDAT = Archivo donde trabajan las acciones del men� (Cargar, Listar, Editar)
//	ArchivoBKP = Archivo de respaldo
//
//	Leer todos los registros ArchivoBKP en un vector din�mico
//	Vaciar ArchivoDAT
//	Guardar todos los registros del vector en ArchivoDAT
//
//	*/
//	int cantidadRegistros = _archivoBkp.getCantidadRegistros();
//	Tarea *vec = new Alumno[cantidadRegistros];
//
//	if (vec == nullptr){
//		cout << "Falla al restaurar backup" << endl;
//		return;
//	}
//
//	_archivoBkp.leer(vec, cantidadRegistros);
//	_archivo.vaciar();
//	if (_archivo.guardar(vec, cantidadRegistros)){
//		cout << "Backup restaurado correctamente" << endl;
//	}
//	else{
//		cout << "Falla al restaurar backup" << endl;
//	}
//
//	delete []vec;
//}
