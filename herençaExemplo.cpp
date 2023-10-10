#include <iostream>

using namespace std;

class Figura {
    private:

    public:
    float area();
    float perimetro();
};

class Quadrado: public Figura {
    private:
        float lado;

    public: 
        float area (){
            return lado * lado;
        }
        
        float perimetro() {
            return lado * 4;
        }

        void setLado(float _lado) {
            lado = _lado;
        }

        float getLado (){
            return lado;
        }
};

class Triangulo {
    private:
        float base, altura, l1, l2, l3;

    public:
        Triangulo(float _base, float _altura, float _l1 , float _l2, float _l3) {
            base = _base;
            altura = _altura;
            l1 = _l1;
            l2 = _l2;
            l3 = _l3;
        }
        float area(){
            return base * (altura / 2);
        }

        float perimetrio(){
            return l1 + l2 + l3;
        }
};

int main(){
    Quadrado quadrado;
    float buffer;

    cout << "Digite o lado do quadrado para calcular seu perimetro e a sua area: ";
    cin >> buffer;
    quadrado.setLado(buffer);

    cout << "Area do quadrado: " << quadrado.area() << endl;
    cout << "Perimetro do quadrado: " << quadrado.perimetro() << endl << endl;

    Triangulo triangulo(5, 6, 2, 3, 6);

    cout << "Area do triangulo: " << triangulo.area() << endl;
    cout << "Perimetro do triangulo: " << triangulo.perimetrio() << endl;

    return 0;   
}