#include "Revista.h"
#include <iostream>

using namespace std;

// --- IMPLEMENTACAO DOS METODOS DA REVISTA ---

// Implementacao do Construtor
Revista::Revista(string tituloRevista, int anoPublicadoRevista, string editoraInicial, int numeroEdicaoInicial) 
    : ItemDeMidia(tituloRevista, anoPublicadoRevista)
{
    this->editora = editoraInicial;
    this->numeroEdicao = numeroEdicaoInicial;
}

// Implementacao dos Getters
int Revista::getNumeroEdicao() {
    return this->numeroEdicao;
}

string Revista::getEditora() {
    return this->editora;
}

// Implementacao do metodo obrigatorio
void Revista::exibirDados() {
    cout << "\n--- Detalhes da Revista ---" << endl;
    cout << "Tipo: Revista " << endl;
    cout << "Titulo: \"" << titulo << "\"" << endl;
    cout << "Editora: \"" << editora << "\"" << endl;
    cout << "Numero da Edicao: " << numeroEdicao << endl;
    cout << "Ano Publicado: " << anoPublicacao << endl;
    cout << "Status: " << (this->estaEmprestado ? "Emprestado" : "Disponivel") << endl;
    cout << "-------------------------" << endl;
}