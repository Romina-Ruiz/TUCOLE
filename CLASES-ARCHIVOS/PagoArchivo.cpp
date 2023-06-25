#include <cstdio>
#include<cstring>
#include"PagoArchivo.h"

PagoArchivo::PagoArchivo(const char *ruta)
{

    strcpy(_ruta,ruta);
}
PagoArchivo::PagoArchivo()
{

    strcpy(_ruta,"Pago.dat");

}

bool PagoArchivo::agregar(Pago registro)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "ab");
    if (pFile != NULL)
    {
        fwrite(&registro, sizeof(Pago), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

int PagoArchivo::getCantidad()
{
    int cantidad = 0;
    FILE* pFile = fopen(_ruta, "rb");
    if (pFile != NULL)
    {
        fseek(pFile, 0, SEEK_END);
        cantidad = ftell(pFile) / sizeof(Pago);
        fclose(pFile);
    }
    return cantidad;
}


Pago PagoArchivo::leerReg(int nroRegistro)
{

    Pago obj;
    FILE* pFile = fopen(_ruta, "rb");

    if (pFile == NULL)
    {

        return obj;
    }

    fseek(pFile, nroRegistro * sizeof(Pago), SEEK_SET);
    fread(&obj, sizeof(Pago), 1, pFile);
    fclose(pFile);

    return obj;
}



bool PagoArchivo::modificarReg(Pago registro, int nroRegistro)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "rb+");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(Pago), SEEK_SET);
        fwrite(&registro, sizeof(Pago), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}

bool PagoArchivo::leerTodos(Pago registros[], int cantidad)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "rb");
    if (pFile != NULL)
    {
        fread(registros, sizeof(Pago), cantidad, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}



int PagoArchivo::buscarReg(int dni)
{

    int nroRegistro = -1;
    int cantidad = this->getCantidad();

    Pago registro;
    for (int i = 0; i < cantidad; i++)
    {
        registro =this->leerReg(i);
        if (registro.getDNIalumno() == dni)
        {
            nroRegistro = i;
            break;
        }
    }
    return nroRegistro;
}
bool PagoArchivo::guardar(Pago reg, int posicionAReemplazar)
{

    {
        FILE *p = fopen(_ruta, "rb+");

        if (p == NULL)
        {
            return false;
        }

        fseek(p, posicionAReemplazar * sizeof(Pago), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Pago), 1, p);
        fclose(p);
        return pudoEscribir;
    }
}
void PagoArchivo::leer(Pago *vec, int cantidadRegistrosALeer){
	FILE *p = fopen(_ruta, "rb");
	if (p == NULL)
	{
		return ;
	}

	fread(vec, sizeof(Pago), cantidadRegistrosALeer, p);
	fclose(p);
}

void PagoArchivo::vaciar()
{

    FILE *p = fopen(_ruta, "wb");
    if (p == NULL)
    {
        return ;
    }
    fclose(p);


}
