EXEC = Implementacao_dos_Algoritmos_de_Ordenacao.exe
CXX = g++
CXXFLAGS = -Wall -O0 -pedantic
OBJS = main.o algoritmos_de_ordenacao.o

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

main.o: main.cpp algoritmos_de_ordenacao.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

algoritmos_de_ordenacao.o: algoritmos_de_ordenacao.cpp algoritmos_de_ordenacao.hpp
	$(CXX) $(CXXFLAGS) -c algoritmos_de_ordenacao.cpp

clean:
	@if exist *.o del /Q *.o
	@if exist $(EXEC) del /Q $(EXEC)