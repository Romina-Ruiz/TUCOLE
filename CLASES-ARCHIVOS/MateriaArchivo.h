#ifndef MATERIAARCHIVO_H
#define MATERIAARCHIVO_H
#include "Materia.h"

class MateriaArchivo
{
private:
    char _ruta[30];

public:
    MateriaArchivo (const char *ruta);
    MateriaArchivo ();


public:

    bool agregar (Materia registro);
    int getCantidad();
    Materia leerReg(int nroRegistro);
    void leerTodos(Materia materia[], int cantidad);
    bool modificar(Materia registro, int nroRegistro);
    void vaciar();





};

#endif // MATERIAARCHIVO_H
