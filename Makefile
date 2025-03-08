CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) -o llrec-test llrec-test.o llrec.o

# Compile llrec-test.cpp to object file
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp

# Compile llrec.cpp to object file
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 