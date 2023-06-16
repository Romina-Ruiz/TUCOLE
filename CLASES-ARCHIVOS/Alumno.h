#ifndef ALUMNO_H
#define ALUMNO_H
#include "Persona.h"


class Alumno : public Persona
{
private:
    int _id;
    int _curso;
    bool _activo;

public:
    void setId(int id);
    void setCurso(int curso);
    void setActivo(bool estado);

    int getId();
    int getCurso();
    bool getActivo();


};
#endif // ALUMNO_H
