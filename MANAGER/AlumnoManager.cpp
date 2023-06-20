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
    int Legajo, telefono,AnioCurso;
    int dni, dia, mes, anio;

    rlutil::locate(20,8);
    cout << "Ingrese DNI #: " <<endl;
    rlutil::locate(35,8);
    cin>>dni;

    int numerodeRegistro=buscarDNI(dni);

    if(numerodeRegistro>0){

        rlutil::locate(20,10);
        cout<<"EL DNI YA EXISTE !!";
        system("pause>nul");
    }
    else {

    rlutil::locate(20,9);
    cout << "Ingrese el nombre: "<<endl;
    rlutil::locate(39,9);
	cin>>nombre;
	rlutil::locate(20,10);
    cout << "Ingrese el apellido: "<<endl;
    rlutil::locate(41,10);
	cin >> apellido;
	rlutil::locate(20,11);
    cout << "Ingrese el email: "<<endl;
    rlutil::locate(38,11);
	cin >> email;
	rlutil::locate(20,12);
    cout << "Ingrese el telefono: "<<endl;
    rlutil::locate(41,12);
	cin >> telefono;
	rlutil::locate(20,13);
   	cout<<"Anio en curso: "<<endl;
	rlutil::locate(35,13);
	cin>>AnioCurso;
	rlutil::locate(20,14);
    cout << "Ingrese día ingreso: "<<endl;
    rlutil::locate(42,14);
	cin >> dia;
	rlutil::locate(20,15);
    cout << "Ingrese mes de ingreso: "<<endl;
    rlutil::locate(45,15);
	cin >> mes;
	rlutil::locate(20,16);
    cout << "Ingrese año de ingreso: "<<endl;
    rlutil::locate(45,16);
	cin >> anio;
	Legajo=this->generarLegajo();
	rlutil::locate(20,17);
	cout << "Legajo: "<<  Legajo <<endl;
    rlutil::locate(20,18);
	 cout << "Estado: "<< "Activo" <<endl;

	Alumno aux;
	aux.setDNI(dni);
	aux.setNombre(nombre);
	aux.setApellido(apellido);
	aux.setEmail(email);
    aux.setTelefono(telefono);
	aux.setEstado(true);
	aux.setLegajo(Legajo);
    aux.setIngreso(Fecha(dia, mes, anio));

	if (_archivo.agregar(aux))
	{
	     rlutil::locate(30,23);
		cout << "** Alumno guardado correctamente **" << endl;
		system("pause>nul");
	}
	else
	{
	     rlutil::locate(30,25);
		cout << "Ups! Algo salio mal :(" << endl;
		system("pause>nul");
	}
}
	 system("pause");

}

int AlumnoManager::buscarDNI(int dni)
{

        return _archivo.buscarReg(dni)>=0;

}

int AlumnoManager::generarLegajo(){

	return _archivo.getCantidad()+1;
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
    cout<<" DNI : " <<alumno.getDni()<<endl;
    cout<<" NOMBRE: "<<alumno.getNombre()<<endl;
    cout<<" APELLIDO: "<<alumno.getApellido()<<endl;
    cout<<" EMAIL :" <<alumno.getEmail()<<endl;
    cout<<" TELEFONO : "<<alumno.getTelefono()<<endl;
    cout << "ESTADO         : " << alumno.getEstado() << endl;
	cout << "LEGAJO : " << alumno.getLegajo() << endl;
	cout << "ANIO EN CURSO    : " << alumno.getAnioCurso() << endl;
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
