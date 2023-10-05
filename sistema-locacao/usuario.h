#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Usuario{
    public:
        string cpf;
        string nome;
        string endereco;
        string telefone;

        Usuario(string _cpf,
                string _nome,
                string _endereco,
                string _telefone){
            
            cpf = _cpf;
            nome = _nome;
            endereco = _endereco;
            telefone = _telefone;
        }
};

class Cliente : public Usuario{
    public:
        string habilitacao;
        Cliente():Usuario("","","",""){}
};

class Funcionario : public Usuario{
    public: 
        string matricula;

        Funcionario(string _cpf,
                string _nome,
                string _endereco,
                string _telefone,
                string _matricula):Usuario(_cpf,
                                             _nome,
                                             _endereco,
                                             _telefone){
            matricula = _matricula;
        }

        vector <Cliente> cadastrarCliente(){
            char op;
            string _cpf, _nome, _endereco, _telefone, _habilitacao;
            Cliente novoCliente;
            vector<Cliente> novosClientes;

           cout << "Cadastro de clientes" << endl;
           cout << "---------------------" << endl;
           do {
            cout << "digite um CPF: " << endl;
            getline(cin >> ws , novoCliente.cpf);

            cout << "digite um nome: " << endl;
            getline(cin >> ws , novoCliente.nome);

            cout << "digite um endereco: " << endl;
            getline(cin >> ws , novoCliente.endereco);

            cout << "digite um telefone: " << endl;
            getline(cin >> ws , novoCliente.telefone);
            
            cout << "digite um habilitacao: " << endl;
            getline(cin >> ws , novoCliente.habilitacao);
            cout << endl;
            novosClientes.push_back(novoCliente);
            cout << "Deseja adicionar mais algum cliente? s/n) ";
            cin >> op;

           }while(op != 'n');

           return novosClientes;

        }

        vector <Veiculo> cadastrarVeiculo(){
            char op;
            Veiculo novoVeiculo;
            vector<Veiculo> novosVeiculos;

           cout << "Cadastro de veiculos" << endl;
           cout << "---------------------" << endl;
           do {
            cout << "digite um identificador: " << endl;
            getline(cin >> ws , novoVeiculo.identificador);
            
            cout << "digite o ano de fabricacao: " << endl;
            cin >> novoVeiculo.anoFabricacao;


            cout << "digite a marca: " << endl;
            getline(cin >> ws , novoVeiculo.marca);

            cout << "digite o modelo: " << endl;
            getline(cin >> ws , novoVeiculo.modelo);
            
            cout << "digite o preco por dia de locacao: " << endl;
            cin >> novoVeiculo.precoPorDia;
            cout << endl;
            novosVeiculos.push_back(novoVeiculo);
            cout << "Deseja adicionar mais algum veiculo? s/n) ";
            cin >> op;

           }while(op != 'n');

           return novosVeiculos;

        }
};