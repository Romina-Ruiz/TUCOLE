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

void Alumno::setLegajo(int legajo)
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


int GenerarId(){

    AlumnoArchivo Archivo ("Alumno.dat");
    return Archivo.getCantidad() + 1;

}
