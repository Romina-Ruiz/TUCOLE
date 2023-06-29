#ifndef COMUNICADOSMANAGER_H
#define COMUNICADOSMANAGER_H
#include"Comunicados.h"
#include"ComunicadosArchivo.h"

class ComunicadosManager
{
private:

    ComunicadosArchivo _archivo;


public:

    void Cargar();
    int generarID();
    void ComunicadoxDNI();
    void ComunicadoxCurso();
    void EliminarComunicado();
    void BuscarComunicado();
    void cargarCadena(char *pal, int tam);
    void listarxDNI(Comunicados obj);
    void ComunicadosActivos();



};

#endif // COMUNICADOSMANAGER_H
