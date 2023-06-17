#ifndef PROFESOR_H
#define PROFESOR_H
#include "Persona.h"

class Profesor : public Persona
{
    private:
        int _id_profesor;
        int _id_materia;
      //  char _materia_a_cargo[30];
        bool _activo;

    public:

    void setidprofesor(int id);
    void setIdMateria(int idMateria);
   // void setMateriaAcargo(char *materia);
    void setActivo(bool activo);
    int getidProfesor();
    int getIdMateria();
    //char *getMateriaAcargo();
    bool getActivo();

};

#endif // PROFESOR_H
