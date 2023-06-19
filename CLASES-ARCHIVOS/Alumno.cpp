#include <iostream>
#include "Alumno.h"
#include"../MENUS/Fecha.h"

using namespace std;


void Alumno::setEstado(bool estado)
{
    _Estado = estado;
}

void Alumno::setLegajo(int legajo)
{
    _Legajo= legajo;
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
    cout <<"LEGAJO: "<<endl;
    cin >>_Legajo;
    cout <<"ANIO EN CURSO: "<<endl;
    cin >>_AnioCurso;
    cout <<"FECHA INGRESO: "<<endl;
    //cin >> _Ingreso;


}
