#include <iostream>
using namespace std;

class Elevador {
    int cargaMax;
    int cargaAtual;
    int maxAndares;
    int andarAtual;

    public:
    Elevador(int max, int nAndares){
        cargaMax = max;
        cargaAtual = 0;
        maxAndares = nAndares;
        andarAtual = 0;
    }

    void entra() {
        if(cargaAtual < cargaMax)
            cargaAtual+=4;
        else 
            cout << "Elevador com carga maxima de pessoas. Espere pelo menos 1 pessoa sair." << endl;
    }   

    void sai() {
        if(cargaAtual > 0)
            cargaAtual-=4;
        else
            cout << "O elevador esta vazio! Adicione pelo menos uma pessoa no elevador." << endl;
    }

    void sobe() {
        if(andarAtual < maxAndares)
             andarAtual+= 5;
        else 
            cout << "O elevador ja esta no ultimo andar do predio." << endl;
    }

    void desce() {
        if(andarAtual > 0)
            andarAtual--;
        else 
            cout << "O elevador esta no terreo do predio." << endl;
    }

    int get_cargaMax() {
        cout << "Carga maxima do elevador: " << endl;
        return cargaMax;
    }

    int get_cargaAtual() {
        cout << "Carga atual: ";
        return cargaAtual;
    }

    int getMaxAndares() {
        cout << "Quantidade de andares do predio: " << endl;
        return maxAndares;
    }

    int getAndarAtual(){
        cout << "Andar atual do elevador: " << endl;
        return andarAtual;
    }


};

int main () {
    Elevador elevador(8, 15);
    cout << elevador.getAndarAtual() << endl;
    elevador.sobe();
    cout << elevador.getAndarAtual() << endl;

    elevador.entra();
    cout << elevador.get_cargaAtual() <<endl;
    elevador.entra();
    cout <<elevador.get_cargaAtual() << endl;

    cout << elevador.get_cargaMax();
    cout << elevador.getMaxAndares();





    return 0;
}