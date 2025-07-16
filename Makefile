# Define o nome do nosso programa final
EXECUTAVEL = biblioteca

# Define o compilador que vamos usar
COMPILADOR = g++

# Define as flags de compilacao (padrao C++17, mostrar todos os warnings)
FLAGS = -std=c++17 -Wall

# Lista de todos os seus arquivos de implementacao (.cpp)
FONTES = main.cpp ItemDeMidia.cpp Livro.cpp Filme.cpp Revista.cpp Biblioteca.cpp

# Transforma a lista de .cpp em uma lista de .o (arquivos objeto)
OBJETOS = $(FONTES:.cpp=.o)

# Regra principal: executada quando voce digita 'make'
all: $(EXECUTAVEL)

# Regra para criar o programa final
$(EXECUTAVEL): $(OBJETOS)
	$(COMPILADOR) $(FLAGS) -o $(EXECUTAVEL) $(OBJETOS)

# Regra generica para criar um arquivo .o a partir de um .cpp
%.o: %.cpp
	$(COMPILADOR) $(FLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(EXECUTAVEL) $(OBJETOS)