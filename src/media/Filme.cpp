// 1. Incluimos o "cardapio" do Filme para saber quais metodos implementar.
#include "../media/Filme.h"
#include <iostream>

using namespace std;

// --- IMPLEMENTACAO DOS METODOS DO FILME ---
// Usamos Filme:: para conectar cada implementacao a classe Filme.

// Implementacao do Construtor
Filme::Filme(string tituloFilme, int anoPublicadoFilme, string diretorFilme, double duracaoFilme)
    : ItemDeMidia(tituloFilme, anoPublicadoFilme) // Passa os dados para a classe mae.
{
    // E aqui inicializamos apenas os atributos que sao do proprio Filme.
    this->diretor = diretorFilme;
    this->duracao = duracaoFilme;
}

// Implementacao dos Getters
string Filme::getDiretor() {
    return this->diretor;
}

double Filme::getDuracao() {
    return this->duracao;
}

// Implementacao do metodo obrigatorio do "contrato".
void Filme::exibirDados() {
    cout << "\n--- Detalhes do Filme ---" << endl;
    cout << "Tipo: Filme " << endl;
    cout << "Titulo: \"" << this->titulo << "\"" << endl;
    cout << "Diretor: \"" << this->diretor << "\"" << endl;
    cout << "Ano Publicado: " << this->anoPublicacao << endl;
    cout << "Duracao: " << this->duracao << " minutos" << endl;
    cout << "Status: " << (this->estaEmprestado ? "Emprestado" : "Disponivel") << endl;
    cout << "-------------------------" << endl;
}