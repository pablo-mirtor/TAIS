// Pablo Miranda Torres
//TAIS46

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/*
 * Coste O(NlogN), debido a la función sort
 * Forzamos que la diferencia de valores sea mayor, por tanto ordenamos en orden ascendiente la puntuación de los rivales
 * y en orden descendente la puntuación del equipo
 * */
bool resuelveCaso() {
    int N;
    std::cin>>N;
    if (N == 0)
        return false;
    std::vector<int> rivales(N);
    std::vector<int> puntos(N);
    for(int i = 0; i < N; i++){
        int a;
        std::cin>>a;
        rivales[i] = a;
    }
    for(int i = 0; i < N; i++){
        int l;
        std::cin>>l;
        puntos[i] = l;
    }
    std::sort(rivales.begin(), rivales.end());
    std::sort(puntos.begin(), puntos.end(), std::greater<>());

    int suma = 0;
    for(int i = 0; i < N; i++){
        if(puntos[i] > rivales[i]){
            suma += puntos[i] - rivales[i];
        }
    }
    std::cout << suma << '\n';

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/52.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
