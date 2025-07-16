// 1. A primeira coisa que a "cozinha" faz e' incluir o "cardapio" para saber
//    o que ela precisa preparar.
#include "../core/ItemDeMidia.h" 
#include <iostream> // Incluimos iostream aqui porque usamos 'cout', etc.

// Usamos o namespace std para facilitar.
using namespace std;

// --- A IMPLEMENTACAO DOS METODOS (A "RECEITA") ---

// Para cada metodo, usamos 'ItemDeMidia::' para dizer que esta implementacao
// pertence a classe ItemDeMidia.

// Implementacao do Construtor
ItemDeMidia::ItemDeMidia(string titulo, int anoPublicacao) 
    : titulo(titulo), anoPublicacao(anoPublicacao), estaEmprestado(false)
{
    cout << "Construtor de ItemDeMidia chamado para: " << this->titulo << endl;
}

// Implementacao do Destrutor
// Mesmo que ele nao faca nada, e' uma boa pratica implementa-lo.
ItemDeMidia::~ItemDeMidia() {
    cout << "Destrutor de ItemDeMidia chamado para: " << this->titulo << endl;
}

// Implementacao dos outros metodos
string ItemDeMidia::getTitulo() {
    return this->titulo;
}

int ItemDeMidia::getAnoPublicacao() {
    return this->anoPublicacao;
}

bool ItemDeMidia::isEmprestado() {
    return this->estaEmprestado;
}

void ItemDeMidia::setEmprestado(bool status) {
    this->estaEmprestado = status;
}

// E o metodo virtual puro 'exibirDados()'?
// NAO FAZEMOS! A regra de um metodo virtual puro e' que a classe base
// NAO fornece uma implementacao. A obrigacao e' das classes filhas.