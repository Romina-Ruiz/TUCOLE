#ifndef MATERIAARCHIVO_H
#define MATERIAARCHIVO_H
#include "Materia.h"

class MateriaArchivo
{
   public:
    void leerMaterias(Materia materia[], int cantidad);
//    void cargarMaterias(Materia materia);
    void guardar(Materia materia);
    int cantidadMaterias();
    bool agregar (Materia);
    bool eliminar(Materia dto);
    int obtenerTamanio();
    int leerDeDisco(int pos);



};

#endif // MATERIAARCHIVO_H
