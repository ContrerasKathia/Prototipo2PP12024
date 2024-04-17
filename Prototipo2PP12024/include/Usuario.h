#ifndef USUARIO_H
#define USUARIO_H
//Librerias
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;


class Usuario
{
    private:
    string id,name,contrasenas;
    int estado;
    const string USUARIOADM = "Administrador";
    const string PASSWORD1 = "1234";
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
		bool loginPersona();
        bool buscarLoginPersona(string user, string passw);
};

#endif // USUARIO_H
