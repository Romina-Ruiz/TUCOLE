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
		cout << "** Ups! Algo salio mal :( **" << endl;
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


void AlumnoManager::ListarXdni()
{
	int dni;

	cout << "Ingrese el dni: ";
	cin >> dni;

	int posicion = _archivo.buscarReg(dni);
	if (posicion >= 0)
	{
		Alumno reg = _archivo.leerReg(posicion);
		Listar(reg);
	}
	else
	{
		cout << "No existe el registro con DNI #" << dni << endl;
	}
}




void AlumnoManager::Editar()
{
	Alumno reg;
	int dni, posicion;
	cout << "DNI a buscar: ";
	cin >> dni;
	cout << endl;

	posicion = _archivo.buscarReg(dni);
	if (posicion >= 0)
	{
		reg = _archivo.leerReg(posicion);
		Listar(reg);
		cout << endl;

		int nuevoEstado;
		cout << "Nuevo estado: ";
		cin >> nuevoEstado;
		reg.setEstado(nuevoEstado);
		_archivo.guardar(reg, posicion);
	}
	else
	{
		cout << "No existe el registro con DNI #" << dni << endl;
	}
}

void AlumnoManager::Eliminar()
{

	Alumno reg;
	int dni, posicion;
	cout << "DNI a buscar: ";
	cin >> dni;
	cout << endl;

	posicion = _archivo.buscarReg(dni);
	if (posicion >= 0)
	{
		reg = _archivo.leerReg(posicion);
		Listar(reg);
		cout << endl;
		reg.setEstado(false);
		_archivo.guardar(reg, posicion);
		cout << "Registro #" << dni << " eliminado correctamente" << endl;
        }
	else	{
		cout << "No existe el registro con DNI #" << dni << endl;
	}
}

void AlumnoManager::HacerCopiaDeSeguridad(){

	int cantidadRegistros = _archivo.getCantidad();
	Alumno *vec = new Alumno[cantidadRegistros];

	if (vec == nullptr){
		cout << "Falla al realizar backup" << endl;
		return;
	}

	_archivo.leer(vec, cantidadRegistros);
	_archivoBkp.vaciar();
	if (_archivoBkp.guardar(vec, cantidadRegistros)){
		cout << "Backup realizado correctamente" << endl;
	}
	else{
		cout << "Falla al realizar backup" << endl;
	}

	delete []vec;
}

void AlumnoManager::RestaurarCopiaDeSeguridad(){

	int cantidadRegistros = _archivoBkp.getCantidad();
	Alumno *vec = new Alumno[cantidadRegistros];

	if (vec == nullptr){
		cout << "Falla al restaurar backup" << endl;
		return;
	}

	_archivoBkp.leer(vec, cantidadRegistros);
	_archivo.vaciar();
	if (_archivo.guardar(vec, cantidadRegistros)){
		cout << "Backup restaurado correctamente" << endl;
	}
	else{
		cout << "Falla al restaurar backup" << endl;
	}

	delete []vec;
}
