#ifndef NOTASARCHIVO_H
#define NOTASARCHIVO_H
#include "Notas.h"

class NotasArchivo
{
    public:
    void leerNotas(Notas nota[], int cantidad);
    void cargarNotas(Notas nota);
    void guardar(Notas nota);
    int cantidadNotas();
    bool agregar (Notas dto);
//    bool eliminar (Nota);
    int obtenerTamanio();
    int leerDeDisco(int pos);
};

#endif // NOTASARCHIVO_H
