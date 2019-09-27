
// Pablo Miranda Torres

// Creamos una clase donde se guarden los valores de cada usuario: id, periodo y tiempo pasado. Asignamos prioridad a la clase usuario.

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase



class Usuario{
private:
    long long int id;
    long int tiempo;
    int periodo;
public:
    Usuario(){}
    Usuario(long long int i, long int t, int p){
        id = i;
        tiempo = t;
        periodo = p;
    }

    bool operator<(Usuario const & u) const{
        return (tiempo < u.tiempo || (tiempo == u.tiempo && id < u.id));
    }

    void suma(){
        tiempo+=periodo;
    }

    long long int getID(){
        return id;
    }

};


// O(NlogN + KlogN)   N es numero usuarios y k número consultas

bool resuelveCaso() {

    int usuarios;
    std::cin>>usuarios;

    if (usuarios==0)
        return false;
    PriorityQueue<Usuario> colaUsuarios;
    for(int i = 0; i < usuarios; i++){
        long long int id;
        long int tiempo;
        std::cin>>id >> tiempo;
        colaUsuarios.push(Usuario(id,tiempo,tiempo));
    }

    long int k;
    std::cin>>k;

    for(long int i = 0; i < k; i++){
        Usuario u = colaUsuarios.top();
        colaUsuarios.pop();
        std::cout<< u.getID() << "\n";
        u.suma();
        colaUsuarios.push(u);
    }
    std::cout<< "---\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("../Casos/21.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
