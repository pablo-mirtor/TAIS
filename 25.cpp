
// Pablo Miranda Torres

/*Creamos dos colas, una decreciente que representa la primera la mitad izquierda de los pájaros, cuyo top será el pájaro que se
 * encuentre en el centro, y otra creciente que representa la mitad derecha. Ambas colas deben tener casi el mismo tamaño
 * (la primera uno más ya que tiene al centro). */
#include <iostream>
#include <fstream>
#include "PriorityQueue.h"


//Coste O(NlogN), siendo N el número de pájaros total
bool resuelveCaso() {
    int pajaro, n;
    std::cin>>pajaro>>n;
    if (pajaro == 0 && n == 0)
        return false;

    PriorityQueue<int, std::greater<int>> primeraMitad;
    PriorityQueue<int> segundaMitad;

    primeraMitad.push(pajaro);

    for(int i = 0; i < n; i++){
        int p1, p2;
        std::cin>>p1>>p2; //leemos la pareja nueva

        if(p1 > primeraMitad.top()){ //insertamos en una de las colas según su valor
            segundaMitad.push(p1);
        }
        else{
            primeraMitad.push(p1);
        }

        if(p2 > primeraMitad.top()){
            segundaMitad.push(p2);
        }
        else{
            primeraMitad.push(p2);
        }

        while(primeraMitad.size() != segundaMitad.size() + 1){ //equilibramos el tamaño de las colas
            if(segundaMitad.size() >= primeraMitad.size()){
                pajaro = segundaMitad.top();
                segundaMitad.pop();
                primeraMitad.push(pajaro);
            }
            else if(primeraMitad.size() > segundaMitad.size() + 1){
                pajaro = primeraMitad.top();
                primeraMitad.pop();
                segundaMitad.push(pajaro);
            }
        }

        std::cout << primeraMitad.top() << ' ';
    }
    std::cout << '\n';

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/25.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
