#include <iostream>

using namespace std;

class SuperClasse {
    private:
    int teste;

    public:
    void setTest(int _novoteste){
        teste = _novoteste;
    }

    int getTest () {
        return teste;
    }
};

class derivadaClasse : public SuperClasse {
    private:
    int outrotest;
    public:
    int getOutroTest() {
        return getTest();
    }
};


int main () {

    derivadaClasse derivada;

    derivada.setTest(5);

    cout << derivada.getOutroTest();
    

    return 0;
}