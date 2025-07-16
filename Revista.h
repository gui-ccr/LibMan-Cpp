#ifndef REVISTA_H
#define REVISTA_H

// 1. Incluimos o "cardapio" da classe mae para podermos herdar dela.
#include "ItemDeMidia.h"
#include <string>

using namespace std;

// --- DECLARACAO DA CLASSE Revista ---
//    Ela herda publicamente de ItemDeMidia.
class Revista : public ItemDeMidia
{
private: 
    // Atributos que sao exclusivos de um Revista.
    string editora;
    int numeroEdicao;

public:
    // Apenas as declaracoes dos metodos do Revista.

    // Construtor do Revista.
    Revista(string tituloRevista, int anoPublicadoRevista, string editoraInicial, int numeroEdicaoInicial);
    
    // Getters para seus atributos proprios.
    string getEditora();
    int getNumeroEdicao();

    // Sobrescrita do metodo virtual da classe mae para cumprir o "contrato".
    void exibirDados() override;
};

#endif // Fim do REVISTA_H