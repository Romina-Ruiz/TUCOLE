#ifndef PROFESOR_H
#define PROFESOR_H
#include "Persona.h"

class Profesor : public Persona
{
    private:
        int _id;
        char _materia_a_cargo[30];
        bool _estado;

    public:

    void setId(int id);
    void setMateriaAcargo(char *materia);
    void setEstado(bool estado);

    int getId();
    char *getMateriaAcargo();
    bool getEstado();

};

#endif // PROFESOR_H
