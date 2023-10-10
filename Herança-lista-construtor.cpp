#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    string nome;
    Animal(string nome) : nome(nome) {}
};

class Cachorro : public Animal {
public:
    string raca;
    Cachorro(string nome, string raca) : Animal(nome) {}
};

int main() {
    Cachorro cachorro("Scooby", "Pastor Alemao");

    cout << cachorro.nome << endl;
    cout << cachorro.raca << endl;

    return 0;
}
