

// Pablo Miranda Torres
//TAIS46

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"

// función que resuelve el problema
// coste, O(N), donde N es la longitud de la cola
long int resolver(PriorityQueue<long int> datos) {
    long int esfuerzo = 0;
    long int valor1, valor2;
    while(datos.size() > 1){
            valor1 = datos.top(); //sacamos los dos valores menores y sumamos
            datos.pop();
            valor2 = datos.top();
            datos.pop();
            if(!datos.empty())
                 datos.push(valor1+valor2); //devolvemos la suma parcial a la cola
             esfuerzo += valor1+valor2;
    }
    return esfuerzo;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    long int num;
    std::cin>>num;
    if(num == 0)
        return false;
    PriorityQueue<long int> cola;
    for(long int i= 0; i < num; i++){
        long int x;
        std::cin>>x;
        cola.push(x);
    }
    std::cout << resolver(cola)<< std::endl;
    // escribir solución
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("../Casos/20.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
