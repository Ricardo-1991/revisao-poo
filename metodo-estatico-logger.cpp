#include <iostream>

using namespace std;


class Logger {
    private:
    string name;

    public:
    Logger(string name, string message){
      this->name = name;

      MensagemCriacao(this->name, message);
    }   

    static void MensagemCriacao(string _name, string _menssage) {
        cout << "[LOG] - " << _menssage << ", " << _name; 
    }
};

int main() {
    Logger usuario("Ricardo", "Bem vindo!");

    return 0;
}