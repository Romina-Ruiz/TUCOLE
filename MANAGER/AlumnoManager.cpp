#include <iostream>
#include "AlumnoManager.h"
#include "Alumno.h"
#include "AlumnoArchivo.h"
#include "Persona.h"
#include"../MENUS/rlutil.h"
using namespace std;

AlumnoManager::AlumnoManager(char *ruta)
{

    strcpy(_ruta,ruta);
}
AlumnoManager::AlumnoManager()
{

    strcpy(_ruta,"AlumnoManager.dat");

}

int AlumnoManager::buscarDNI(int dni)
{

    Alumno obj;

    int nroReg=-1;
    int cantRegArchivo=_archivo.getCantidad();


    for (int i = 0; i < cantRegArchivo; i++)
    {
        obj=_archivo.leerReg(i);

        if (obj.getDni()== dni)
        {
            nroReg=i;
            break;
        }
    }

    return nroReg;
}

int AlumnoManager::Cargar()
{
    Alumno obj;
    int dni, nroReg;

    bool agrego = false;

    rlutil::locate(20,8);
    cout<<"DNI: ";
    rlutil::  locate (26,8);
    cin>>dni;

    nroReg = this->buscarDNI(dni);

    if (nroReg!=-1)
    {
        rlutil::locate(28,9);
        cout<<"EL DNI YA EXISTE!";
        system("pause>null");
        return -1;
    }
    obj.cargar(dni);

    if (_archivo.agregar(obj)==true)
    {
        rlutil::locate(28,20);
        cout << "** Alumno guardado correctamente **" << endl;
        system("pause>nul");
    }
    else
    {
        rlutil::locate(28,20);
        cout << "** Ups! Algo salio mal :( **" << endl;
        system("pause>nul");
    }
}

//int AlumnoManager::GenerarId()
//{
//
//    AlumnoArchivo Archivo (RUTA_ALUMNO);
//    return Archivo.getCantidad() + 1;
//
//}

//void AlumnoManager::ListarTodos()
//{
//    AlumnoArchivo ArchAlumno;
//    int cantidadRegistros = ArchAlumno.getCantidad();
//
//    for (int i = 0; i<cantidadRegistros; i++)
//    {
//        Alumno reg = ArchAlumno.leerReg(i);
//        if (reg.getEstado()==true)
//        {
//            Listar(reg);
//            cout << endl;
//        }
//    }
//}

//void AlumbvgbgtnoManager::ListarXId()
//{
//	int id;
//
//	cout << "Ingrese el ID: ";
//	cin >> id;
//
//	int posicion = _archivo.buscar(id);
//	if (posicion >= 0)
//	{
//		Alumno reg = _archivo.leer(posicion);
//		Listar(reg);
//	}
//	else
//	{
//		cout << "No existe el registro con ID #" << id << endl;
//	}
//}



//
//void AlumnoManager::Editar()
//{
//	Alumno reg;
//	int id, posicion;
//	cout << "ID a buscar: ";
//	cin >> id;
//	cout << endl;
//
//	posicion = _archivo.buscar(id);
//	if (posicion >= 0)
//	{
//		reg = _archivo.leer(posicion);
//		Listar(reg);
//		cout << endl;
//
//		int nuevoEstado;
//		cout << "Nuevo estado: ";
//		cin >> nuevoEstado;
//		reg.setActivo(nuevoEstado);
//		_archivo.guardar(reg, posicion);
//	}
//	else
//	{
//		cout << "No existe el registro con ID #" << id << endl;
//	}
//}
//
//void AlumnoManager::Eliminar()
//{
//    /*
///    pedir el id
///    buscarlo
///    cambiar el estado
///    guardarlo
///    */
//	Alumno reg;
//	int id, posicion;
//	cout << "ID a buscar: ";
//	cin >> id;
//	cout << endl;
//
//	posicion = _archivo.buscar(id);
//	if (posicion >= 0)
//	{
//		reg = _archivo.leer(posicion);
//		Listar(reg);
//		cout << endl;
//		reg.setActivo(false);
//		_archivo.guardar(reg, posicion);
//		cout << "Registro #" << id << " eliminado correctamente" << endl;
//        }
//	else	{
//		cout << "No existe el registro con ID #" << id << endl;
//	}
//}
//
//
//bool AlumnoManager::ExisteId(int id)
//{
//    return _archivo.buscar(id) >= 0;
//
////   if (_archivo.buscar(id) >= 0)
////   {
////       return true;
////   }
////   else
////    {
////        return false;
////    }
//
//}
//
//
//
//void AlumnoManager::HacerCopiaDeSeguridad(){
//
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
//
//void AlumnoManager::RestaurarCopiaDeSeguridad(){
//
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
