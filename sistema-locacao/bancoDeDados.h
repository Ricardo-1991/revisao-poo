#include <iostream>
#include <vector>
#include <fstream>

#include "aluguel.h"

using namespace std;

class BancoDeDados{
    public:
        static void salvarDados(string arquivoNome, vector<string> dados){
            ofstream arquivo;
            
            vector<string>::iterator it;
            arquivo.open(arquivoNome,ios_base::out);
            
            if (arquivo.is_open()) {
                for(it = dados.begin(); it != dados.end(); it++){
                    arquivo << *it << endl;
                }
                arquivo.close();
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }
        }
        
        static void clientesParaArquivo(vector<Cliente> clientes){
            string bdClientes = "clientes.txt";
            vector<string> dados;

            for(Cliente cli : clientes){
                dados.push_back(cli.cpf);
                dados.push_back(cli.nome);
                dados.push_back(cli.endereco);
                dados.push_back(cli.telefone);
                dados.push_back(cli.habilitacao);
            }

            salvarDados(bdClientes,dados);
        }

           static void veiculosParaArquivo(vector<Veiculo> veiculos){
            string bdVeiculos = "veiculos.txt";
            vector<string> dados;

            for(Veiculo vec : veiculos){
                dados.push_back(vec.identificador);
                dados.push_back(to_string(vec.anoFabricacao));
                dados.push_back(vec.marca);
                dados.push_back(vec.modelo);
                dados.push_back(to_string(vec.precoPorDia));
            }

            salvarDados(bdVeiculos,dados);
        }



        static vector<string> recuperarDados(string arquivoNome){
            ifstream arquivo;
            vector<string> dados;
            arquivo.open(arquivoNome,ios_base::in);
            
            if (arquivo.is_open()) {
                string linha;
            while (arquivo.eof() == false) {
                    getline(arquivo, linha);
                    dados.push_back(linha);
                }
                arquivo.close();
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }

            return dados;
        }

        static vector<Cliente> arquivoParaClientes(){
            string bdClientes = "clientes.txt";
            vector<string> dados = recuperarDados(bdClientes);

            vector<Cliente> clientes;

            for(int i=0; i<dados.size()-1;i+=5){
                Cliente cli;
                cli.cpf = dados.at(i);
                cli.nome = dados.at(i+1);
                cli.endereco = dados.at(i+2);
                cli.telefone = dados.at(i+3);
                cli.habilitacao = dados.at(i+4);
                clientes.push_back(cli);
            }
            return clientes;
        }

           static vector<Veiculo> arquivoParaVeiculos(){
            string bdVeiculos = "veiculos.txt";
            vector<string> dados = recuperarDados(bdVeiculos);

            vector<Veiculo> veiculos;

            for(int i=0; i<dados.size()-1;i+=5){
                Veiculo vec;
                vec.identificador = dados.at(i);
                vec.anoFabricacao = stoi(dados.at(i+1));
                vec.marca = dados.at(i+2);
                vec.modelo= dados.at(i+3);
                vec.precoPorDia = stof(dados.at(i+4));
                veiculos.push_back(vec);
            }
            return veiculos;
        }

        static void imprimirClientes(){
            vector<Cliente> printClientes = arquivoParaClientes();

            for(int i = 0; i < printClientes.size(); i++){
                cout << printClientes[i].nome << endl << printClientes[i].cpf << endl << endl;
            }
        }

          static void imprimirVeiculos(){
            vector<Veiculo> printVeiculos = arquivoParaVeiculos();

            for(int i = 0; i < printVeiculos.size(); i++){
                cout << printVeiculos[i].identificador << endl << printVeiculos[i].precoPorDia << endl << endl;
            }
        }
};