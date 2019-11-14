// Pablo Miranda Torres


#include <iostream>
#include <fstream>
#include <vector>

#include "Grafo.h"

using namespace std;
class grafoBipartito{
private:
    vector<bool> marked;
    vector<int> valor; //grafo que asigna valores a los nodos (1 un color, 2 otro, 0 sin asignar)
    bool bipartito;

    void dfs(Grafo const & g, int v){
        for(int i : g.ady(v)){
            marked[v] = true;
            if(valor[i] == 0){
                if(valor[v] == 1)
                    valor[i] = 2;
                else valor[i] = 1;
            }
            else if(valor[i] == valor[v])
                bipartito = false;
            if(!marked[i])
                dfs(g,i);
        }
    }

public:
    grafoBipartito(){};
    //Coste O(V+E) por algoritmo dfs
    grafoBipartito(Grafo const & g) : marked(g.V(), false) , valor(g.V(), 0), bipartito(true) {
        for(int i = 0; i < g.V(); ++i){
            if(!marked[i]){
                valor[i] = 1;
                dfs(g, i);
            }
        }
    }
    bool esBipartito() const {return bipartito;}
};


bool resuelveCaso() {
    int V, E;
    std::cin>> V >> E;
    if (!cin)
        return false;

    Grafo grafo = Grafo(V);

    for(int i = 0; i < E; i++){
        int v1, v2;
        cin>>v1>>v2;
        grafo.ponArista(v1,v2);
    }

    grafoBipartito gb(grafo);
    if(gb.esBipartito()) cout << "SI\n";
    else cout << "NO\n";
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/30.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
