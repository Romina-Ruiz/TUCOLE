#ifndef NOTAMANAGER_H
#define NOTAMANAGER_H
#include"Notas.h"
#include"NotasArchivo.h"

class NotaManager
{
private:

    char _ruta[30];

    NotasArchivo _archivo;

public:
    NotaManager (char* ruta);
    NotaManager();

    int buscarDNI(int dni);
    void Cargar();
    //void ListarXdni();
    void Editar();

    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();
};

#endif // NOTAMANAGER_H
