#ifndef PROFESOR_H
#define PROFESOR_H
#include "Persona.h"
#include"../MENUS/Fecha.h"
class Profesor : public Persona
{
private:
    bool _Estado;
    int _Legajo;
    Fecha _Ingreso;

public:

    void setEstado(bool estado);
    void setLegajo(int legajo);
    Fecha setIngreso(Fecha ingreso);

    bool getEstado();
    int getLegajo();
    Fecha getIngreso();

   void cargar(int dni);

};

#endif // PROFESOR_H
