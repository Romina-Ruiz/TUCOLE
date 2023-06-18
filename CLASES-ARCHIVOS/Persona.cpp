#include "Persona.h"
#include <iostream>
#include <windows.h>



char vacio[50] {"vacio"};

Persona::Persona()
{
    _dni=0;
    strcpy(vacio,_nombre);
    strcpy(vacio,_apellido);
    strcpy(vacio,_email);
    _telefono=0;
}


void Persona::setDni(int val)
{
    _dni = val;
}

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


int Persona::getDni()
{
    return _dni;
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

void Persona::cargar(){

    cout << "DNI          : " << endl;
    cin>>dni;
    cout<<"NOMBRE   : "<<endl;
    cin>>nombre;
    cout<<"APELLIDO : "<<endl;
    cin>>apellido;
    cout<<"EMAIL       : "<<endl;
    cin>>email;
    cout<<"TELEFONO: "<<endl;
    cin>>telefono;

}



