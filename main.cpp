// =======================================================
// ARQUIVO: main.cpp
// =======================================================

// 1. Todos os includes devem ficar aqui no topo do arquivo.
#include <iostream>
#include <string>
#include <limits>
#include "Biblioteca.h" // Inclui a interface da nossa classe principal
#include "Livro.h"      // Necessario para criar Livros (make_unique<Livro>)
#include "Filme.h"      // Necessario para criar Filmes
#include "Revista.h"    // Necessario para criar Revistas

using namespace std;

// 2. So pode haver UMA funcao main() em todo o projeto.
int main()
{
    const string NOME_ARQUIVO = "biblioteca.txt";
    Biblioteca minhaBiblioteca;
    
    minhaBiblioteca.carregarDeArquivo(NOME_ARQUIVO);

    int opcao = -1;

    while (true)
    {
        cout << "\n--- MENU DA BIBLIOTECA ---" << endl;
        cout << "1. Adicionar Livro" << endl;
        cout << "2. Adicionar Filme" << endl;
        cout << "3. Adicionar Revista" << endl;
        cout << "4. Listar Todos os Itens" << endl;
        cout << "5. Deletar Item" << endl;
        cout << "6. Buscar por Titulo" << endl;
        cout << "7. Emprestar Item" << endl;
        cout << "8. Devolver Item" << endl;
        cout << "0. Sair do Programa" << endl;
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, digite um numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        // 3. O switch case completo deve estar DENTRO do while.
        switch (opcao)
        {
            case 1:
            {
                string tituloG, autorG, edicaoG;
                int anoG, paginasG;
                cout << "Digite o titulo do livro: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, tituloG);
                cout << "Digite o autor do livro: ";
                getline(cin, autorG);
                cout << "Digite a edicao do livro: ";
                getline(cin, edicaoG);
                cout << "Digite o ano de publicacao: ";
                cin >> anoG;
                cout << "Digite a quantidade de paginas: ";
                cin >> paginasG;
                minhaBiblioteca.adicionarItem(make_unique<Livro>(tituloG, anoG, edicaoG, autorG, paginasG));
                break;
            }
            case 2:
            {
                string tituloG, diretorG;
                int anoG;
                double duracaoG;
                cout << "Digite o titulo do Filme: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, tituloG);
                cout << "Digite o diretor do Filme: ";
                getline(cin, diretorG);
                cout << "Digite o ano de publicacao: ";
                cin >> anoG;
                cout << "Digite a duracao em minutos: ";
                cin >> duracaoG;
                minhaBiblioteca.adicionarItem(make_unique<Filme>(tituloG, anoG, diretorG, duracaoG));
                break;
            }
            case 3:
            {
                string tituloG, editoraG;
                int anoG, edicaoG;
                cout << "Digite o titulo da Revista: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, tituloG);
                cout << "Digite a editora da Revista: ";
                getline(cin, editoraG);
                cout << "Digite o ano de publicacao: ";
                cin >> anoG;
                cout << "Digite o numero da edicao: ";
                cin >> edicaoG;
                minhaBiblioteca.adicionarItem(make_unique<Revista>(tituloG, anoG, editoraG, edicaoG));
                break;
            }
            case 4: { minhaBiblioteca.listarItens(); break; }
            case 5:
            {
                if (minhaBiblioteca.estaVazia()) {
                    cout << "\nA biblioteca esta vazia. Nao ha itens para deletar." << endl;
                } else {
                    minhaBiblioteca.listarItens();
                    cout << "Digite o numero do item que deseja deletar (ou 0 para cancelar): ";
                    int indiceParaDeletar;
                    cin >> indiceParaDeletar;
                    if (indiceParaDeletar > 0) {
                        minhaBiblioteca.deletarItem(indiceParaDeletar - 1);
                    } else {
                        cout << "Delecao cancelada." << endl;
                    }
                }
                break;
            }
            case 6:
            {
                string tituloBuscado;
                cout << "Digite o titulo que deseja buscar: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, tituloBuscado);
                minhaBiblioteca.buscarPorTitulo(tituloBuscado);
                break;
            }
            case 7:
            {
                if (minhaBiblioteca.estaVazia()) {
                    cout << "\nA biblioteca esta vazia. Nao ha itens para emprestar." << endl;
                } else {
                    minhaBiblioteca.listarItens();
                    cout << "Digite o numero do item que deseja emprestar (ou 0 para cancelar): ";
                    int indiceParaEmprestar;
                    cin >> indiceParaEmprestar;
                    if (indiceParaEmprestar > 0) {
                        minhaBiblioteca.emprestarItem(indiceParaEmprestar - 1);
                    } else {
                        cout << "Operacao cancelada." << endl;
                    }
                }
                break;
            }
            case 8:
            {
                if (minhaBiblioteca.estaVazia()) {
                    cout << "\nA biblioteca esta vazia. Nao ha itens para devolver." << endl;
                } else {
                    minhaBiblioteca.listarItens();
                    cout << "Digite o numero do item que deseja devolver (ou 0 para cancelar): ";
                    int indiceParaDevolver;
                    cin >> indiceParaDevolver;
                    if (indiceParaDevolver > 0) {
                        minhaBiblioteca.devolverItem(indiceParaDevolver - 1);
                    } else {
                        cout << "Operacao cancelada." << endl;
                    }
                }
                break;
            }
            case 0: { break; }
            default: { cout << "Opcao invalida! Por favor, tente novamente." << endl; break; }
        }

        if (opcao == 0)
        {
            cout << "Saindo do sistema..." << endl;
            break;
        }
    }

    minhaBiblioteca.salvarEmArquivo(NOME_ARQUIVO);
    
    return 0;
}