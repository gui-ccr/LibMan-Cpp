/*
 * ===================================================================================
 * Projeto Final: Sistema de Gerenciamento de Biblioteca de Mídia
 * ===================================================================================
 *
 * O que eu apliquei neste projeto:
 * - Classes e Objetos: Para modelar os conceitos de Midia, Livro, Filme e Biblioteca.
 * - Encapsulamento: Protegi os dados com 'private'/'protected' e criei uma interface 'public'.
 * - Heranca: Criei uma hierarquia onde Livro e Filme sao tipos de ItemDeMidia.
 * - Polimorfismo: Usei um vetor de ponteiros da classe base para gerenciar objetos
 * de diferentes classes filhas de forma uniforme, com metodos 'virtual'.
 * - Classes Abstratas: Defini a classe ItemDeMidia como um "contrato" com uma
 * funcao virtual pura ('= 0'), impedindo que ela seja instanciada.
 * - std::vector: Para criar uma colecao dinamica de itens na biblioteca.
 * - Ponteiros e Gerenciamento de Memoria Dinamica: Usei 'new' para criar objetos
 * na memoria heap e 'delete' para libera-los, evitando vazamentos de memoria.
 * - Destrutores Virtuais: Garanti que a memoria fosse limpa corretamente na hierarquia.
 *
 * -----------------------------------------------------------------------------------
 * Passos da Criacao do Sistema:
 * -----------------------------------------------------------------------------------
 * Passo 1: Criei a estrutura das classes de midia (ItemDeMidia, Livro, Filme),
 * definindo a hierarquia de heranca e o contrato com a classe abstrata.
 *
 * Passo 2: Implementei a classe gerenciadora 'Biblioteca', usando composicao para
 * conter uma colecao polimorfica (um vetor de ponteiros da classe base).
 *
 * Passo 3: Refinei o gerenciamento de memoria, introduzindo 'new', 'delete' e
 * destrutores para garantir que o sistema fosse robusto e sem vazamentos.
 *
 * Passo 4: Construi a interface do usuario no 'main', com um menu interativo
 * que permitia adicionar, listar e deletar itens.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits> // Eu preciso disso para o 'std::cin.ignore()' funcionar corretamente.
#include <fstream> // usado para fazer a manipulacao de arquivos

using namespace std;

// --- CLASSE BASE ABSTRATA ---
// Esta classe serve como um "contrato". Nao posso criar objetos dela diretamente.
class ItemDeMidia
{
protected:
    // 'protected' permite que as classes filhas (Livro, Filme) acessem estes atributos diretamente.
    string titulo;
    int anoPublicacao;
    bool estaEmprestado;

public:
    // Construtor da classe base, usando a lista de inicializadores.
    ItemDeMidia(string titulo, int anoPublicacao) : titulo(titulo), anoPublicacao(anoPublicacao), estaEmprestado(false)
    {
        // O corpo fica vazio pois a inicializacao ja foi feita.
    }

    // --- FUNCAO VIRTUAL PURA ---
    // O '= 0' torna este metodo um contrato obrigatorio.
    // Toda classe filha concreta DEVE fornecer sua propria implementacao de 'exibirDados'.
    virtual void exibirDados() = 0;

    // --- DESTRUTOR VIRTUAL ---
    // Regra de ouro: Se minha classe tem pelo menos uma funcao virtual, o destrutor tambem deve ser virtual.
    // Isso garante que, ao deletar um objeto filho atraves de um ponteiro da classe mae, o destrutor
    // correto (o da classe filha) seja chamado primeiro, evitando vazamentos de memoria.
    virtual ~ItemDeMidia() {}

    int getAnoPublicacao() {
    return anoPublicacao;
}

    // Getter para o titulo, util para mensagens de confirmacao.
    string getTitulo()
    {
        return titulo;
    }
    bool isEmprestado()
    {
        return estaEmprestado;
    }
    void setEmprestado(bool status)
    {
        this->estaEmprestado = status;
    }
};

// --- CLASSE DERIVADA: LIVRO ---
class Livro : public ItemDeMidia
{
private: // Usei 'private' aqui para o encapsulamento mais forte.
    int quantidadePaginas;
    string edicao;
    string autor;

public:
    // Construtor do Livro.
    // Ele recebe todos os dados e passa os que pertencem a mae para o construtor dela.
    Livro(string tituloLivro, int anoPublicadoLivro, string edicaoLivro, string autorLivro, int paginas)
        : ItemDeMidia(tituloLivro, anoPublicadoLivro) // Chamando o construtor da mae.
    {
        // Depois de chamar o construtor da mae, eu inicializo meus proprios atributos.
        this->edicao = edicaoLivro;
        this->autor = autorLivro;
        this->quantidadePaginas = paginas;
    }
    string getAutor() { return autor; }
    string getEdicao() { return edicao;}
    int getNumeroPaginas() { return quantidadePaginas; }

    // --- CUMPRINDO O CONTRATO ---
    // Eu sou obrigado a implementar este metodo. 'override' confirma que estou sobrescrevendo.
    void exibirDados() override
    {
        std::cout << "--- Detalhes do Livro ---" << std::endl;
        std::cout << "Tipo: Livro " << std::endl;
        std::cout << "Titulo: \"" << titulo << "\"" << std::endl; // 'titulo' e 'anoPublicacao' sao herdados.
        std::cout << "Autor: \"" << autor << "\"" << std::endl;
        std::cout << "Edicao: (" << edicao << ")" << std::endl;
        std::cout << "Ano Publicado: " << anoPublicacao << std::endl;
        std::cout << "Paginas: " << quantidadePaginas << std::endl;
        std::cout << "-------------------------" << std::endl
                  << std::endl;

        std::cout << "---- Status ----";
        if (estaEmprestado)
        {
            std::cout << std::endl << "Emprestado" << std::endl;
        }
        else
        {
            std::cout << std::endl << "Disponivel" << std::endl;
        }
    }
};

// --- CLASSE DERIVADA: FILME ---
class Filme : public ItemDeMidia
{
private:
    double duracao; // Em minutos
    string diretor;

public:
    // Construtor do Filme, segue a mesma logica do construtor de Livro.
    Filme(string tituloFilme, int anoPublicadoFilme, string diretorFilme, double duracaoFilme)
        : ItemDeMidia(tituloFilme, anoPublicadoFilme)
    {
        this->duracao = duracaoFilme;
        this->diretor = diretorFilme;
    }
    double getDuracao() { return duracao; }
    string getDiretor() { return diretor; }

    // Cumprindo o contrato com a implementacao especifica para Filme.
    void exibirDados() override
    {
        std::cout << "--- Detalhes do Filme ---" << std::endl;
        std::cout << "Tipo: Filme " << std::endl;
        std::cout << "Titulo: \"" << titulo << "\"" << std::endl;
        std::cout << "Diretor: \"" << diretor << "\"" << std::endl;
        std::cout << "Ano Publicado: " << anoPublicacao << std::endl;
        std::cout << "Duracao: " << duracao << " minutos" << std::endl;
        std::cout << "-------------------------" << std::endl
                  << std::endl;

        std::cout << "---- Status ----";
        if (estaEmprestado)
        {
            std::cout << endl << "Emprestado" << std::endl;
        }
        else
        {
            std::cout << endl << "Disponivel" << std::endl;
        }
    }
};

// --- CLASSE DERIVADA: Revista ---
class Revista : public ItemDeMidia
{
private:
    string editora;
    int numeroEdicao;

public:
    // -- Construtor --
    Revista(string tituloRevista, int anoPublicadoRevista, string editoraInicial, int numeroEdicaoInicial) : ItemDeMidia(tituloRevista, anoPublicadoRevista)
    {
        this->editora = editoraInicial;
        this->numeroEdicao = numeroEdicaoInicial;
    }

    int getNumeroEdicao(){return numeroEdicao;}
    string getEditora(){return editora;}

    void exibirDados() override
    {
        std::cout << "--- Detalhes da Revista ---" << std::endl;
        std::cout << "Tipo: Revista " << std::endl;
        std::cout << "Titulo: \"" << titulo << "\"" << std::endl;
        std::cout << "Ano Publicado: " << anoPublicacao << std::endl;
        std::cout << "Numero da Edição: (" << numeroEdicao << ")" << std::endl;
        std::cout << "Editora: \"" << editora << "\"" << std::endl;
        std::cout << "-------------------------" << std::endl
                  << std::endl;

        std::cout << "---- Status ----";
        if (estaEmprestado)
        {
            std::cout << endl << "Emprestado" << std::endl;
        }
        else
        {
            std::cout << endl << "Disponivel" << std::endl;
        }
    }
};

// --- CLASSE GERENCIADORA ---
// Esta classe usa Composicao. Ela "tem uma" colecao de mídias.
class Biblioteca
{
private:
    // O coracao do polimorfismo: um vetor de ponteiros da classe base.
    // Ele pode guardar enderecos de Livros, Filmes ou qualquer outra classe que herde de ItemDeMidia.
    vector<ItemDeMidia*> colecao;

public:
    // Construtor da Biblioteca.
    Biblioteca()
    {
        std::cout << std::endl
                  << "Sistema da Biblioteca iniciado!" << std::endl;
    }

    // Destrutor da Biblioteca. E aqui que eu limpo a memoria alocada com 'new'.
    ~Biblioteca()
    {
        std::cout << "\nLimpando a memoria da Biblioteca e encerrando o sistema..." << std::endl;
        // Para cada ponteiro na minha colecao...
        for (ItemDeMidia *itemPtr : colecao)
        {
            // ...eu chamo 'delete' para liberar a memoria do objeto na heap.
            delete itemPtr;
        }
    }

    // Adiciona um novo item a colecao. Recebe um ponteiro para um ItemDeMidia.
    void adicionarItem(ItemDeMidia *itemParaAdicionar)
    {
        colecao.push_back(itemParaAdicionar);
        std::cout << "Item \"" << itemParaAdicionar->getTitulo() << "\" adicionado a biblioteca." << std::endl;
    }

    // Lista todos os itens da colecao de forma polimorfica.
    void listarItens()
    {
        std::cout << "\n===== ITENS NA BIBLIOTECA =====" << std::endl;

        // .empty() e um metodo do vetor que retorna 'true' se ele estiver vazio.
        if (colecao.empty())
        {
            std::cout << "A biblioteca esta vazia." << std::endl;
        }
        else
        {
            int indice = 0;
            // Para cada ponteiro 'itemPtr' na minha 'colecao'...
            for (ItemDeMidia *itemPtr : colecao)
            {
                // ...eu chamo o metodo 'exibirDados'. A versao correta (de Livro ou Filme)
                // sera executada automaticamente. Isso e' polimorfismo!
                std::cout << "\n[" << indice + 1 << "]"; // Mostro um numero para o usuario.
                itemPtr->exibirDados();
                indice++;
            }
        }
        std::cout << "===============================" << std::endl;
    }

    // Dentro da sua classe Biblioteca

    void buscarPorTitulo(const string &tituloParaBuscar)
    {
        std::cout << std::endl
                  << "\nBuscando por \"" << tituloParaBuscar << "\"..." << std::endl;

        // Variavel de ajuda para sabermos se encontramos o item durante o loop.
        bool encontrado = false;

        // 1. Percorremos TODA a colecao primeiro.
        for (ItemDeMidia *itemPtr : colecao)
        {
            // Se o titulo do item atual for igual ao que estamos buscando...
            if (itemPtr->getTitulo() == tituloParaBuscar)
            {

                // ...avisamos que encontramos e mostramos seus detalhes.
                std::cout << std::endl
                          << "Item encontrado!" << std::endl;
                itemPtr->exibirDados(); // <-- CORRECAO 1

                // Marca que encontramos para nao mostrar a mensagem de erro depois.
                encontrado = true;

                // Poderia colocar um 'break;' aqui para sair do loop mais cedo,
                // ja que ja encontramos o que queriamos. Mas nao e' obrigatorio.
            }
        }

        // 2. DEPOIS que o loop terminou, nos checamos a nossa variavel.
        // Se ela ainda for 'false', significa que o loop terminou e nada foi encontrado.
        if (!encontrado)
        { // <-- CORRECAO 2
            std::cout << std::endl
                      << "Nenhum item com o titulo \"" << tituloParaBuscar << "\" foi encontrado na biblioteca." << std::endl;
        }
    }

    // empresta 1 item
    void emprestarItem(int indice)
    {
        if (indice < 0 || indice >= colecao.size())
        {
            std::cout << "Erro: Indice invalido." << std::endl;
            return; // Saio do metodo.
        }
        ItemDeMidia *itemParaEmprestar = colecao[indice];

        if (itemParaEmprestar->isEmprestado())
        {
            std::cout << "O item \"" << itemParaEmprestar->getTitulo() << "\" ja esta emprestado." << std::endl;
        }
        else
        {
            itemParaEmprestar->setEmprestado(true);

            // Depois, avise o usuario.
            std::cout << "Voce emprestou o item \"" << itemParaEmprestar->getTitulo() << "\" com sucesso." << std::endl;
        }
    }

    // devolve o item

    // dentro da classe Biblioteca
    void devolverItem(int indice)
    {
        // Sua validacao de indice (continua perfeita)
        if (indice < 0 || indice >= colecao.size())
        {
            std::cout << "Erro: Indice invalido." << std::endl;
            return;
        }

        ItemDeMidia *itemParaDevolver = colecao[indice];

        // --- LOGICA CORRIGIDA ---

        // Checamos se o item ESTA realmente emprestado para poder devolve-lo.
        if (itemParaDevolver->isEmprestado())
        { // Se for 'true'...

            // ...entao fazemos a devolucao!
            // 1. Mudamos o status para 'false' (disponivel)
            itemParaDevolver->setEmprestado(false);

            // 2. Avisamos o usuario do sucesso.
            std::cout << "Voce devolveu o item \"" << itemParaDevolver->getTitulo() << "\" com sucesso." << std::endl;
        }
        else
        { // Se 'isEmprestado()' for 'false'...

            // ...o item ja estava na biblioteca. Apenas informamos o usuario.
            std::cout << "O item \"" << itemParaDevolver->getTitulo() << "\" ja estava disponivel." << std::endl;
        }
    }
    // Deleta um item da colecao e da memoria.
    void deletarItem(int indice)
    {
        // Primeiro, eu valido se o indice que o usuario digitou e' valido.
        if (indice < 0 || indice >= colecao.size())
        {
            std::cout << "Erro: Indice invalido. Nenhum item foi deletado." << std::endl;
            return; // Saio do metodo.
        }

        // ORDEM CRUCIAL:
        // 1. Libero a memoria do objeto na heap.
        delete colecao[indice];
        // 2. Removo o ponteiro (que agora aponta para memoria invalida) do vetor.
        colecao.erase(colecao.begin() + indice);

        std::cout << "Item deletado com sucesso!" << std::endl;
    }

    // Metodo auxiliar para verificar se a biblioteca esta vazia, encapsulando a logica.
    bool estaVazia()
    {
        return colecao.empty();
    }
void salvarEmArquivo(const string& nomeArquivo) {
    // ofstream (output file stream) e a classe que usamos para ESCREVER em arquivos.
    // Eu crio um objeto 'arquivo' e passo o nome do arquivo que quero criar/sobrescrever.
    ofstream arquivo(nomeArquivo);

    // E uma boa pratica sempre verificar se o arquivo foi aberto com sucesso.
    if (!arquivo.is_open()) {
        cout << "Erro: Nao foi possivel abrir o arquivo para salvar." << endl;
        return; // Sai do metodo se nao conseguir abrir o arquivo.
    }

    cout << "\nSalvando dados da biblioteca em " << nomeArquivo << "..." << endl;

    // Para cada item na minha colecao...
    for (ItemDeMidia* itemPtr : colecao) {
        // ...eu preciso descobrir qual e' o seu tipo real para salvar os dados corretos.
        // Para isso, eu uso o 'dynamic_cast'.

        // Eu tento "converter" o ponteiro generico para um ponteiro de Livro.
        Livro* livroPtr = dynamic_cast<Livro*>(itemPtr);
        Filme* filmePtr = dynamic_cast<Filme*>(itemPtr);
        Revista* revistaPtr = dynamic_cast<Revista*>(itemPtr);
        // Adicione aqui um para Revista, se voce ja a criou
        // Revista* revistaPtr = dynamic_cast<Revista*>(itemPtr);

        if (livroPtr != nullptr) { // Se a conversao para Livro funcionou...
            arquivo << "LIVRO" << endl;
            arquivo << livroPtr->getTitulo() << endl;
            arquivo << livroPtr->getAnoPublicacao() << endl;
            arquivo << livroPtr->getAutor() << endl;
            arquivo << livroPtr->getEdicao() << endl;
            arquivo << livroPtr->getNumeroPaginas() << endl;
            arquivo << livroPtr->isEmprestado() << endl; // Salva 0 para false, 1 para true
        } 
        else if (filmePtr != nullptr) { // Se a conversao para Filme funcionou...
            arquivo << "FILME" << endl;
            arquivo << filmePtr->getTitulo() << endl;
            arquivo << filmePtr->getAnoPublicacao() << endl;
            arquivo << filmePtr->getDiretor() << endl;
            arquivo << filmePtr->getDuracao() << endl;
            arquivo << filmePtr->isEmprestado() << endl;
        }
        else if (revistaPtr != nullptr) { // Se a conversao para Filme funcionou...
            arquivo << "REVISTA" << endl;
            arquivo << revistaPtr->getTitulo() << endl;
            arquivo << revistaPtr->getAnoPublicacao() << endl;
            arquivo << revistaPtr->getEditora()<< endl;
            arquivo << revistaPtr->getNumeroEdicao() << endl;
            arquivo << revistaPtr->isEmprestado() << endl;
        }
    }

    // Eu fecho o arquivo quando termino de escrever nele.
    arquivo.close();
    cout << "Dados salvos com sucesso!" << endl;
}

    void carregarDeArquivo(const string& nomeArquivo){
        // Limpa a colecao atual para nao duplicar itens se o metodo for chamado mais de uma vez
    for (ItemDeMidia* itemPtr : colecao) {
        delete itemPtr;
    }
    colecao.clear(); // Esvazia o vetor

        ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) { /* ... */ return; }

    string linha, tipo;
    
    while (getline(arquivo, tipo)) {
        
        // --- LOGICA MAIS SEGURA PARA O LIVRO ---
        if (tipo == "LIVRO") {
            string titulo, autor, edicao;
            int ano = 0, paginas = 0, emprestadoInt = 0; // Inicializamos com valores padrao

            // Leitura de strings (nao precisa de verificacao extra)
            getline(arquivo, titulo);
            
            // --- VERIFICACAO ANTES DE CONVERTER ---
            if (getline(arquivo, linha) && !linha.empty()) {
                ano = stoi(linha); 
            }

            getline(arquivo, autor);
            getline(arquivo, edicao);

            // --- VERIFICACAO ANTES DE CONVERTER ---
            if (getline(arquivo, linha) && !linha.empty()) {
                paginas = stoi(linha);
            }

            // --- VERIFICACAO ANTES DE CONVERTER ---
            if (getline(arquivo, linha) && !linha.empty()) {
                emprestadoInt = stoi(linha);
            }

            Livro* novoLivro = new Livro(titulo, ano, edicao, autor, paginas);
            novoLivro->setEmprestado(emprestadoInt == 1);
            colecao.push_back(novoLivro);

        } 
           else if (tipo == "FILME") {
            string titulo, diretor;
            int ano = 0, emprestadoInt = 0;
            double duracao = 0.0;

            getline(arquivo, titulo);
            if (getline(arquivo, linha) && !linha.empty()) { ano = stoi(linha); }
            getline(arquivo, diretor);
            if (getline(arquivo, linha) && !linha.empty()) { duracao = stod(linha); } // stod para double
            if (getline(arquivo, linha) && !linha.empty()) { emprestadoInt = stoi(linha); }

            Filme* novoFilme = new Filme(titulo, ano, diretor, duracao);
            novoFilme->setEmprestado(emprestadoInt == 1);
            colecao.push_back(novoFilme);
        }
            else if (tipo == "REVISTA") {
                string titulo, editora;
                int ano,emprestadoInt, edicao;

                getline(arquivo, titulo);
                if (getline(arquivo, linha) && !linha.empty()) { ano = stoi(linha); }
                getline(arquivo, editora);
                if (getline(arquivo, linha) && !linha.empty()) { edicao = stoi(linha); }
                if (getline(arquivo, linha) && !linha.empty()) { emprestadoInt = stoi(linha); }


                Revista* novaRevista = new Revista(titulo,ano,editora,edicao);
                novaRevista->setEmprestado(emprestadoInt == 1);
                colecao.push_back(novaRevista);
            }
        }
        
        cout << "Dados da biblioteca carregados com sucesso!" << endl;
    arquivo.close();
        

    }
};

