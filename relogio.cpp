#include <iostream>
#include <string>

using namespace std;

class Relogio {
    int hora;
    int minuto;
    int segundo;

    public:
    void setHora(int _hora, int _minuto, int _segundo) {
        if((_hora >= 0 && _hora <= 23) && (_minuto >= 0 && _minuto <= 59) && (_segundo >= 0 && _segundo <= 59)) {
            hora = _hora;
            minuto = _minuto;
            segundo = _segundo;
        } else {
            cout << "Formato de hora invalido" << endl;
        }
    }

    string formatarHora() {
        string strHora = to_string(hora), strMinuto = to_string(minuto), strSegundo = to_string(segundo);

        if(hora < 10){
            strHora = "0" + strHora;
        }
        if(minuto < 10) {
            strMinuto = "0" + strMinuto;
        }

        if(segundo < 10) {
            strSegundo = "0" + strSegundo;
        }
        return strHora + ":" + strMinuto + ":" + strSegundo;
    }

    string getHora() {
        return formatarHora();
    }

    void avancaSegundo() {
        segundo++;
    }
};


int main (){
    Relogio relogio;

    int op;
    int hora, minuto, segundo;

    cout << "Que horas sao? Digite HORA (0-23) - MINUTO (0 - 59) - SEGUNDO (0 - 59)" << endl;
    cin >> hora >> minuto >> segundo;
    relogio.setHora(hora, minuto, segundo);
    do {
      cout << "MENU RELOGIO DIGITAL" << endl;
      cout << "--------------------" << endl << endl;
      cout << "1 - Mostrar a hora configurada:" << endl;
      cout << "2 - Avancar um segundo:" << endl;
      cout << "3 - Finalizar programa:" << endl <<endl;
      cout << "Selecione a opcao desejada no menu: " << endl;
      cin >> op;
      switch (op)
      {
      case 1:
         cout << "Sao exatamente " << relogio.getHora() << endl;
        break;
      case 2:
         cout << "Aumentando um segundo..." << endl;
         relogio.avancaSegundo();
         break;
      case 3:
         cout << "Programa finalizado..." << endl;
        break;
      default: 
         cout << "Opcao invalida." << endl;
         break;
      }

    }while(op != 3);

    return 0;
}