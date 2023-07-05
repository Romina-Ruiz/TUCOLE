#include <iostream>
#include <string>
#include <cstring>
#include "Notas.h"



void Notas::setDNIalumno(int dni)
{
    _DNIalumno=dni;

}
void Notas::setNombreMateria( std::string nombremateria)
{

     strcpy(_nombre_materia,nombremateria.c_str());
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
 std::string  Notas::getNombreMateria()
{
     std::string nombre_materia;
     nombre_materia= _nombre_materia;
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
