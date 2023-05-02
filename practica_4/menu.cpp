
#include "menu.h"

using namespace std;

Menu::Menu()
{
    this->router = Router();
}

void Menu::MenuAgregarRouter()
{
    bool salirAgregar = false;
    vector<Node> conexiones;
    char comandoSalirMenu;

    while(!salirAgregar)
    {
        // limpiar la consola
        system("cls");

        vector<char> letrasPermitidas;
        for(int i = 'A'; i <= 'Z';i++)
            letrasPermitidas.push_back(i);

        char indice;

        bool verificacionIndice = false;
        while(!verificacionIndice){
            cout << "Agregue un indice valido [A-Z]" << endl;
            cin >> indice;

            for(int i = 0; i < letrasPermitidas.size(); i++)
                if(indice == letrasPermitidas[i])
                    verificacionIndice = true;
        }

        bool salirAgregarConexiones = false;

        while(!salirAgregarConexiones){
            char indiceConexion;
            char instruccionSalir;
            string pesoPaquete;

            verificacionIndice = false;
            while(!verificacionIndice){
                cout << "Agregar indice de conexion cercana a " << indice << endl;
                cin >> indiceConexion;

                for(int i = 0; i < letrasPermitidas.size(); i++)
                    if(indiceConexion == letrasPermitidas[i])
                        verificacionIndice = true;
            }

            cout << "Agregar peso de paquete entre la conexion " << indice << " - " << indiceConexion << endl;
            cin >> pesoPaquete;

            conexiones.push_back(Node(indiceConexion, stoi(pesoPaquete)));

            cout << "[1] para salir de las conexiones del Router " << indice << endl;
            cin >> instruccionSalir;

            if(instruccionSalir == '1')
            {
                salirAgregarConexiones = true;
            }
        }

        this->router.AgregarNodo(indice, conexiones);
        conexiones.clear();

        cout << "[1] para salir del menu (Agregar Router)" << endl;
        cin >> comandoSalirMenu;

        if(comandoSalirMenu == '1')
        {
            salirAgregar = true;
        }
    }

    this->MostrarMenu();
}

void Menu::MenuCargarRouterArchivo()
{
    char comandoSalirMenu;
    this->router.CargarMapaArchivo();
    this->router.PintarMapa();
    cout << "Presione cualquier tecla para salir" << endl;
    cin >> comandoSalirMenu;
    this->MostrarMenu();
}

void Menu::MenuEnviarPaquetes()
{
    system("cls");
    bool salir = false;
    char inicio, destino;
    char comando;

    while(!salir){
        cout << " Escribe el lugar desde donde quieres comenzar " << endl;
        cin >> inicio;

        cout << "Escribe el destino " << endl;
        cin >> destino;

        this->router.EnviarPaquete(inicio, destino);

        cout << "¿Desea enviar otro paquete? [1] para salir" << endl;
        cin >> comando;

        if(comando == '1')
            salir = true;
    }

    this->MostrarMenu();
}

void Menu::MenuGenerarAutomaticamente()
{
    char comando;
    this->router.PintarMapa();

    cout << "Presione cualquier tecla para continuar" << endl;
    cin >> comando;
    return;
    this->MostrarMenu();
}

void Menu::MostrarMenu()
{
    system("cls");
    cout << "\e[0;36mBienvenido al menu\e[0m" << endl;
    cout << " [1] para agregar un nuevo router" << endl;
    cout << " [2] para cargar routers desde un archivo (mapa.txt)" << endl;
    cout << " [3] para enviar un paquete de un destino a otro y saber su costo " << endl;
    cout << " [4] para imprimir el mapa" << endl;
    cout << " [5] para salir " << endl;
    cin >> this->comando;

    switch (comando) {
    case '1':
        this->MenuAgregarRouter();
        break;
    case '2':
        this->MenuCargarRouterArchivo();
        break;
    case '3':
        this->MenuEnviarPaquetes();
        break;
    case '4':
        this->MenuPintarMapa();
        break;
    case '5':
        return;
    default:
        break;
    }
}
void Menu::MenuPintarMapa(){
    this->router.PintarMapa();
    char comandoSalirMenu;
    cout << "Presione cualquier tecla para salir" << endl;
    cin >> comandoSalirMenu;
    this->MostrarMenu();

}






