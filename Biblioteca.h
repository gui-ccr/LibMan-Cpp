#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include "ItemDeMidia.h"
#include <memory>

using namespace std;
class Biblioteca 
{
private:
    // O coracao do polimorfismo: um vetor de ponteiros da classe base.
    // Ele pode guardar enderecos de Livros, Filmes ou qualquer outra classe que herde de ItemDeMidia.
    std::vector<std::unique_ptr<ItemDeMidia>> colecao;


public:
    // Apenas as declaracoes (assinaturas) dos metodos.
    // A implementacao deles ficara no .cpp.

    // Construtor
    Biblioteca();

    // Destrutor
    ~Biblioteca();

    // Metodos de acao
    void adicionarItem(unique_ptr<ItemDeMidia> itemParaAdicionar);
    void listarItens();
    void salvarEmArquivo(const string& nomeArquivo);
    void carregarDeArquivo(const string& nomeArquivo);
    void deletarItem(int indice);
    void emprestarItem(int indice);
    void devolverItem(int indice);
    void buscarPorTitulo(const string& tituloParaBuscar);

    // Metodo auxiliar
    bool estaVazia();
};






#endif 