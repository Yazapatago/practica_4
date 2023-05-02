#ifndef ROUTER_H
#define ROUTER_H

#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <iostream>
#include <random>
#include <set>

struct Node
{
    int dest;
    int weight;
    Node(int d, int w) : dest(d), weight(w){}
};


class Router
{
private:
    std::map<char, std::vector<Node>> mapa;
    void Dijsktra(char start, char end);
public:
    Router();
    void CargarMapaArchivo();
    void AgregarNodo(char key, std::vector<Node> node);
    void EliminarNodo(char key);
    void EnviarPaquete(char start, char end);
    void PintarMapa();
};

#endif // ROUTER_H
