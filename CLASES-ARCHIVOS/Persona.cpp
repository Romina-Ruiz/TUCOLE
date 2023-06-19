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

void Persona::cargar(int dni)
{


    if (dni!=0)
    {
        _DNI=dni;
    }
    else
    {
        rlutil::locate(20,8);
        cout<<"DNI: "<<endl;
        rlutil::locate(26,8);
        cin>>_DNI;
    }
    rlutil::locate(20,9);
    cout<<"NOMBRE: "<<endl;
    rlutil::locate(29,9);
    cin>>_nombre;
    rlutil::locate(20,10);
    cout<<"APELLIDO: "<<endl;
    rlutil::locate(31,10);
    cin>>_apellido;
    rlutil::locate(20,11);
    cout<<"EMAIL: "<<endl;
    rlutil::locate(28,11);
    cin>>_email;
    rlutil::locate(20,12);
    cout<<"TELEFONO: "<<endl;
    rlutil::locate(32,12);
    cin>>_telefono;


}



