#ifndef LIVRO_H
#define LIVRO_H

// 1. Incluimos o "cardapio" da classe mae.
// Agora o Livro sabe o que e' um ItemDeMidia.
#include "ItemDeMidia.h" 
#include <string>

using namespace std;

// --- DECLARACAO DA CLASSE FILHA ---
class Livro : public ItemDeMidia
{
private: 
    // Atributos que sao exclusivos de um Livro.
    int quantidadePaginas;
    string edicao;
    string autor;

public:
    // Apenas as declaracoes (assinaturas) dos metodos.
    
    // Construtor
    Livro(string tituloLivro, int anoPublicadoLivro, string edicaoLivro, string autorLivro, int paginas);
    
    // Metodos 'get' para seus atributos proprios.
    string getAutor();
    string getEdicao();
    int getNumeroPaginas();

    // Sobrescrita do metodo virtual puro da classe mae.
    void exibirDados() override;
};

#endif // Fim do LIVRO_H