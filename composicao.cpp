#include <iostream>

// Classe Ponto representa uma coordenada (x, y)
class Ponto {
private:
    int x, y;

public:
  Ponto(int x, int y) : x(x), y(y) {}

    void exibirCoordenadas() const {
        std::cout << "Coordenadas: (" << x << ", " << y << ")" << std::endl;
    }
};

// Classe Retângulo composta por dois objetos Ponto
class Retangulo {
private:
    Ponto superiorEsquerdo;
    Ponto inferiorDireito;

public:
    Retangulo(int x1, int y1, int x2, int y2) : superiorEsquerdo(x1, y1), inferiorDireito(x2, y2){};
    // Vai exigir que a instancia (objeto) criado por ele, necessite de valores iniciais;

    void exibirInformacoes() const {
        std::cout << "Retângulo definido por:" << std::endl;
        superiorEsquerdo.exibirCoordenadas();
        inferiorDireito.exibirCoordenadas();
    }
};

int main() {
    // Criando um objeto Retangulo usando composição
    Retangulo meuRetangulo(1, 2, 4, 6);
    Retangulo meuRetangulo2(5, 6, 7, 8);

    // Exibindo informações do retângulo
    meuRetangulo.exibirInformacoes();

    meuRetangulo2.exibirInformacoes();

    return 0;
}
