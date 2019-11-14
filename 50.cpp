// Pablo Miranda Torres
//TAIS46

#include <iostream>
#include <fstream>
#include <vector>

bool resuelveCaso() {
    int N, L;
    std::cin>>N>>L;
    if (!std::cin)
        return false;
    std::vector<int> agujeros(N);
    for(int i=0; i < N; i++) {
        int a;
        std::cin >> a;
        agujeros.at(i) = a;
    }

    int nParches = 1;
    int rango = agujeros[0] + L; //si colocamos un parche en i, el rango dirá la distancia máxima de parche desde i

    for(int i = 1; i < N; i++){
        if(agujeros[i] > rango){
            rango = agujeros.at(i) + L;
            nParches++;
        }
    }
    std::cout<< nParches << '\n';
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/40.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
