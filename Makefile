CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
OBJS := llrec.o

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: 
	$(CXX) $(CXXFLAGS) -o $@

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c amazon.cpp

llrec.o: llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 