
// Pablo Miranda Torres
// TAIS46

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
// Coste O(log N) siendo N el número de nodos
bool resolver(bintree<char> datos, int &altura) {

    bool equilibrado;
    if (datos.empty()) {
        equilibrado = true;
        altura = 0;
    }
    else {
        bool equilibradoIzq, equilibradoDer; //analizamos el árbol izquierdo y derecho
        int alturaIzq, alturaDer;
        equilibradoIzq = resolver(datos.left(), alturaIzq);
        equilibradoDer = resolver(datos.right(), alturaDer);

        if (equilibradoIzq && equilibradoDer && abs(alturaIzq - alturaDer) <= 1) { //los dos árboles son equilibrados y la diferencia de altura es como mucho 1
            equilibrado = true;
            altura = std::max(alturaIzq, alturaDer) + 1;
        }
        else equilibrado = false;
    }
    return equilibrado;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    int altura;
    bool equilibrado = resolver(arbol, altura);

    std::cout << (equilibrado ? "SI" : "NO") << std::endl;
    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("Casos/01.txt");
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