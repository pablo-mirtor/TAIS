
// Pablo Miranda Torres
// TAIS46

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
// Coste O(N) siendo N el número de nodos



bool esAVL(bintree<int> arbol, int &minimo, int &maximo, int &altura){
    bool avl = false;
    if(arbol.left().empty() && arbol.right().empty()){
        avl = true;
        altura = 1;
    }
    else if(arbol.left().empty()){
        int maximoRight = arbol.root(), minimoRight = arbol.root();
        maximo = std::max(maximo, arbol.root());
        minimo = std::min(minimo, arbol.root());
        bool avlRight = esAVL(arbol.right(), minimoRight, maximoRight, altura);
        avl = (avlRight && minimoRight < arbol.root());
    }
    else if(arbol.right().empty()){
        int maximoLeft, minimoLeft;
        bool avlLeft = esAVL(arbol.left(), minimoLeft, maximoLeft, altura );
        avl = (avlLeft && minimoLeft < arbol.root());
    }
    else{


    }
    return avl;
}

bool resolver(bintree<int> datos, int &altura) {

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
    bintree<int> arbol = leerArbol(-1);
    int altura;
    bool equilibrado = resolver(arbol, altura);

    std::cout << (equilibrado ? "SI" : "NO") << std::endl;

}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/11.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}