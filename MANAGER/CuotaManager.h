#ifndef CUOTAMANAGER_H
#define CUOTAMANAGER_H
#include "Cuota.h"
#include"CuotaArchivo.h"


class CuotaManager
{

private:



public:


    int buscarDNI(int dni);
    void Cargar();
    int generarFactura();
    void ListarTodos();
    void ListarxDNI(int dni);
    void ListarOrdenadosPorFecha(int mes);
    void MenuUserPagosyCuotas(int dni);
    void Listar(Cuota cuota);
    void MenuInformeCuotas();
    void InformeFacturacion();
    void TotalFacturacion(float m[12][3]);
    void TotalPagos();
    int CuotasCurso(int dni);



    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();




};

#endif // CUOTAMANAGER_H
