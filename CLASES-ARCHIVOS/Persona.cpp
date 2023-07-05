#include "Persona.h"
#include <iostream>
#include <string>
#include <cstring>
#include"../MENUS/rlutil.h"
#include"../MENUS/FUNCIONES_FRONT.h"
using namespace std;


void Persona::setNombre(std::string nombre)
{
    strcpy(_nombre,nombre.c_str());
}

void Persona::setApellido( std::string apellido)
{
    strcpy(_apellido,apellido.c_str());
}

void Persona::setEmail( std::string email)
{
    strcpy(_email,email.c_str());
}

void Persona::setTelefono(int telefono)
{
    _telefono = telefono;
}
void Persona::setDNI (int dni)
{

    _DNI=dni;
}

 std::string  Persona::getNombre()
{
     std::string nombre;
     nombre=_nombre;
    return nombre;
}

 std::string  Persona::getApellido()
{
     std::string apellido;
     apellido=_apellido;
    return apellido;
}

 std::string  Persona::getEmail()
{
     std::string  email;
     email=_email;
    return email;
}

int Persona::getTelefono()
{
    return _telefono;
}
int Persona::getDni()
{
    return _DNI;
}




