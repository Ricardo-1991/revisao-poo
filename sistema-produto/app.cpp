#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Product {
public:
    string name;
    double price;

    virtual string priceTag() {
        ostringstream oss;
        oss << fixed << setprecision(2);
        oss << name << " R$ " << price;
        return oss.str();
    }
};

class ImportedProduct : public Product {
public:
    double customsFee;

    double totalPrice() {
        customsFee = price * 0.1;
        double result = (price + customsFee);
        return result;
    }

    string priceTag() override {
        ostringstream oss;
        oss << fixed << setprecision(2);
        oss << name + " R$ " << (totalPrice()) << " (Taxa de Importacao: R$ " << (customsFee) << ")";
        return oss.str();
    }
};

class UsedProduct : public Product {
public:
    static tm manufacturedDate;

    string priceTag() override {
        ostringstream oss;
        oss << fixed << setprecision(2);

        oss << name << " (usado) R$ " << price << " Data de fabricacao: " <<
            setw(2) << setfill('0') << manufacturedDate.tm_mday << "/" << 
            setw(2) << setfill('0') << manufacturedDate.tm_mon + 1 << "/" << 
            manufacturedDate.tm_year + 1900;
        return oss.str();
    }

    static void convertData(string dataString) {
        istringstream dataStream(dataString);
        char delimiter = '/';
        dataStream >> manufacturedDate.tm_mday >> delimiter >> manufacturedDate.tm_mon >> delimiter >> manufacturedDate.tm_year;
        manufacturedDate.tm_year -= 1900; 
        manufacturedDate.tm_mon--;        
    }
};

tm UsedProduct::manufacturedDate = {};

int main() {
    vector<Product*> products;
    int op;
    char typeOfProduct;
    string dataString;
    cout << "Entre com o numero de produtos que deseja cadastrar: " << endl;
    cin >> op;

    for (int i = 0; i < op; i++) {
        Product* newProduct = nullptr;
        cout << "Comum, usado ou importado? (c, u, i)" << endl;
        cin >> typeOfProduct;

        switch (typeOfProduct) {
        case 'c':
            newProduct = new Product();
            cout << "Digite o nome do produto: " << endl;
            getline(cin >> ws, newProduct->name);
            cout << "Digite o preco do produto: " << endl;
            cin >> newProduct->price;
            products.push_back(newProduct);
            break;
        case 'i':
            newProduct = new ImportedProduct();
            cout << "Digite o nome do produto importado: " << endl;
            getline(cin >> ws, newProduct->name);
            cout << "Digite o preco do produto: " << endl;
            cin >> newProduct->price;
            dynamic_cast<ImportedProduct*>(newProduct)->totalPrice();
            products.push_back(newProduct);
            break;
        case 'u':
            newProduct = new UsedProduct();
            cout << "Digite o nome do produto usado: " << endl;
            getline(cin >> ws, newProduct->name);
            cout << "Digite o preco do produto: " << endl;
            cin >> newProduct->price;
            cout << "Quando ele foi fabricado? dd/mm/aaaa" << endl;
            getline(cin >> ws, dataString);
            UsedProduct::convertData(dataString);
            products.push_back(newProduct);
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < products.size(); i++) {
        cout << products[i]->priceTag() << endl;
    }

    // Liberar a memória alocada para os produtos
    for (int i = 0; i < products.size(); i++) {
        delete products[i];
    }

    return 0;
}
