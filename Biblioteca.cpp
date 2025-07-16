// Biblioteca.cpp

#include "Biblioteca.h" // Incluimos o "cardapio"
#include <iostream>
#include <fstream>

// Incluimos os .h das classes filhas porque precisamos cria-las com 'make_unique' aqui
#include "Livro.h"
#include "Filme.h"
#include "Revista.h"

using namespace std;

// --- IMPLEMENTACAO DOS METODOS DA BIBLIOTECA ---

// Construtor
Biblioteca::Biblioteca() {
    cout << endl << "Sistema da Biblioteca iniciado!" << endl;
}

// Destrutor (agora vazio, a limpeza e' automatica pelos unique_ptr)
Biblioteca::~Biblioteca() {
    cout << "\nLimpando a memoria da Biblioteca e encerrando o sistema..." << endl;
}

// Adicionar Item
void Biblioteca::adicionarItem(unique_ptr<ItemDeMidia> itemParaAdicionar) {
    cout << "Item \"" << itemParaAdicionar->getTitulo() << "\" adicionado a biblioteca." << endl;
    colecao.push_back(std::move(itemParaAdicionar));
}

// Listar Itens
void Biblioteca::listarItens() {
    cout << "\n===== ITENS NA BIBLIOTECA =====" << endl;
    if (colecao.empty()) {
        cout << "A biblioteca esta vazia." << endl;
    } else {
        int indice = 0;
        for (const auto& itemPtr : colecao) {
            cout << "\n[" << indice + 1 << "]";
            itemPtr->exibirDados();
            indice++;
        }
    }
    cout << "===============================" << endl;
}

// Deletar Item
void Biblioteca::deletarItem(int indice) {
    if (indice < 0 || indice >= colecao.size()) {
        cout << "Erro: Indice invalido." << endl;
        return;
    }
    colecao.erase(colecao.begin() + indice);
    cout << "Item deletado com sucesso!" << endl;
}

// Os outros metodos seguem o mesmo padrao...
void Biblioteca::emprestarItem(int indice) {
    if (indice < 0 || indice >= colecao.size()) { /*...*/ return; }
    auto& item = colecao[indice];
    if (item->isEmprestado()) {
        cout << "O item \"" << item->getTitulo() << "\" ja esta emprestado." << endl;
    } else {
        item->setEmprestado(true);
        cout << "Voce emprestou o item \"" << item->getTitulo() << "\" com sucesso." << endl;
    }
}

void Biblioteca::devolverItem(int indice) {
    if (indice < 0 || indice >= colecao.size()) { /*...*/ return; }
    auto& item = colecao[indice];
    if (item->isEmprestado()) {
        item->setEmprestado(false);
        cout << "Voce devolveu o item \"" << item->getTitulo() << "\" com sucesso." << endl;
    } else {
        cout << "O item \"" << item->getTitulo() << "\" ja estava disponivel." << endl;
    }
}

void Biblioteca::buscarPorTitulo(const string& tituloParaBuscar) {
    bool encontrado = false;
    for (const auto& itemPtr : colecao) {
        if (itemPtr->getTitulo() == tituloParaBuscar) {
            cout << "\nItem encontrado!" << endl;
            itemPtr->exibirDados();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "\nNenhum item com o titulo \"" << tituloParaBuscar << "\" foi encontrado." << endl;
    }
}

bool Biblioteca::estaVazia() {
    return colecao.empty();
}

void Biblioteca::salvarEmArquivo(const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) { /*...*/ return; }
    cout << "\nSalvando dados..." << endl;
    for (const auto& itemPtr : colecao) {
        Livro* livroPtr = dynamic_cast<Livro*>(itemPtr.get());
        Filme* filmePtr = dynamic_cast<Filme*>(itemPtr.get());
        Revista* revistaPtr = dynamic_cast<Revista*>(itemPtr.get());

        if (livroPtr) {
            arquivo << "LIVRO\n" << livroPtr->getTitulo() << "\n" << livroPtr->getAnoPublicacao() << "\n"
                    << livroPtr->getAutor() << "\n" << livroPtr->getEdicao() << "\n"
                    << livroPtr->getNumeroPaginas() << "\n" << livroPtr->isEmprestado() << endl;
        } else if (filmePtr) {
            arquivo << "FILME\n" << filmePtr->getTitulo() << "\n" << filmePtr->getAnoPublicacao() << "\n"
                    << filmePtr->getDiretor() << "\n" << filmePtr->getDuracao() << "\n"
                    << filmePtr->isEmprestado() << endl;
        } else if (revistaPtr) {
            arquivo << "REVISTA\n" << revistaPtr->getTitulo() << "\n" << revistaPtr->getAnoPublicacao() << "\n"
                    << revistaPtr->getEditora() << "\n" << revistaPtr->getNumeroEdicao() << "\n"
                    << revistaPtr->isEmprestado() << endl;
        }
    }
    arquivo.close();
    cout << "Dados salvos com sucesso!" << endl;
}

void Biblioteca::carregarDeArquivo(const string& nomeArquivo) {
    colecao.clear();
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) { return; }

    string linha, tipo;
    while (getline(arquivo, tipo)) {
        if (tipo == "LIVRO") {
            string titulo, autor, edicao;
            int ano, paginas, emprestadoInt;
            getline(arquivo, titulo);
            getline(arquivo, linha); ano = stoi(linha);
            getline(arquivo, autor);
            getline(arquivo, edicao);
            getline(arquivo, linha); paginas = stoi(linha);
            getline(arquivo, linha); emprestadoInt = stoi(linha);
            auto novoItem = make_unique<Livro>(titulo, ano, edicao, autor, paginas);
            novoItem->setEmprestado(emprestadoInt == 1);
            colecao.push_back(std::move(novoItem));
        } else if (tipo == "FILME") {
            string titulo, diretor;
            int ano, emprestadoInt;
            double duracao;
            getline(arquivo, titulo);
            getline(arquivo, linha); ano = stoi(linha);
            getline(arquivo, diretor);
            getline(arquivo, linha); duracao = stod(linha);
            getline(arquivo, linha); emprestadoInt = stoi(linha);
            auto novoItem = make_unique<Filme>(titulo, ano, diretor, duracao);
            novoItem->setEmprestado(emprestadoInt == 1);
            colecao.push_back(std::move(novoItem));
        } else if (tipo == "REVISTA") {
            string titulo, editora;
            int ano, edicao, emprestadoInt;
            getline(arquivo, titulo);
            getline(arquivo, linha); ano = stoi(linha);
            getline(arquivo, editora);
            getline(arquivo, linha); edicao = stoi(linha);
            getline(arquivo, linha); emprestadoInt = stoi(linha);
            auto novoItem = make_unique<Revista>(titulo, ano, editora, edicao);
            novoItem->setEmprestado(emprestadoInt == 1);
            colecao.push_back(std::move(novoItem));
        }
    }
    arquivo.close();
    cout << "Dados da biblioteca carregados com sucesso!" << endl;
}