#ifndef PERSONA_H
#define PERSONA_H
#include <string>


class Persona
{
   protected:
    char _nombre[50];
    char _apellido[50];
    char _email[50];
    int _telefono;
    int _DNI;


public:

    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setEmail(std::string email);
    void setTelefono(int telefono);
    void setDNI(int dni);



    std::string getNombre();
    std::string getApellido();
    std::string getEmail();
    int getTelefono();
    int getDni();



};

#endif // PERSONA_H
