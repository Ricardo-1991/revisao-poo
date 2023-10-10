
#include <iostream>
#include <iomanip>

using namespace std;

class FormatadorTexto {
public:
    static string formatarDecimal(double numero, int precisao) {
        ostringstream stream;
        stream << fixed << setprecision(precisao) << numero;
        return stream.str();
    }
};

int main() {
    double valor = 123.456789;
    string resultado = FormatadorTexto::formatarDecimal(valor, 2);
    cout << "Resultado: " << resultado << endl;
    return 0;
}
