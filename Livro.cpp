// 1. Incluimos o "cardapio" do Livro para saber quais metodos implementar.
#include "Livro.h" 
#include <iostream>

using namespace std;

// --- IMPLEMENTACAO DOS METODOS ---

// Usamos Livro:: para conectar cada implementacao a classe Livro.

// Implementacao do Construtor
Livro::Livro(string tituloLivro, int anoPublicadoLivro, string edicaoLivro, string autorLivro, int paginas) 
    : ItemDeMidia(tituloLivro, anoPublicadoLivro) // 2. Passamos os dados para a classe mae.
{
    // 3. E aqui inicializamos apenas os atributos que sao do proprio Livro.
    this->edicao = edicaoLivro;
    this->autor = autorLivro;
    this->quantidadePaginas = paginas;
}

// Implementacao dos Getters
string Livro::getAutor() {
    return this->autor;
}

string Livro::getEdicao() {
    return this->edicao;
}

int Livro::getNumeroPaginas() {
    return this->quantidadePaginas;
}

// Implementacao do metodo obrigatorio do "contrato".
void Livro::exibirDados() {
    cout << "\n--- Detalhes do Livro ---" << endl;
    cout << "Tipo: Livro " << endl;
    cout << "Titulo: \"" << this->titulo << "\"" << endl; // 'titulo' e 'anoPublicacao' sao herdados e 'protected'.
    cout << "Autor: \"" << this->autor << "\"" << endl;
    cout << "Edicao: (" << this->edicao << ")" << endl;
    cout << "Ano Publicado: " << this->anoPublicacao << endl;
    cout << "Paginas: " << this->quantidadePaginas << endl;
    cout << "Status: " << (this->estaEmprestado ? "Emprestado" : "Disponivel") << endl; // Operador ternario para checar o status.
    cout << "-------------------------" << endl;
}