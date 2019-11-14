
// Pablo Miranda Torres
//TAIS46

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/*
 * Coste O(NlogN), debido a la función sort*/
bool resuelveCaso() {
    int N;
    std::cin>>N;
    if (N == 0)
        return false;
    std::vector<int> alturas(N);
    std::vector<int> longitudes(N);
    for(int i = 0; i < N; i++){
        int a;
        std::cin>>a;
        alturas[i] = a;
    }
    for(int i = 0; i < N; i++){
        int l;
        std::cin>>l;
        longitudes[i] = l;
    }

    std::sort(alturas.begin(), alturas.end());
    std::sort(longitudes.begin(), longitudes.end());

    long int suma = 0;
    for(int i = 0; i < N; i++){
        suma += abs(alturas[i] - longitudes[i]);
    }
    std::cout << suma << '\n';

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/51.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
