#ifndef ALUMNO_H
#define ALUMNO_H
#include "Persona.h"
#include"../MENUS/Fecha.h"

class Alumno : public Persona
{
private:
    bool _Estado;
    int _Legajo;
    int _AnioCurso;
    Fecha _Ingreso;


public:

   void setEstado(bool estado);
   void setLegajo();
   void setAnioCurso(int anio);
   Fecha setIngreso(Fecha ingreso);
   int GenerarId();

    bool getEstado();
    int getLegajo();
    int getAnioCurso();
    Fecha getIngreso();



};
#endif // ALUMNO_H
