#include <iostream>
#include <string>
#include <cstring>
#include "Notas.h"


void Notas::setDNIalumno(int dni)
{
    _DNIalumno=dni;

}

void Notas::setIDMateria(int id)
{
        _IDmateria=id;
}

void Notas::setNroExamen(int nro)
{
  _Nro_examen = nro;

}
void Notas::setNota(float nota)
{
    _nota=nota;

}

void Notas::setIDNota(int idnota){

    _IDNota=idnota;

}
void Notas::setEliminada(bool eliminada){

_eliminada = eliminada;
}

int Notas::getDNIalumno()
{

    return _DNIalumno;
}

 int Notas::getIDMateria()
{

    return _IDmateria;

}

int Notas::getNroExamen()
{
    return _Nro_examen;
}

float Notas::getNota()
{

    return _nota;

}

int Notas::getIDNota(){

    return _IDNota;
}
bool Notas::getEliminada(){

return _eliminada;
}
