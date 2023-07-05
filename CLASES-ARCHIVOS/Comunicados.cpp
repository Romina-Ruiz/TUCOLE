#include <iostream>
#include <string>
#include <cstring>
#include "Comunicados.h"

void Comunicados::setIdComunicado(int idcomunicado)
{


    _id_comunicado = idcomunicado;

}
void Comunicados::setDNIalumno(int dni)
{

    _DNIalumno = dni;

}
void Comunicados::setIdMateria(int id)
{

    _id_materia = id;

}
void Comunicados::setAnioCurso(int curso)
{

    _anio_curso = curso;

}

void Comunicados::setFechaComunicado(Fecha fecha)
{

    _fechaComunicado= fecha;

}

void Comunicados::setEliminado(bool eliminado)
{

    _eliminado = eliminado;
}
void Comunicados::setComunicado(std::string comunicado)
{

    strcpy(_comunicado,comunicado.c_str());

}

int Comunicados::getIdComunicado()
{

    return _id_comunicado;
}
int Comunicados::getDni()
{

    return _DNIalumno;

}

int Comunicados::getIdMateria()
{

    return _id_materia;

}
int Comunicados::getAnioCurso()
{
    return _anio_curso;

}
Fecha Comunicados::getFechaComunicado()
{
    return _fechaComunicado;

}
bool Comunicados::getEliminado()
{

    return _eliminado;
}

std::string Comunicados::getComunicado()
{
    std::string comunicado;
    comunicado=_comunicado;
    return comunicado;
}
