#ifndef NOTAMANAGER_H
#define NOTAMANAGER_H
#include"Notas.h"
#include"NotasArchivo.h"

class NotaManager
{
private:


    NotasArchivo _archivo;

public:


    int buscarDNI(int dni);
    void Cargar();
    void ListarTodos();
    void Listar(Notas nota);
    void ListarXdni();
    void Editar();

    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();
};

#endif // NOTAMANAGER_H
