#include "MenuGeneral.h"
#include "cliente.h"
#include "usuario.h"
#include <cstdlib>
using namespace std;

MenuGeneral::MenuGeneral()
{

}

//Muestra el menu principal
void MenuGeneral::menuPrincipal()
{
    system("cls");
    int options;
    bool repetir = true;
    do {
    cout << "\n\t\tKathia Nicolle Contreras Rosales 9959-23-8246" << endl;
    cout << "\n\n\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tMENU GENERAL " << endl;
    cout << "\t\t---------------------------------------------" << endl;

    cout << "\n\n\t\t1. Catalogos " << endl;
    cout << "\t\t2. Informes " << endl;
    cout << "\t\t3. Salir del Sistema" << endl;

    cout<<"\n\n\t\t-------------------------------"<<endl;
	cout<<"\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t-------------------------------"<<endl;
	cout<<"\n\n\t\tIngresa tu Opcion: ";
    cin>>options;
    system("cls");

    switch (options)
    {
case 1:
    subMenuCatalogos();
    break;
case 2:
    subMenuInformes();
    break;
case 3:
    exit(0);

default:
    cout << "Opcion invalida. Intente otra vez.";
    }
    } while (options != 3);
}

//Muestra el submenu Catalogos
void MenuGeneral::subMenuCatalogos()
{
    Usuario rama;
    rama.menu();
}

//Muestra los archivos de informe
void MenuGeneral::subMenuInformes()
{
    Usuario rama; //clase persona objeto rama cambiar clase ahora es cliente
    rama.desplegar();
}
