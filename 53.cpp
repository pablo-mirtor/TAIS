
// Pablo Miranda Torres

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void resuelveCaso() {
    int N, V;
    std::cin >> N >> V;
    // leer los datos de la entrada
    std::vector<int> pilas(N);
    for(int i = 0; i < N; i++){
        int voltaje;
        std::cin>>voltaje;
        pilas[i] =  voltaje;
    }
    std::sort(pilas.begin(), pilas.end(), std::greater<>());

    std::vector<int> mayores(N/2);
    std::vector<int> menores(N/2);

    for(int i = 0; i < N; i++){
        if(i < N/2){

        }

    }


}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("../Casos/53.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
