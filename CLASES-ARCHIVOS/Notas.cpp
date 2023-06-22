#include <iostream>
#include "Notas.h"
#include <cstring>


void Notas::setDNIalumno(int dni)
{
    _DNIalumno=dni;

}

void Notas::setIdMateria(int materia)
{
    _idMateria = materia;

}
void Notas::setTipoNota(int tipo)
{
    _tipoNota = tipo;

}
void Notas::setNota(float nota)
{
    _nota=nota;

}

int Notas::getDNIalumno()
{

    return _DNIalumno;
}

int Notas::getIdMateria()
{

    return _idMateria;
}

int Notas::getTipoNota()
{
    return _tipoNota;
}

float Notas::getNota(){

    return _nota;

}
