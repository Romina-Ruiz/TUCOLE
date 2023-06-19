#include <iostream>
#include "Falta.h"
#include <cstring>


void Falta::setDNIAlumno(int dni)
{

    _DNIalumno = dni;

}
void Falta::setAnioCurso(int aniocurso)
{

    _anio_Curso = aniocurso;


}
void Falta::setFechaAusencia(Fecha fechaausencia)
{

    _fecha_ausencia = fechaausencia;

}
void Falta::setCantidadFaltasAnuales( int faltasanuales)
{

    _cantidad_faltas_anuales = faltasanuales;

}
void Falta::setCantidadFaltasPermitidas(int faltaspermitidas)
{

    _cantidad_faltas_permitidas = faltaspermitidas;

}

char* Falta::getNombreAlumno()
{

    return _nombre_Alumno;
}

int Falta::getidAlumno()
{

    return _id_alumno;

}

int Falta::getAnioCurso()
{

    return _anio_Curso;

}
Fecha Falta::getFechaAusencia()
{

    return _fecha_ausencia;

}
int Falta::getCantidadFaltasAnuales()
{

    return _cantidad_faltas_anuales;

}
int Falta::getCantidadFaltasPermitidas()
{
    return _cantidad_faltas_permitidas;

}
