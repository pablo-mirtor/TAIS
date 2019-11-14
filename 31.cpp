// Pablo Miranda Torres


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Grafo.h"

class grafoCalles{
private:
    vector<bool> marked;
    vector<int> guardias;
    vector<int> distTo;
    int conGuardia;
    int sinGuardia;
    int nGuardias;

    void dfs(Grafo const& G, int s) {
        marked[s] = true;
        for (int w : G.ady(s)){
            if (!marked[w]) {
                distTo[w] = s;
                dfs(G, w);
            }
            }
    }

public:
    grafoCalles(){};
    //Coste O(V+E) por algoritmo dfs
    grafoCalles(Grafo const & g) : marked(g.V(), false), guardias(g.V(),0), distTo(g.V()){
        int i = 1;
        while(i < g.V()){
            if(!marked[i]){
                dfs(g, i);
            }
        }
    }
    int numeroGuardias() const {return nGuardias;}
};


bool resuelveCaso() {
    int V, E;
    std::cin>> V >> E;
    if (!std::cin)
        return false;

    Grafo grafo = Grafo(V);

    for(int i = 0; i < E; i++){
        int v1, v2;
        cin>>v1>>v2;
        grafo.ponArista(v1,v2);
    }

    grafoCalles gc(grafo);
    if(gc.numeroGuardias() == -1) cout << "IMPOSIBLE\n";
    else cout << gc.numeroGuardias() <<"\n";
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/31.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
