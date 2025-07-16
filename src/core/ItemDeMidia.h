// Esta e uma "guarda de cabecalho" (header guard).
// Ela impede que o compilador inclua este arquivo mais de uma vez por engano,
// o que causaria erros de "redefinicao".
#ifndef ITEMDEMIDIA_H
#define ITEMDEMIDIA_H

#include <string> // Precisamos incluir string porque usamos std::string na declaracao.
#include <iostream> // Incluimos para o cout futuro

// Usamos o 'using' aqui para nao precisar escrever std:: em todo lugar neste arquivo.
using namespace std;

// --- A DECLARACAO DA CLASSE (O "CARDAPIO") ---
class ItemDeMidia
{
protected:
    string titulo;
    int anoPublicacao;
    bool estaEmprestado;

public:
    // Apenas declaramos os metodos aqui, sem o corpo {}.

    // Construtor
    ItemDeMidia(string titulo, int anoPublicacao);

    // Destrutor virtual (essencial para a hierarquia)
    virtual ~ItemDeMidia();

    // Funcao virtual pura (o nosso "contrato")
    virtual void exibirDados() = 0;

    // Outros metodos publicos
    string getTitulo();
    int getAnoPublicacao();
    bool isEmprestado();
    void setEmprestado(bool status);
};

#endif // Fim da guarda de cabecalho