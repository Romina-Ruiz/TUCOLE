#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
   protected:
    char _nombre[50];
    char _apellido[50];
    char _email[50];
    int _telefono;
    int _DNI;


public:

    void setNombre(char *nombre);
    void setApellido(char *apellido);
    void setEmail(char *email);
    void setTelefono(int telefono);
    void setDNI(int dni);



    char * getNombre();
    char * getApellido();
    char * getEmail();
    int getTelefono();
    int getDni();



};

#endif // PERSONA_H
