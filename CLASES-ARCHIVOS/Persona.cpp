#include "Persona.h"
#include <iostream>
#include "cstring"

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

void Persona::cargar(int dni)
{
    if (dni!=0)
    {
        _DNI=dni;
    }
    else{
    cout<<"DNI: "<<endl;
    cin>>_DNI;
        }

    cout<<"NOMBRE: "<<endl;
    cin>>_nombre;
    cout<<"APELLIDO: "<<endl;
    cin>>_apellido;
    cout<<"EMAIL: "<<endl;
    cin>>_email;
    cout<<"TELEFONO: "<<endl;
    cin>>_telefono;


}



