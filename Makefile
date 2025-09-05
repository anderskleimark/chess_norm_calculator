
# Kompilator och flaggor
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Källfiler
SRC = main.cpp app.cpp
OBJ = $(SRC:.cpp=.o)

# Exekverbart program
EXE = chess_norm_calculator

# Standardmål: Bygg programmet
all: $(EXE)

# Länkning av objektfiler för att skapa exekverbart program
$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $(EXE)

# Kompilering av .cpp till .o objektfiler
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rensa bort objektfiler och exekverbart program
clean:
	rm -f $(OBJ) $(EXE)
