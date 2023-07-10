#ifndef NOTAMANAGER_H
#define NOTAMANAGER_H
#include"Notas.h"
#include"NotasArchivo.h"

class NotaManager
{
private:


    NotasArchivo _archivo;

public:

    void Cargar();
    void ListarTodos();
    void Listar(Notas nota);
    int buscarDNI(int dni);
    void ListarXdni(int dni);
    void Editar();
    void ModificarDatos(int dni, int id, int pos);
    int GenerarID();
    void BuscarNotas();
    int BuscarMaterias(std::string nombreMateria);
    std::string BuscarMateriaxID(int id);

    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();
};

#endif // NOTAMANAGER_H
