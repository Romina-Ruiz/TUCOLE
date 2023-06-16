#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
   protected:
    int _dni;
    char _nombre[50];
    char _apellido[50];
    char _email[50];
    int _telefono;

public:
    Persona();

    void setDni(int dni);
    void setNombre(char *nombre);
    void setApellido(char *apellido);
    void setEmail(char *email);
    void setTelefono(int telefono);

    int getDni();
    char * getNombre();
    char * getApellido();
    char * getEmail();
    int getTelefono();


};

#endif // PERSONA_H
