#include "router.h"
#include "fstream"

using namespace std;

Router::Router()
{
}

void Router::AgregarNodo(char key, std::vector<Node> node)
{
    this->mapa[key] = node;
    this->mapa[node[0].dest].push_back(Node(key, node[0].weight));
}

void Router::EliminarNodo(char key)
{
    this->mapa.erase(key);
}

// Algoritmo para encontrar la ruta mas corta entre dos nodos
void Router::Dijsktra(char start, char end) {
    // Crear una cola de prioridad (distancia, nodo)
    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::greater<std::pair<int, char>>> pq;
    // Crear los mapas de distancia, visitados y anteriores
    std::map<char, int> distancia;
    std::map<char, bool> visitado;
    std::map<char, char> anterior;

    // Inicializar variables
    for (auto it = mapa.begin(); it != mapa.end(); ++it) {
        distancia[it->first] = INT_MAX; // distancia infinita desde el nodo de inicio
        visitado[it->first] = false; // no se ha visitado ningún nodo
        anterior[it->first] = 0; // no hay nodos anteriores
    }

    distancia[start] = 0; // distancia desde el nodo de inicio a sí mismo es 0
    pq.push(std::make_pair(0, start));

    while (!pq.empty()) {
        char u = pq.top().second;
        pq.pop();

        if (visitado[u]) {
            continue;
        }
        visitado[u] = true;

        // Si se llegó al nodo de destino, salir del ciclo
        if (u == end) {
            break;
        }

        for (auto &e : mapa[u]) {
            int alt = distancia[u] + e.weight;
            if (alt < distancia[e.dest]) {
                distancia[e.dest] = alt;
                anterior[e.dest] = u;
                pq.push(std::make_pair(alt, e.dest));
            }
        }
    }

    // Mostrar la distancia más corta y el camino desde el nodo de inicio hasta el nodo de destino
    std::cout << "La distancia más corta desde " << start << " a " << end << " es " << distancia[end] << std::endl;
}

void Router::EnviarPaquete(char start, char end)
{
    Router::Dijsktra(start, end);
}

void Router::PintarMapa()
{
    for(auto it = this->mapa.begin(); it != this->mapa.end(); ++it)
    {
        cout << it->first << " : ";
        for(auto& node: it->second)
        {
            cout << "(" << node.dest << "," << node.weight << ")";
        }
        cout << endl;
    }
}

void Router::CargarMapaArchivo()
{
    std::ifstream archivo("mapa.txt");

    this->mapa.clear();

    if (archivo.is_open())
    {
        string linea;
        while(getline(archivo, linea))
        {
            stringstream ss(linea);
            string nodo;

            getline(ss, nodo, ';');

            if(mapa.find(nodo[0]) == mapa.end())
            {
                this->mapa[nodo[0]] = vector<Node>();
            }

            string arista;
            while(getline(ss, arista, ';'))
            {
                char destino = arista[0];
                int peso = stoi(arista.substr(2));
                this->mapa[nodo[0]].push_back(Node(destino, peso));
            }
        }
    }
    archivo.close();
}
