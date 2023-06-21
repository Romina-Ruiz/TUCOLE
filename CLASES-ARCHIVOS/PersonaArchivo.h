#ifndef PERSONAARCHIVO_H
#define PERSONAARCHIVO_H
#include "Persona.h"


class PersonaArchivo
{

private:

char _ruta[30];
public:

    void leerAlumnos(Persona alumno[], int cantidad);
    void guardar(Persona alumno);
    int cantidadAlumnos();
    bool existe(const char*);
    bool agregar (Persona);
    bool modificar (Persona);
    bool eliminar (Persona);
    int obtenerTamanio();
    Persona buscarRegistro(int, int);
    Persona obtenerPorDNI (int);
    int leerDeDisco(int pos);
};



#endif // PERSONAARCHIVO_H
