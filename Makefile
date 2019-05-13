CXX = g++
CXXFLAGS = -O3

output: main.o dp_knapsack.o
	${CXX} main.o dp_knapsack.o -o output

dp_knapsack.o: dp_knapsack.h

clean:
	rm *.o output