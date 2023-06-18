#include <iostream>
#include "AlumnoManager.h"
#include "Alumno.h"
#include "AlumnoArchivo.h"
using namespace std;

const char *RUTA_ALUMNO = "Alumno.dat";

int AlumnoManager::buscarDNI(int dni) {
 AlumnoArchivo ArchAlumno (RUTA_ALUMNO);
 Alumno obj;

 int cantRegArchivo=ArchAlumno.leerTodos();


  for (int i = 0; i < cantRegArchivo; i++)
  {
        obj=ArchAlumno.leerReg(i);

                if (obj.getDni()== dni){
                       return 1;
                    }
                }

return 0;

}

void AlumnoManager::Cargar()
{
        Alumno obj;
        AlumnoArchivo Archivo (RUTA_ALUMNO);
        cout <<"INGRESE DNI: "<<endl;
        cin >>dni <<endl;
        int ok=this->buscarDNI(dni);

        if (ok==0){
        cout "EL ALUMNO YA FUE INGRESADO" <<endl;
        }

       obj.cargar();

       int id = this->GenerarId();
      cout "EL ID DEL ALUMNO ES: " << id <<endl;
      obj.setId(id);
       obj.setActivo(true);

	if (Archivo.agregar(obj))
	{
		cout << "Alumno guardada correctamente" << endl;
	}
	else
	{
		cout << "Ups! Algo salio mal :(" << endl;
	}
}

int AlumnoManager::GenerarId()
{

    AlumnoArchivo Archivo (RUTA_ALUMNO);
    return Archivo.getCantidad() + 1;

}

///
///void AlumnoManager::ListarTodos()
///{
///	int cantidadRegistros = _archivo.getCantidad();
///
///	for (int i = 0; i<cantidadRegistros; i++)
///	{
///		Alumno reg = _archivo.leer(i);
///        if (reg.getActivo()==true)
///        {
///            Listar(reg);
///            cout << endl;
///        }
///	}
///}
///
///
///
///
///void AlumnoManager::ListarXId()
///{
///	int id;
///
///	cout << "Ingrese el ID: ";
///	cin >> id;
///
///	int posicion = _archivo.buscar(id);
///	if (posicion >= 0)
///	{
///		Alumno reg = _archivo.leer(posicion);
///		Listar(reg);
///	}
///	else
///	{
///		cout << "No existe el registro con ID #" << id << endl;
///	}
///}
///
///void AlumnoManager::Listar(Alumno alumno)
///{
///	cout << "ID          : " << alumno.getId() << endl;
///	cout << "Curso : " << alumno.getCurso() << endl;
///	cout << "Activo      : " << alumno.getActivo() << endl;
///}
///
///void AlumnoManager::Editar()
///{
///	Alumno reg;
///	int id, posicion;
///	cout << "ID a buscar: ";
///	cin >> id;
///	cout << endl;
///
///	posicion = _archivo.buscar(id);
///	if (posicion >= 0)
///	{
///		reg = _archivo.leer(posicion);
///		Listar(reg);
///		cout << endl;
///
///		int nuevoEstado;
///		cout << "Nuevo estado: ";
///		cin >> nuevoEstado;
///		reg.setActivo(nuevoEstado);
///		_archivo.guardar(reg, posicion);
///	}
///	else
///	{
///		cout << "No existe el registro con ID #" << id << endl;
///	}
///}
///
///void AlumnoManager::Eliminar()
///{
///    /*
///    pedir el id
///    buscarlo
///    cambiar el estado
///    guardarlo
///    */
///	Alumno reg;
///	int id, posicion;
///	cout << "ID a buscar: ";
///	cin >> id;
///	cout << endl;
///
///	posicion = _archivo.buscar(id);
///	if (posicion >= 0)
///	{
///		reg = _archivo.leer(posicion);
///		Listar(reg);
///		cout << endl;
///		reg.setActivo(false);
///		_archivo.guardar(reg, posicion);
///		cout << "Registro #" << id << " eliminado correctamente" << endl;
///	}
///	else
///	{
///		cout << "No existe el registro con ID #" << id << endl;
///	}
///}
///
///
///
///bool AlumnoManager::ExisteId(int id)
///{
///    return _archivo.buscar(id) >= 0;
///    /*
///    if (_archivo.buscar(id) >= 0)
///    {
///        return true;
///    }
///    else
///    {
///        return false;
///    }

///}



//void AlumnoManager::HacerCopiaDeSeguridad(){
//	/*
//		ArchivoDAT = Archivo donde trabajan las acciones del menú (Cargar, Listar, Editar)
//		ArchivoBKP = Archivo de respaldo
//
//		Leer todos los registros ArchivoDAT en un vector dinámico X
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
//	ArchivoDAT = Archivo donde trabajan las acciones del menú (Cargar, Listar, Editar)
//	ArchivoBKP = Archivo de respaldo
//
//	Leer todos los registros ArchivoBKP en un vector dinámico
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
