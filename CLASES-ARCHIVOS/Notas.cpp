#include <iostream>
#include "Notas.h"
#include <cstring>


void Notas::setDNIalumno(int dni)
{
    _DNIalumno=dni;

}
void Notas::setNombreMateria(char* nombremateria)
{

     strcpy(_nombre_materia,nombremateria);
}
void Notas::setNroExamen(int nro)
{
  _Nro_examen = nro;

}
void Notas::setNota(float nota)
{
    _nota=nota;

}
void Notas::setEliminada(bool eliminada){

_eliminada = eliminada;
}

int Notas::getDNIalumno()
{

    return _DNIalumno;
}
char * Notas::getNombreMateria()
{
    return _nombre_materia;

}

int Notas::getNroExamen()
{
    return _Nro_examen;
}

float Notas::getNota()
{

    return _nota;

}
bool Notas::getEliminada(){

return _eliminada;
}
