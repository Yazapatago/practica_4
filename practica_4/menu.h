#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "router.h"
#include <cstdlib>

class Menu
{
private:
    Router router;
    char comando;
    void MenuAgregarRouter();
    void MenuCargarRouterArchivo();
    void MenuEnviarPaquetes();
    void MenuGenerarAutomaticamente();
    void MenuPintarMapa();
public:
    Menu();
    void MostrarMenu();
};

#endif // MENU_H
