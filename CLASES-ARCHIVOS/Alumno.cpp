#include <iostream>
#include "Alumno.h"
#include"../MENUS/Fecha.h"
#include"../MENUS/rlutil.h"
#include"AlumnoArchivo.h"
#include "Persona.h"

using namespace std;

//const char *RUTA_ALUMNO = "Alumno.dat";


void Alumno::setEstado(bool estado)
{
    _Estado = estado;
}

void Alumno::setLegajo()
{
       // _Legajo=this->GenerarId();
}

void Alumno::setAnioCurso(int anio)
{
    _AnioCurso = anio;
}
Fecha Alumno::setIngreso(Fecha ingreso)
{
    _Ingreso= ingreso;
}

bool Alumno::getEstado()
{
    return _Estado;
}
int Alumno::getLegajo()
{
    return _Legajo;
}

int Alumno::getAnioCurso()
{
    return _AnioCurso;
}
Fecha Alumno::getIngreso()
{
    return _Ingreso;
}
void Alumno::cargar(int dni)
{
    _Estado=true;
    Persona::cargar(dni);
    rlutil::locate(20,13);
    cout <<"LEGAJO: "<<endl;
    rlutil::locate(29,13);
   cout <<_Legajo <<endl;
    rlutil::locate(20,14);
    cout <<"ANIO EN CURSO: "<<endl;
    rlutil::locate(36,14);
    cin >>_AnioCurso;
    rlutil::locate(20,15);
    cout <<"FECHA INGRESO: "<<endl;
    rlutil::locate(37,15);
    //cin >> _Ingreso;


}
void Alumno::Mostrar(int dni){

    Persona::Mostrar(dni);

    cout<<"NOMBRE: "   <<_nombre;
    cout<<"APELLIDO: " <<_apellido;
    cout<<"EMAIL: "    <<_email;
   cout<<"TELEFONO: " <<_telefono;
}

int GenerarId(){

    AlumnoArchivo Archivo ("Alumno.dat");
    return Archivo.getCantidad() + 1;

}
