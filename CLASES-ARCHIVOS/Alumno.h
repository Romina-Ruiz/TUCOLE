#ifndef ALUMNO_H
#define ALUMNO_H
#include "Persona.h"


class Alumno : public Persona
{
private:
    int _dni;
    int _id;
    bool _activo;

public:
   void setDni(int dni);
    void setId(int id);
    void setActivo(bool estado);
    void cargar();

    int getDni();
    int getId();
    bool getActivo();


};
#endif // ALUMNO_H
