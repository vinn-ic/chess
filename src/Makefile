# Nome do executável
TARGET = main

# Código fonte
SRC = main.cpp

# Caminhos e flags (ajuste para subir um nível)
INCLUDE = -I./media/vinicius-pc/PENDRIVE/raylib/include
LIBS = -L./media/vinicius-pc/PENDRIVE/raylib/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Compilador
CXX = g++

# Regra principal
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(INCLUDE) $(LIBS)

# Limpeza
clean:
	rm -f $(TARGET)
