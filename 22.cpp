
// Pablo Miranda Torres

// Creamos una clase donde se guarden los valores de cada usuario: id, periodo y tiempo pasado. Asignamos prioridad a la clase usuario.

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase



class Paciente{
private:
    int tiempo;
    std::string nombre;
    int gravedad;
public:
    Paciente(){}
    Paciente(int t, std::string n, int g){
        tiempo = t;
        nombre = n;
        gravedad = g;
    }

    std::string getNombre() const{
        return nombre;
    }
    bool operator>(Paciente const & p) const {
        return gravedad > p.gravedad || (gravedad == p.gravedad && tiempo < p.tiempo);
    }
};


// O(KlogN) N es numero usuarios y k número consultas

bool resuelveCaso() {

    int n;
    std::cin>>n;

    if (n==0)
        return false;
    PriorityQueue<Paciente, std::greater<Paciente>> colaPacientes;
    for(int i = 0; i < n; i++){
        char evento;
        std::cin>>evento;
        if(evento=='I'){
            std::string nombre;
            int gravedad;
            std::cin>> nombre >> gravedad;
            colaPacientes.push(Paciente(i, nombre, gravedad));
        }
        else if(evento=='A'){
            Paciente p = colaPacientes.top();
            colaPacientes.pop();
            std::cout << p.getNombre() << '\n';
        }
    }

    std::cout<< "---\n";
    return true;
}

int main() {

    #ifndef DOMJUDGE
        std::ifstream in("../Casos/22.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif

        while (resuelveCaso());

    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
    #endif
        return 0;
}
