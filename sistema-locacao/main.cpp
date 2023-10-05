#include <iostream>
#include "bancoDeDados.h"

using namespace std;

int main(){
    Funcionario func1("12234455","Ulian","Ilheus","454564","123456");
/*     vector <Cliente> listaClientes = func1.cadastrarCliente();
    vector <Veiculo> listaVeiculos = func1.cadastrarVeiculo();
    BancoDeDados::clientesParaArquivo(listaClientes);
    BancoDeDados::veiculosParaArquivo(listaVeiculos); */
    BancoDeDados::imprimirVeiculos();
    cout << endl << endl;
    BancoDeDados::imprimirClientes();

    return 0;
}