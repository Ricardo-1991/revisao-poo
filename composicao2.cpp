#include <iostream>
#include <vector>

using namespace std;

class Cliente {
    public:
    string nome, cpf;
    Cliente(string n = "indefinido", string c = "indefinido") : nome(n), cpf(c) {};
};

class Dependente {
    public:
    string nome;
    vector<Cliente*> *dependente_de;

    Dependente(vector<Cliente> &especifico, string n){
        nome = n;
        dependente_de = new vector<Cliente*>();  // Inicializar o vetor

        for(int i = 0; i < especifico.size(); i++) {
            dependente_de->push_back(new Cliente(especifico[i]));
        }
    };
};

class Funcionario {
    public:

    static void adicionaClientes(vector<Cliente> &clientes) {
    bool isContinue = true;
    char resp;

    cout << "Adicionar clientes: ";
    do {
      Cliente novoCliente;
      cout << "Digite um nome: " << endl;
      getline(cin >> ws, novoCliente.nome);

      cout << "Digite um cpf: " << endl;
      getline(cin >> ws, novoCliente.cpf);
      cout << endl;

      clientes.push_back(novoCliente);

      cout << "Deseja adicionar mais algum cliente? Digite 's' para adicionar ou qualquer tecla para sair: " << endl;
      cin >> resp;

      if(resp != 's') {
        isContinue = false;
      }
    
    }while(isContinue);
    }
};

int main () {
    vector<Cliente> clientes;
    Funcionario::adicionaClientes(clientes);

    Dependente novoDependente(clientes, "Mavie");

    cout << "Os pais de " << novoDependente.nome << " sao: " << endl;
    for(auto it = novoDependente.dependente_de->begin(); it < novoDependente.dependente_de->end(); it++){
        cout << (*it)->nome << " - " << (*it)->cpf << endl;
    }

    return 0;
}