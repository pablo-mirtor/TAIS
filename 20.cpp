

// Pablo Miranda Torres
//TAIS46
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(PriorityQueue<long int> datos) {
    long int esfuerzo = 0;
    long int valor1, valor2;
    while(!datos.size() > 1){
        valor1 = datos.top();
        datos.pop();
        if(datos.size() > 1){
        valor2 = datos.top();
        datos.pop();}
        esfuerzo = valor1+valor2;
    }
    return esfuerzo;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num;
    std::cin>>num;
    PriorityQueue<long int> cola;
    for(int i= 0; i < num; i++){
        long int x;
        std::cin>>x;
        cola.push(x);
    }
    std::cout << resolver(cola)<< std::endl;
    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("../Casos/20.txt");
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
