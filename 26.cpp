// Pablo Miranda Torres


#include <iostream>
#include <fstream>

#include "PriorityQueue.h"


Solucion resolver(Datos datos) {
    ...
}


bool resuelveCaso() {
    int n;
    std::cin>>n;
    if (!std::cin)
        return false;
    int p;
    std::cin>>p;
    Solucion sol = resolver(datos);


    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/XX.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
