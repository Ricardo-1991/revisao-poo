#include <iostream>
#include <vector>

using namespace std;

class Pessoa {
  string nome;
  int idade;
  double altura;
  public:

   Pessoa(string _nome, int _idade, double _altura) {
        nome = _nome;
        idade = _idade;
        altura = _altura;
   }

  void setNome (string _nome) {
    nome = _nome;
  }

  void setIdade (int _idade){
    idade = _idade;
  }

  void setAltura(double _altura) {
    altura = _altura;
  }
 

  string getNome () {
    return nome;
  }

  int getIdade (){
    return idade;
  }

  double getAltura() {
    return altura;
  }

};

class Agenda {
    vector <Pessoa> povo;

    public:

    void armazenaPessoa(Pessoa pessoa) {
        povo.push_back(pessoa);
    }

    void imprimePovo() {
        for (auto it = povo.begin(); it != povo.end(); it++) {
           cout << "Nome: " << (*it).getNome() << endl << "Idade: " << (*it).getIdade() << endl << "Altura: " << (*it).getAltura() << endl << "--------------" << endl;
        }
    }

    int buscaPessoa(string _nome){
       int index = 0;
       for(auto it = povo.begin(); it != povo.end(); it++, index++){
         if(_nome == (*it).getNome()) {
            return index;
         }
       }
       return -1;
    }

    void imprimePessoa(int _posicao) {
        cout << "Nome: " << povo[_posicao].getNome() << endl;
        cout << "Idade: " << povo[_posicao].getIdade() << endl;
        cout << "Altura: " << povo[_posicao].getAltura() << endl << endl;
    }

    void removePessoa(string _nome) {
        int index = 0;
       for (auto it = povo.begin(); it != povo.end(); it++, index++) {
            if (_nome == (*it).getNome()) {
                it = povo.erase(it);
                break;
            }  
        }
    }
};

int main () {
    Agenda agenda;
    int op;
    do {
        cout << "Cadastro de pessoas em agenda" << endl;
        cout << "-----------------------------" << endl;
        string nome;
        int idade;
        double altura;
        cout << "Digite um nome: " << endl;
        getline(cin >> ws, nome);
        cout << "Digite uma idade: " << endl;
        cin >> idade;
        cout << "Digite uma altura: " << endl;
        cin >> altura;

        agenda.armazenaPessoa(Pessoa(nome, idade, altura));

        cout << "Deseja cadastrar mais uma pessoa?" << endl;
        cout << "Digite 1 para SIM ou aperte qualquer tecla para encerrar." << endl;
        cin >> op;

    }while(op == 1);

    int posicao = agenda.buscaPessoa("Rafaella");
    
    if(posicao >= 0) {
      agenda.imprimePessoa(posicao);
    }

    agenda.removePessoa("Joao");

    agenda.imprimePovo();
    
    return 0;
}