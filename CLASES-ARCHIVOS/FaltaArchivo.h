#ifndef FALTAARCHIVO_H
#define FALTAARCHIVO_H
#include "Falta.h"

class FaltaArchivo
{
    public:
    void leerFaltas(Falta falta[], int cantidad);
   // void cargarFaltas(Falta alumno);
    void guardar(Falta falta);
    int cantidadFaltas();
    bool agregar (Falta dto);
    bool modificar (Falta);
    bool eliminar (Falta dto);
    int obtenerTamanio();
    int leerDeDisco(int pos);
};

#endif // FALTAARCHIVO_H
