
// Pablo Miranda Torres

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"


class Caja{
private:
    int id;
    int tiempo;
public:
    Caja(){}
    Caja(int i){
        id = i;
        tiempo = 0;
    }

    int getID() const{
        return id;
    }

    bool operator<(Caja const & p) const {
        return tiempo < p.tiempo || (tiempo == p.tiempo && id < p.id);
    }

    void atiendeCliente(int secs){
        tiempo+=secs;
    }
};


// O(NlogN + ClogN) N es numero cajas y c número clientes

bool resuelveCaso() {

    int n, c;
    std::cin>>n>>c;

    if (n==0 && c==0)
        return false;
    PriorityQueue<Caja> cola;

    for(int i = 1; i <= n; i++){ //Creamos las cajas
        cola.push(Caja(i));
    }

    for(int i = 0; i < c; i++){  //Cogemos la caja que se queda libre y le asignamos al siguiente cliente sumándole el tiempo estimado
        int secs;
        std::cin>>secs;
        Caja cajaLibre = cola.top();
        cola.pop();
        cajaLibre.atiendeCliente(secs);
        cola.push(cajaLibre);
    }

    std::cout<< cola.top().getID() <<"\n";
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/23.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
