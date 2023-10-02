#include <iostream>

using namespace std;

class Funcionario {
    string nome;
    double salario;
    double horasTrabalhadas;

    public:
    Funcionario(string _nome, double _salario, double _horasTrabalhadas){
        nome = _nome;
        salario = _salario;
        horasTrabalhadas = _horasTrabalhadas;
    }

    double getSalario() {
        return salario;
    }

    double getHorasTrabalhadas(){
        return horasTrabalhadas;
    }

    static double calculaSalario(Funcionario& funcionario){
        return funcionario.getHorasTrabalhadas() * funcionario.getSalario();
    }
};


int main () {
    Funcionario funcionario1("nome", 100.0, 5);

    cout << Funcionario::calculaSalario(funcionario1);

    return 0;
}