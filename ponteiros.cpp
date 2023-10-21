#include <iostream>
#include <vector>

using namespace std;

class Pessoa {
    public:
    string nome;
    string cpf;
    Pessoa(string _nome, string _cpf) : nome(_nome), cpf(_cpf){}
};

class Cliente : public Pessoa {
    private:
    public:
    Cliente(string _nome, string _cpf) : Pessoa(_nome, _cpf){}

    void setNome(string _nome){
        nome = _nome;
    }

    string getNome(){
        return nome;
    }

    void setCPF(string _cpf){
        cpf = _cpf;
    }

    string getCPF(){
        return cpf;
    }
};

class Pagamento {
    public:
    float desconto;
    float adicional;
    float preco;
    
    void metodoPagamento(int metodoPagamento) {
    
    }
};


class Funcionario : public Pessoa {
    private:
    string matricula;
    vector<Cliente*> cliente;
    public:
    Pagamento pagamento;
    
    Funcionario(string _nome, string _cpf) : Pessoa(_nome, _cpf){};

    void setNome(string _nome){
        nome = _nome;
    }

    string getNome(){
        return nome;
    }

    void setCPF(string _cpf){
        cpf = _cpf;
    }

    string getCPF(){
        return cpf;
    }

    void setMatricula(string _matricula){
        matricula = _matricula;
    }

    string getMatricula(){
        return matricula;
    }

    void cadastrarCliente(Cliente* _novoCliente) {
        cliente.push_back(_novoCliente);
    }

    void listarClientes () {
        for(auto it = cliente.begin(); it != cliente.end(); it++){
            cout << (*it)->nome << " - " << (*it)->getCPF() << endl;
        }
    }

};


class Reserva {
    public:
    vector<Funcionario*> funcionario;
    tm data_inicio;
    tm* data_termino;

    void listarReservas(){
        for(auto it = funcionario.begin(); it != funcionario.end(); it++){
            cout << "--- Reservas --- " << endl;
            cout << "Funcionario: " << (*it)->nome << endl;
            cout << "Matricula: " << (*it)->getMatricula() << endl;
            cout << "--- Lista de Clientes Cadastrados ---" << endl;
            (*it)->listarClientes();
            cout << endl;
        }
    }

    void cadastrarReserva(Funcionario* _novoFuncionario){
        funcionario.push_back(_novoFuncionario);
    }

};


int main (){
    Funcionario superFuncionario("Alexandre", "12345");
    Funcionario funcionario2("Lexamon", "32145");
    funcionario2.setMatricula("86759");
    superFuncionario.setMatricula("028384");

    Cliente cliente("Ricardo", "45678");

    superFuncionario.cadastrarCliente(&cliente);

    Cliente cliente2("Matheus","1233");
    superFuncionario.cadastrarCliente(&cliente2);


    Cliente cliente3("Gilberto","3321");
    superFuncionario.cadastrarCliente(&cliente3);

    Cliente cliente4("Alexandre","6642");

    superFuncionario.cadastrarCliente(&cliente4);




    Cliente cliente5("Muriolo", "64756743");

    funcionario2.cadastrarCliente(&cliente5);

    Cliente cliente6("Finflinz","095950");
    funcionario2.cadastrarCliente(&cliente6);


    Cliente cliente7("Amanda","6889459");
    funcionario2.cadastrarCliente(&cliente7);

    Cliente cliente8("Lucas","463576543");

    funcionario2.cadastrarCliente(&cliente8);

    Reserva reserva;

    reserva.cadastrarReserva(&superFuncionario);
    reserva.cadastrarReserva(&funcionario2);

    reserva.listarReservas();

    return 0;
}