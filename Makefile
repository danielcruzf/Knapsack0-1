CXX = clang++
CXXFLAGS = -Ofast -march=native#-std=c++1z  -flto -funroll-loops -fopenmp

output: main.o dp_knapsack.o getdata.o
	${CXX} main.o dp_knapsack.o getdata.o -o output

dp_knapsack.o: dp_knapsack.hpp
getdata.o: getdata.hpp
main.o: dp_knapsack.hpp getdata.hpp

clean:
	rm *.o output