#include <iostream>
#include "AlumnoManager.h"
#include "Alumno.h"
#include "AlumnoArchivo.h"
#include "Persona.h"
#include"../MENUS/rlutil.h"
#include "../MENUS/Fecha.h"

using namespace std;
AlumnoManager::AlumnoManager(char *ruta)
{

    strcpy(_ruta,ruta);
}
AlumnoManager::AlumnoManager()
{

    strcpy(_ruta,"AlumnoManager.dat");

}


void AlumnoManager::Cargar()
{
    char nombre[30], apellido[30], email[30];
	bool Estado;
    int Legajo, telefono;
    int AnioCurso;
    int dni, dia, mes, anio;

    dni = buscarDNI(dni);

    cout << "DNI #" << dni << endl;
    cout << "Ingrese el nombre : "<<endl;
	cin>>nombre;
    cout << "Ingrese el apellido: "<<endl;
	cin >> apellido;
    cout << "Ingrese el email: "<<endl;
	cin >> email;
    cout << "Ingrese el telefono "<<endl;
	cin >> telefono;
    cout << "Ingrese el estado "<<endl;
	cin>>Estado;
	cout << "Ingrese el legajo "<<endl;
	cin>>Legajo;
	cout<<" Anio en curso :"<<endl;
	cin>>AnioCurso;
    cout << "Ingrese día ingreso: "<<endl;
	cin >> dia;
    cout << "Ingrese mes de ingreso: "<<endl;
	cin >> mes;
    cout << "Ingrese año de ingreso: "<<endl;
	cin >> anio;



	Alumno aux;
	aux.setDNI(dni);
	aux.setNombre(nombre);
	aux.setApellido(apellido);
	aux.setEmail(email);
    aux.setTelefono(telefono);
	aux.setEstado(Estado);
	aux.setLegajo(Legajo);
    aux.setIngreso(Fecha(dia, mes, anio));

	if (_archivo.agregar(aux))
	{
		cout << "Alumno guardado correctamente" << endl;
	}
	else
	{
		cout << "Ups! Algo salio mal :(" << endl;
	}
	 system("pause");
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

void AlumnoManager::ListarTodos()
{
    AlumnoArchivo _archivo;
	int cantidadRegistros = _archivo.getCantidad();

	for (int i = 0; i<cantidadRegistros; i++)
	{
		Alumno reg = _archivo.leerReg(i);
        if (reg.getEstado()==true)
        {
            Listar(reg);
            cout << endl;
        }
	}
}
void AlumnoManager::Listar(Alumno alumno)
{

	cout << "ESTADO         : " << alumno.getEstado() << endl;
	cout << "LEGAJO : " << alumno.getLegajo() << endl;
	cout << "ANIO EN CURSO       : " << alumno.getAnioCurso() << endl;
	cout << "FECHA DE INGRESO  : " << alumno.getIngreso().toString()<< endl;


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
