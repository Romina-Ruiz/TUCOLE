#ifndef ALUMNO_H
#define ALUMNO_H
#include "Persona.h"
#include"../MENUS/Fecha.h"


class Alumno : public Persona
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




};
#endif // ALUMNO_H
