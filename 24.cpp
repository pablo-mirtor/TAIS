// Pablo Miranda Torres


#include <iostream>
#include <fstream>

#include "PriorityQueue.h"

class Dron{
private:
    int a;
    int b;
public:
    Dron(){
    }

    Dron(int p1, int p2){
        a=p1;
        b=p2;
    }

    bool operator>(Dron const & d) const {
        return std::max(a,b) < std::max(d.a,d.b);
    }

    int resto() const { //devuelve la carga de la pila que sobra
        return std::abs(a-b);
    }

    int getA() const {
        return a;
    }

    int getB() const {
        return b;
    }
};


void resolver(int n, PriorityQueue<int,std::greater<int>> aqueue, PriorityQueue<int,std::greater<int>> bqueue){

    PriorityQueue<Dron, std::greater<Dron>> drones;

    while(!aqueue.empty() && !bqueue.empty()){
        int i = 0;
        int horasTotales = 0;
        while(i < n && !aqueue.empty() && !bqueue.empty()){ //insertamos las pilas en los drones
            drones.push(Dron(aqueue.top(),bqueue.top()));
            aqueue.pop(); bqueue.pop();
            i++;
        }

        while(!drones.empty()){ //descargamos cada dron
            Dron d = drones.top();
            drones.pop();
            if(d.getA() > d.getB()) //guardamos la pila que ha sobrado
                aqueue.push(d.resto());
            else if(d.getA() < d.getB())
                bqueue.push(d.resto());
            horasTotales+=std::min(d.getA(), d.getB());
        }
        std::cout << horasTotales << ' ';
    }
    std::cout << '\n';
}


bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!std::cin)
        return false;
    int a, b;
    std::cin>>a>>b;
    PriorityQueue<int,std::greater<int>> aqueue;
    PriorityQueue<int,std::greater<int>> bqueue;

    for(int i=0; i<a;i++){
        int carga;
        std::cin>>carga;
        aqueue.push(carga);
    }

    for(int i=0; i<b;i++){
        int carga;
        std::cin>>carga;
        bqueue.push(carga);
    }
    resolver(n,aqueue,bqueue);
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("../Casos/24.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
