#ifndef FILME_H
#define FILME_H

// 1. Incluimos o "cardapio" da classe mae para podermos herdar dela.
#include "ItemDeMidia.h"
#include <string>

using namespace std;

// --- DECLARACAO DA CLASSE FILME ---
//    Ela herda publicamente de ItemDeMidia.
class Filme : public ItemDeMidia
{
private: 
    // Atributos que sao exclusivos de um Filme.
    double duracao; // Em minutos
    string diretor;

public:
    // Apenas as declaracoes dos metodos do Filme.

    // Construtor do Filme.
    Filme(string tituloFilme, int anoPublicadoFilme, string diretorFilme, double duracaoFilme);
    
    // Getters para seus atributos proprios.
    string getDiretor();
    double getDuracao();

    // Sobrescrita do metodo virtual da classe mae para cumprir o "contrato".
    void exibirDados() override;
};

#endif // Fim do FILME_H