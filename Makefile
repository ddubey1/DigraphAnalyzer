CONSERVATIVE_FLAGS = -std=c++11 -pedantic -Wall -Wextra
DEBUGGING_FLAGS = -g
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

# Creates executable for running and testing.
digraph_analyzer: digraph_analyzer.o digraph_functions.o
	g++ -o digraph_analyzer digraph_analyzer.o digraph_functions.o

# Creates object files from .cpp files.
digraph_analyzer.o: digraph_analyzer.cpp  digraph_functions.h
	g++ -c digraph_analyzer.cpp $(CFLAGS)

digraph_functions.o: digraph_functions.cpp digraph_functions.h
	g++ -c digraph_functions.cpp $(CFLAGS)

# Gets rid of object files and executables.
clean:
	rm -f *.o main