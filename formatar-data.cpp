#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;
int main() {
    string dataString = "05/10/2023";

    tm data = {};

    istringstream dataStream(dataString);

    char delimiter = '/';
    dataStream >> data.tm_mday >> delimiter >> data.tm_mon >> delimiter >> data.tm_year;

    if (dataStream.fail()) {
        std::cerr << "Erro ao analisar a data." << std::endl;
        return 1;
    }

    cout << "Mês: " << data.tm_mon<< endl; 
    cout << "Ano: " << data.tm_year << endl;
    cout << "Dia: " << data.tm_mday << endl;

    return 0;
}
