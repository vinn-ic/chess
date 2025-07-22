# Nome do executável
TARGET = main

# Compilador
CXX = g++

# Arquivos fonte
SRC = main.cpp

# Diretórios de include e biblioteca
INCLUDES = -I/home/vinicius-pc/raylib/build/raylib/include/
LIBDIRS  = -L/home/vinicius-pc/raylib/build/raylib/

# Bibliotecas necessárias
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Flags de compilação
CXXFLAGS = $(INCLUDES)
LDFLAGS  = $(LIBDIRS) $(LIBS)

# Regra padrão
all:
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

# Limpar arquivos gerados
clean:
	rm -f $(TARGET)
