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
    Comunicados leerReg(int nroRegistro);
    bool modificarReg(Comunicados registro, int nroRegistro);


//    bool eliminar(Comunicados dto);
    void vaciar();

};

#endif // COMUNICADOSARCHIVO_H
