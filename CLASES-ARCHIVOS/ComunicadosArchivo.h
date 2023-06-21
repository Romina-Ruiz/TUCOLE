#ifndef COMUNICADOSARCHIVO_H
#define COMUNICADOSARCHIVO_H
#include "Comunicados.h"


class ComunicadosArchivo
{
private :

    char _ruta[30];

public:
    ComunicadosArchivo (const char *ruta);
    ComunicadosArchivo();

    int getCantidad();
    bool agregar (Comunicados dto);
//    bool eliminar(Comunicados dto);
    void vaciar();

};

#endif // COMUNICADOSARCHIVO_H
