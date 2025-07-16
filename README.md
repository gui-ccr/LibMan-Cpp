# 💿 Sistema de Gerenciamento de Biblioteca de Mídia

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=cplusplus&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completo-brightgreen)
![License](https://img.shields.io/badge/License-MIT-green)

<details open>
<summary>🇧🇷 Português</summary>

## 📖 Sobre o Projeto

Este projeto é uma aplicação de console em C++ que simula um sistema de gerenciamento para uma biblioteca de mídias. Ele foi desenvolvido como um estudo aprofundado para aplicar e solidificar os pilares da **Programação Orientada a Objetos (POO)** em um cenário prático.

O sistema permite gerenciar uma coleção de diferentes tipos de mídia (Livros, Filmes, Revistas), suportando operações de CRUD (Criar, Ler, Atualizar, Deletar), além de funcionalidades de negócio como empréstimos e persistência de dados em arquivo.

---
## ✨ Funcionalidades

* ✅ **Adicionar Múltiplos Tipos de Mídia:** Adicionar Livros, Filmes e Revistas com seus atributos específicos.
* ✅ **Listagem Polimórfica:** Listar todos os itens da biblioteca de forma unificada, exibindo os detalhes específicos de cada tipo.
* ✅ **Busca por Título:** Encontrar um item na biblioteca através de seu título.
* ✅ **Gerenciamento de Empréstimos:** Controlar o status de cada item como "Disponível" ou "Emprestado" e realizar as operações de empréstimo e devolução.
* ✅ **Deleção Segura:** Remover itens da biblioteca, garantindo a liberação correta da memória.
* ✅ **Persistência de Dados:** Salvar o estado completo da biblioteca em um arquivo (`biblioteca.txt`) ao sair e carregar os dados automaticamente ao iniciar o programa.
* ✅ **Estrutura Profissional:** O código é organizado em arquivos de cabeçalho (`.h`) e implementação (`.cpp`), com a compilação gerenciada por um `Makefile`.

---
## 🧠 Conceitos Aplicados

Este projeto é uma demonstração prática dos seguintes conceitos avançados de C++:

* ### **Arquitetura Orientada a Objetos**
  * **Encapsulamento:** Os dados são protegidos (`private`/`protected`) e acessados através de uma interface pública, garantindo a integridade dos objetos.
  * **Herança:** Uma hierarquia de classes (`ItemDeMidia` -> `Livro`, `Filme`, etc.) foi criada para maximizar a reutilização de código e estabelecer uma relação lógica "é um".
  * **Polimorfismo:** O conceito mais importante do projeto. Usando `virtual` e `override`, o sistema trata todos os tipos de mídia através de um ponteiro da classe base, permitindo que métodos como `exibirDados()` tenham comportamentos diferentes para cada tipo de objeto.
  * **Classes Abstratas:** A classe `ItemDeMidia` é abstrata (`virtual ... = 0;`), definindo um "contrato" que obriga todas as classes de mídia concretas a implementarem funcionalidades essenciais, o que torna o design mais robusto.

* ### **Gerenciamento de Memória Moderno**
  * **Ponteiros Inteligentes (`std::unique_ptr`):** O projeto foi refatorado para usar `std::unique_ptr` em vez de ponteiros brutos (`new`/`delete`). Isso automatiza o gerenciamento de memória, seguindo o princípio RAII (Resource Acquisition Is Initialization), e previne vazamentos de memória (memory leaks) e ponteiros pendentes (dangling pointers).
  * **Destrutores Virtuais:** A classe base possui um destrutor virtual (`virtual ~ItemDeMidia()`) para garantir a limpeza correta da memória em toda a hierarquia de classes ao usar polimorfismo.

* ### **Organização de Código e Compilação**
  * **Separação de Arquivos:** O código é modularizado em arquivos de cabeçalho (`.h` para declarações) e de implementação (`.cpp` para definições), seguindo as melhores práticas da indústria.
  * **`Makefile`:** A compilação de múltiplos arquivos é automatizada através de um `Makefile`, simplificando o processo de "build" do projeto.

* ### **Biblioteca Padrão do C++ (STL)**
  * **`std::vector`:** Utilizado como a estrutura de dados dinâmica para armazenar a coleção de mídias.
  * **`std::string`:** Usado para toda a manipulação de texto.
  * **`fstream`:** Utilizado para a persistência de dados, lendo e escrevendo em um arquivo de texto.

---
## 🚀 Como Compilar e Executar

### Pré-requisitos
* Um compilador C++ (como g++).
* A ferramenta `make` instalada no seu sistema.

### Passos
1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/SEU_USUARIO/SEU_REPOSITORIO.git](https://github.com/SEU_USUARIO/SEU_REPOSITORIO.git)
    cd SEU_REPOSITORIO
    ```
2.  **Compile o projeto:**
    * Navegue até a pasta `Projeto_Sistema_Biblioteca` (ou o nome que você deu).
    * Execute o comando `make` no seu terminal. Ele irá ler o `Makefile` e compilar todos os arquivos fonte.
    ```bash
    make
    ```
3.  **Execute o programa:**
    * Após a compilação, um executável chamado `biblioteca` será criado. Para rodá-lo, use:
    ```bash
    ./biblioteca
    ```
4.  **Limpar os arquivos compilados (opcional):**
    * Para remover os arquivos objeto (`.o`) e o executável, use:
    ```bash
    make clean
    ```
</details>

<details>
<summary>🇬🇧 English</summary>

## 📖 About The Project

This project is a C++ console application that simulates a media library management system. It was developed as an in-depth study to apply and solidify the core pillars of **Object-Oriented Programming (OOP)** in a practical scenario.

The system manages a collection of different media types (Books, Movies, Magazines), supporting CRUD operations (Create, Read, Update, Delete), as well as business logic features like loans and data persistence to a file.

---
### ✨ Features

* ✅ **Add Multiple Media Types:** Add Books, Movies, and Magazines with their specific attributes.
* ✅ **Polymorphic Listing:** List all library items in a unified way, while displaying the specific details for each type.
* ✅ **Search by Title:** Find an item in the library by its title.
* ✅ **Loan Management:** Track the status of each item as "Available" or "On Loan" and perform loan and return operations.
* ✅ **Safe Deletion:** Remove items from the library, ensuring proper memory deallocation.
* ✅ **Data Persistence:** Save the complete state of the library to a file (`biblioteca.txt`) on exit and automatically load the data on startup.
* ✅ **Professional Structure:** The code is organized into header (`.h`) and implementation (`.cpp`) files, with compilation managed by a `Makefile`.

---
### 🧠 Concepts Applied

This project is a practical demonstration of the following advanced C++ concepts:

* ### **Object-Oriented Architecture**
  * **Encapsulation:** Data is protected (`private`/`protected`) and accessed through a `public` interface, ensuring object integrity.
  * **Inheritance:** A class hierarchy (`ItemDeMidia` -> `Book`, `Movie`) was created to maximize code reuse and model a logical "is-a" relationship.
  * **Polymorphism:** The core of the project. Using `virtual` and `override`, the system handles all media types through a base class pointer, allowing methods like `exibirDados()` to have different behaviors for each object type.
  * **Abstract Classes:** The `ItemDeMidia` class is abstract (`virtual ... = 0;`), defining a "contract" that forces all concrete derived classes to implement essential functionality, leading to a more robust design.

* ### **Modern Memory Management**
  * **Smart Pointers (`std::unique_ptr`):** The project was refactored to use `std::unique_ptr` instead of raw pointers (`new`/`delete`). This automates memory management following the RAII principle (Resource Acquisition Is Initialization) and prevents memory leaks and dangling pointers.
  * **Virtual Destructors:** The base class has a virtual destructor (`virtual ~ItemDeMidia()`) to ensure the correct cleanup chain in the polymorphic hierarchy.

* ### **Code Organization & Compilation**
  * **File Separation:** The code is modularized into header (`.h` for declarations) and implementation (`.cpp` for definitions) files, following industry best practices.
  * **`Makefile`:** The compilation of multiple files is automated via a `Makefile`, simplifying the project's build process.

* ### **C++ Standard Library (STL)**
  * **`std::vector`:** Used as the dynamic data structure to hold the media collection.
  * **`std::string`:** Used for all text manipulation.
  * **`fstream`:** Used for data persistence by reading from and writing to a text file.

---
### 🚀 How To Compile and Run

#### Prerequisites
* A modern C++ compiler (like g++).
* The `make` tool installed on your system.

#### Steps
1.  **Clone the repo:**
    ```bash
    git clone [https://github.com/YOUR_USERNAME/YOUR_REPO.git](https://github.com/YOUR_USERNAME/YOUR_REPO.git)
    cd YOUR_REPO
    ```
2.  **Compile the project:**
    * Navigate to the `Projeto_Sistema_Biblioteca` directory.
    * Run the `make` command in your terminal. It will read the `Makefile` and compile all source files.
    ```bash
    make
    ```
3.  **Run the program:**
    * After compilation, an executable named `biblioteca` will be created. To run it, use:
    ```bash
    ./biblioteca
    ```
4.  **Clean up compiled files (optional):**
    * To remove the object files (`.o`) and the executable, use:
    ```bash
    make clean
    ```
</details>
