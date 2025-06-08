# 💿 Sistema de Gerenciamento de Biblioteca de Mídia

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue)
![License](https://img.shields.io/badge/License-MIT-green)

Este projeto é uma aplicação de console em C++ desenvolvida como parte de um estudo aprofundado sobre os pilares da **Programação Orientada a Objetos (POO)**. O sistema simula o gerenciamento de uma biblioteca que contém diferentes tipos de mídia (livros, filmes, revistas), permitindo adicionar, listar, buscar, deletar, emprestar e devolver itens, além de salvar e carregar o estado da biblioteca em um arquivo para persistência de dados.

---
## ✨ Funcionalidades

* ✅ **Adicionar Múltiplos Tipos de Mídia:** Adicionar Livros, Filmes e Revistas com seus atributos específicos.
* ✅ **Listagem Polimórfica:** Listar todos os itens da biblioteca de forma unificada, mas exibindo os detalhes específicos de cada tipo.
* ✅ **Busca por Título:** Encontrar um item na biblioteca através de seu título.
* ✅ **Gerenciamento de Empréstimos:** Controlar o status de cada item como "Disponível" ou "Emprestado" e realizar as operações de empréstimo e devolução.
* ✅ **Deleção Segura:** Remover itens da biblioteca, garantindo a liberação correta da memória.
* ✅ **Persistência de Dados:** Salvar o estado completo da biblioteca em um arquivo (`biblioteca.txt`) ao sair e carregar os dados automaticamente ao iniciar o programa.

---
## 🧠 Conceitos Aplicados

Este projeto foi uma oportunidade para aplicar na prática os conceitos fundamentais e avançados da Programação Orientada a Objetos em C++.

* ### **Encapsulamento**
    * Os atributos das classes são mantidos como `private` ou `protected`, garantindo que o estado interno dos objetos seja protegido. A interação é feita através de uma interface `public` de métodos (como `getters` e `setters`).

* ### **Herança**
    * Foi criada uma hierarquia de classes baseada na relação "é um". `Livro`, `Filme` e `Revista` são tipos de `ItemDeMidia`, herdando seus atributos e métodos comuns e evitando a repetição de código.

* ### **Polimorfismo**
    * Este é o coração do projeto. Utilizando um `std::vector` de ponteiros da classe base (`vector<ItemDeMidia*>`), o sistema consegue gerenciar todos os tipos de mídia de forma uniforme. Métodos declarados como `virtual` na classe base (como `exibirDados`) permitem que a versão correta da classe filha seja chamada em tempo de execução.

* ### **Classes Abstratas e Funções Virtuais Puras**
    * A classe `ItemDeMidia` foi definida como abstrata ao declarar o método `virtual void exibirDados() = 0;`. Isso cria um "contrato" que obriga todas as classes derivadas concretas a implementarem sua própria versão deste método, além de impedir a criação de um "item genérico".

* ### **Gerenciamento de Memória Dinâmica**
    * Os objetos de mídia são criados na memória **Heap** com o operador `new`. Isso permite que o tempo de vida deles seja controlado pela `Biblioteca`, e não pelo escopo onde foram criados.
    * O operador `delete` é usado para liberar a memória de cada objeto quando ele é removido ou quando o programa termina, evitando vazamentos de memória (memory leaks).

* ### **Destrutores Virtuais**
    * O destrutor da classe base `ItemDeMidia` foi declarado como `virtual`. Isso garante que, ao deletar um objeto derivado através de um ponteiro da classe base, a cadeia de destrutores correta seja chamada (primeiro o da filha, depois o da mãe), garantindo uma limpeza completa da memória.

* ### **Manipulação de Arquivos (`fstream`)**
    * O projeto utiliza `ofstream` para escrever os dados da coleção em um arquivo de texto e `ifstream` para ler os dados do arquivo e reconstruir os objetos ao iniciar a aplicação, garantindo a persistência dos dados.

* ### **STL (Standard Template Library)**
    * O `std::vector` foi usado como a estrutura de dados dinâmica para a coleção da biblioteca.
    * O `std::string` foi usado para toda a manipulação de texto.

---
## 🚀 Como Executar

### Pré-requisitos
* Um compilador C++ moderno (como g++).

### Compilação
No seu terminal, navegue até a pasta do projeto e execute o seguinte comando:
```bash
g++ -std=c++17 -o biblioteca seu_arquivo_fonte.cpp
```
* `g++`: O compilador.
* `-std=c++17`: Especifica o uso do padrão C++17 (pode ser C++14 ou C++20 também).
* `-o biblioteca`: Define o nome do arquivo executável de saída como `biblioteca`.
* `seu_arquivo_fonte.cpp`: Substitua pelo nome do seu arquivo `.cpp`.

### Execução
```bash
./biblioteca
```
O programa iniciará e o menu interativo será exibido no console.

---
## 🏛️ Estrutura das Classes

O projeto segue a seguinte hierarquia de classes:

```
ItemDeMidia (Abstrata)
├── Livro
├── Filme
└── Revista
```
A classe `Biblioteca` utiliza **Composição**, contendo uma coleção de ponteiros para `ItemDeMidia` para gerenciar todos os objetos.