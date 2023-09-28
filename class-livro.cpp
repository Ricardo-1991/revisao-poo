#include <iostream>

using namespace std;

class Livro {
    private:
    string titulo;
    string genero;
    string autor;
    string editora;
    int paginas;
    public:
    string idioma;
    Livro(string _titulo) {
        titulo = _titulo;
        genero = "Indefinido";
        autor = "indefinido";
        editora = "indefinido";
        paginas = 0;
        idioma = "indefinido";
    }

    void setTitulo (string _titulo) {
        titulo = _titulo;
    }

    string getTitulo () {
        return titulo;
    }

    void setGenero (string _genero) {
        genero = _genero;
    }

    string getGenero () {
        return genero;
    }

    void setAutor (string _autor) {
        autor = _autor;
    }

    string getAutor () {
        return autor;
    }

    void setEditora (string _editora) {
        editora = _editora;
    }

    string getEditora () {
        return editora;
    }

    void setPaginas (int _paginas) {
        paginas = _paginas;
    }

    int getPaginas () {
        return paginas;
    }

    Livro operator+(Livro livro) {  
        // Recebe o objeto livro do lado direito
        // Cria um novo objeto para receber a somatoria da quantidade de páginas dos dois objetos
        // usa o método setPaginas para ter a página do primeiro livro + a página do livro que vem como parametro (da direita)
        // retorna o livro
        Livro novoLivro("Novo Livro");
        novoLivro.setPaginas(paginas + livro.getPaginas());
        return novoLivro;
    }

    void printLivro () {
        
    cout << "Titulo: " << titulo << endl 
        << "Genero: " << genero << endl 
        << "Autor: " << autor << endl 
        << "Editora: " << editora << endl 
        << "Paginas: "  << paginas << endl
        << "idioma: " << idioma;
    }
    
};


int main () {
    Livro codigoLimpo("Codigo Limpo: Habilidades praticas do Agile software");
    Livro codigoLimpo2("Codigo Limpo 2");
    Livro codigoLimpo3("Codigo limpo 3");

    codigoLimpo.setPaginas(300);
    codigoLimpo2.setPaginas(300);

    codigoLimpo.idioma = "Portugues";
    codigoLimpo.setAutor("Robert C. Martin");
    codigoLimpo.setEditora("Alta Books; 1ª Edicao");
    codigoLimpo.setGenero("Ciencia da Computacao");

    codigoLimpo3 = codigoLimpo + codigoLimpo2;

    cout << codigoLimpo3.getPaginas();

    return 0;
}