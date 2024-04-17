#ifndef CLIENTE_H
#define CLIENTE_H
//Librerias
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

class Cliente
{
    private:
    string id,name,tipo,apellido,nit,telefono,direccion,correo;
    int estado;
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};

#endif // CLIENTE_H
