# Define o compilador
CXX = g++
# Define as flags de compilacao
CXXFLAGS = -std=c++17 -Wall

# Nome do seu programa executavel final
TARGET = biblioteca

# Define os diretorios onde estao os arquivos fonte (.cpp)
SRCDIRS = src/core src/media src/app
# Adiciona os diretorios ao VPATH, que e' onde o 'make' procura por arquivos
VPATH = $(SRCDIRS)

# Encontra todos os arquivos .cpp dentro dos diretorios listados
SOURCES = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))
# Transforma a lista de .cpp em uma lista de .o (arquivos objeto)
OBJECTS = $(SOURCES:.cpp=.o)

# Regra principal
all: $(TARGET)

# Regra para criar o programa final, juntando todos os arquivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regra generica para compilar um .cpp para um .o
# O -Isrc/core, -Isrc/media, etc., diz ao compilador onde procurar pelos arquivos .h
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Isrc/core -Isrc/media -Isrc/app -c $< -o $@

# Regra para limpar tudo
clean:
	rm -f $(TARGET) $(OBJECTS)