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
    void listar(Comunicados obj);
    void ComunicadosActivos();
    void ListarTodos();
    void ComunicadoUser(int dni);
    int BuscarCurso(int dni);


    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();



};

#endif // COMUNICADOSMANAGER_H