// --- INTERFACE DO USUARIO ---
int main()
{
    const string NOME_ARQUIVO = "biblioteca.txt"; // Guarda o nome do arquivo em uma constante
    Biblioteca minhaBiblioteca;
    
    // ---> PASSO 1: Carrega os dados do arquivo ao iniciar
    minhaBiblioteca.carregarDeArquivo(NOME_ARQUIVO);

    int opcao = -1;

    // Loop principal da aplicacao. So para quando a opcao for 0.
    while (true)
    {
        std::cout << "\n--- MENU DA BIBLIOTECA ---" << std::endl;
        std::cout << "1. Adicionar Livro" << std::endl;
        std::cout << "2. Adicionar Filme" << std::endl;
        std::cout << "3. Adicionar Revista" << std::endl;
        std::cout << "4. Listar Todos os Itens" << std::endl;
        std::cout << "5. Deletar Item" << std::endl;
        std::cout << "6. Buscar por Titulo" << std::endl;
        std::cout << "7. Emprestar Item" << std::endl;
        std::cout << "8. Devolver Item" << std::endl;
        std::cout << "0. Sair do Programa" << std::endl;
        std::cout << "Escolha uma opcao: ";

        std::cin >> opcao;

        // Eu verifico se a entrada do 'std::cin' falhou (ex: o usuario digitou uma letra).
        if (std::cin.fail())
        { // 1. "A operacao de leitura falhou?"
            // Se sim, faca o seguinte:

            std::cout << "Entrada invalida..." << std::endl;

            std::cin.clear(); // 2. "Limpe o 'sinal de erro' para que o cin volte a funcionar."

            // 3. "Ignore e descarte tudo o que o usuario digitou de errado nesta linha
            //    para que possamos pedir a entrada novamente sem ler o lixo de novo."
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcao)
        {
        case 1:
        {
            string tituloG, autorG, edicaoG;
            int anoG, paginasG;

            std::cout << "Digite o titulo do livro: ";
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpo o buffer antes do getline.
            getline(std::cin, tituloG);

            std::cout << "Digite o autor do livro: ";
            getline(std::cin, autorG);

            std::cout << "Digite a edicao do livro: ";
            getline(std::cin, edicaoG);

            std::cout << "Digite o ano de publicacao: ";
            std::cin >> anoG;

            std::cout << "Digite a quantidade de paginas: ";
            std::cin >> paginasG;

            // Crio o objeto na heap com 'new' e passo o ponteiro para a biblioteca.
            minhaBiblioteca.adicionarItem(new Livro(tituloG, anoG, edicaoG, autorG, paginasG));

            break;
        }
        case 2:
        {
            string tituloG, diretorG;
            int anoG;
            double duracaoG;

            std::cout << "Digite o titulo do Filme: ";
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(std::cin, tituloG);

            std::cout << "Digite o diretor do Filme: ";
            getline(std::cin, diretorG);

            std::cout << "Digite o ano de publicacao: ";
            std::cin >> anoG;

            std::cout << "Digite a duracao em horas: ";
            int duracaohoras;
            std::cin >> duracaohoras;
            duracaoG = duracaohoras * 60;

            minhaBiblioteca.adicionarItem(new Filme(tituloG, anoG, diretorG, duracaoG));

            break;
        }
        case 3:
        {
            string tituloG, editoraG;
            int anoG, edicaoG;

            std::cout << "Digite o titulo do Revista: ";
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(std::cin, tituloG);

            std::cout << "Digite a editora da Revista: ";
            getline(std::cin, editoraG);

            std::cout << "Digite o ano de publicacao: ";
            std::cin >> anoG;

            std::cout << "Digite a edicao da Revista: ";
            std::cin >> edicaoG;

            minhaBiblioteca.adicionarItem(new Revista(tituloG, anoG, editoraG, edicaoG));

            break;
        }
        case 4:
        {
            minhaBiblioteca.listarItens();
            break;
        }
        case 5:
        {
            if (minhaBiblioteca.estaVazia())
            {
                std::cout << "\nA biblioteca ja esta vazia. Nao ha itens para deletar." << std::endl;
            }
            else
            {
                minhaBiblioteca.listarItens();
                std::cout << "Digite o numero do item que deseja deletar (ou 0 para cancelar): ";
                int indiceParaDeletar;
                std::cin >> indiceParaDeletar;

                if (indiceParaDeletar > 0)
                {
                    // Converte o indice do usuario (base 1) para o indice do vetor (base 0).
                    minhaBiblioteca.deletarItem(indiceParaDeletar - 1);
                }
                else
                {
                    std::cout << "Delecao cancelada." << std::endl;
                }
            }
            break;
        }
        case 6:
        {
            string tituloBuscado;

            std::cout << "Digite o titulo que deseja buscar: ";
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::getline(std::cin, tituloBuscado);
            minhaBiblioteca.buscarPorTitulo(tituloBuscado);

            break;
        }
            // ... dentro do seu switch ...

        case 7:
        { // Supondo que 7 seja "Emprestar Item"
            // E uma boa pratica checar se a biblioteca esta vazia primeiro.
            if (minhaBiblioteca.estaVazia())
            {
                cout << "\nA biblioteca esta vazia. Nao ha itens para emprestar." << endl;
            }
            else
            {
                // 1. Mostra a lista para o usuario escolher
                minhaBiblioteca.listarItens();

                // 2. Pede para o usuario digitar o numero
                cout << "Digite o numero do item que deseja emprestar (ou 0 para cancelar): ";
                int indiceParaEmprestar;
                cin >> indiceParaEmprestar; // 3. Le a escolha do usuario

                // 4. Se o usuario nao cancelou, chama o metodo com o indice ajustado
                if (indiceParaEmprestar > 0)
                {
                    // Lembre-se de subtrair 1, pois a lista para o usuario comeca em 1, mas o vetor em 0.
                    minhaBiblioteca.emprestarItem(indiceParaEmprestar - 1);
                }
                else
                {
                    cout << "Operacao cancelada." << endl;
                }
            }
            break;
        }

        case 8:
        { // Supondo que 8 seja "Devolver Item"
            if (minhaBiblioteca.estaVazia())
            {
                cout << "\nA biblioteca esta vazia. Nao ha itens para devolver." << endl;
            }
            else
            {
                minhaBiblioteca.listarItens();
                cout << "Digite o numero do item que deseja devolver (ou 0 para cancelar): ";
                int indiceParaDevolver;
                cin >> indiceParaDevolver;

                if (indiceParaDevolver > 0)
                {
                    minhaBiblioteca.devolverItem(indiceParaDevolver - 1);
                }
                else
                {
                    cout << "Operacao cancelada." << endl;
                }
            }
            break;
        }
        case 0:
        {
            break; // Apenas sai do switch. O 'if' abaixo vai sair do while.
        }
        default:
        {
            std::cout << "Opcao invalida! Por favor, tente novamente." << std::endl;
            break;
        }
        } // Fim do switch

        // Condicao para sair do loop principal.
        if (opcao == 0)
        {
            break;
        }
    }

    // ---> PASSO 2: Salva os dados no arquivo antes de fechar
    minhaBiblioteca.salvarEmArquivo(NOME_ARQUIVO);
    

    return 0; // O programa termina aqui. O objeto 'minhaBiblioteca' sai de escopo
              // e seu destrutor (~Biblioteca) e' chamado automaticamente, limpando a memoria.
}