#include "Persona.h"
#include <iostream>
#include "cstring"
#include"../MENUS/rlutil.h"
#include"../MENUS/FUNCIONES_FRONT.h"
using namespace std;


void Persona::setNombre(char *nombre)
{
    strcpy(_nombre,nombre);
}

void Persona::setApellido(char *apellido)
{
    strcpy(_apellido,apellido);
}

void Persona::setEmail(char *email)
{
    strcpy(_email,email);
}

void Persona::setTelefono(int telefono)
{
    _telefono = telefono;
}
void Persona::setDNI (int dni)
{

    _DNI=dni;
}

char * Persona::getNombre()
{
    return _nombre;
}

char * Persona::getApellido()
{
    return _apellido;
}

char * Persona::getEmail()
{
    return _email;
}

int Persona::getTelefono()
{
    return _telefono;
}
int Persona::getDni()
{
    return _DNI;
}




