#include <iostream>
#include "FaltaArchivo.h"
#include "Falta.h"

using namespace std;



FaltaArchivo::FaltaArchivo(const char *ruta){

    strcpy(_ruta,ruta);
}
 FaltaArchivo::FaltaArchivo(){

    strcpy(_ruta,"Faltas.dat");

 }

bool FaltaArchivo::agregar(Falta reg)
{
    bool ok = false;
    FILE* pFile = fopen(_ruta, "ab");
    if (pFile != NULL)
    {
        fwrite(&reg, sizeof(Falta), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}
bool FaltaArchivo::guardar(Falta reg, int posicionAReemplazar)
{

    {
        FILE *p = fopen(_ruta, "rb+");

        if (p == NULL)
        {
            return false;
        }

        fseek(p, posicionAReemplazar * sizeof(Falta), SEEK_SET);
        bool pudoEscribir = fwrite(&reg, sizeof(Falta), 1, p);
        fclose(p);
        return pudoEscribir;
    }
}

int FaltaArchivo::getCantidad()
{
    FILE *p;
    int cantidad=0;
    p=fopen(_ruta,"rb");

    if (p==nullptr)
    {
        return 0;
    }

    fseek(p,0,SEEK_END);
    cantidad=ftell(p)/sizeof(Falta);
    fclose (p);

    return cantidad;
}


Falta FaltaArchivo::leerReg(int nroReg)
{

    Falta obj;
    FILE* pFile = fopen(_ruta, "rb");

    if (pFile == NULL)

        {
            return obj;
        }

        fseek(pFile, nroReg * sizeof(Falta), SEEK_SET);
        fread(&obj, sizeof(Falta), 1, pFile);
        fclose(pFile);

        return obj;

}


bool FaltaArchivo::leerTodos(Falta falta[], int cantidad)
{

    bool ok = false;
    FILE* pFile = fopen(_ruta, "rb");
    if (pFile != NULL)
    {
        fread(falta, sizeof(Falta), cantidad, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;

}


bool FaltaArchivo:: modificar(Falta registro, int nroRegistro)
{
     bool ok = false;
    FILE* pFile = fopen(_ruta, "rb+");
    if (pFile != NULL)
    {
        fseek(pFile, nroRegistro * sizeof(Falta), SEEK_SET);
        fwrite(&registro, sizeof(Falta), 1, pFile);
        fclose(pFile);
        ok = true;
    }
    return ok;
}


int FaltaArchivo::buscarReg(int dni)
{
    int nroRegistro = -1;
    int cantidad = this->getCantidad();

    Falta registro;
    for (int i = 0; i < cantidad; i++)
    {
        registro =this->leerReg(i);
        if (registro.getDNIAlumno() == dni)
        {
            nroRegistro = i;
            break;
        }
    }
    return nroRegistro;

}
void FaltaArchivo::vaciar(){
	FILE *p = fopen(_ruta, "wb");
	if (p == NULL)
	{
		return ;
	}
	fclose(p);
}

