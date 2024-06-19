CXX=clang++
CXXFLAGS=-std=c++20 -Werror -Wall
VALGRIND_FLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-exitcode=99
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SOURCES=src/Complex.cpp
DEMO_SOURCES=main.cpp
TESTSOURCES=tests/TestCounter.cpp tests/Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
DEMO_OBJECTS=$(DEMO_SOURCES:.cpp=.o)
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)

HEADERS=include/Node.h \
        include/Tree.h \
        include/doctest.h \
        include/iterators/IteratorType.h \
        include/iterators/PreOrderIterator.h \
        include/iterators/PostOrderIterator.h \
        include/iterators/InOrderIterator.h \
        include/iterators/BFSIterator.h \
        include/iterators/DFSIterator.h \
        include/iterators/MinHeapIterator.h \
        include/Complex.h \
        include/TreeWidget.h

TEMPLATES=src/Node.tpp \
          src/Tree.tpp \
          src/iterators/PreOrderIterator.tpp \
          src/iterators/PostOrderIterator.tpp \
          src/iterators/InOrderIterator.tpp \
          src/iterators/BFSIterator.tpp \
          src/iterators/DFSIterator.tpp \
          src/iterators/MinHeapIterator.tpp

demo: $(DEMO_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEMO_OBJECTS) $(OBJECTS) -o demo $(LDFLAGS)

test: $(TESTOBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(TESTOBJECTS) $(OBJECTS) -o test 

src/%.o: src/%.cpp $(HEADERS) $(TEMPLATES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

tests/%.o: tests/%.cpp $(HEADERS) $(TEMPLATES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

rundemo: demo
	 ./demo

runtests: test
	./test

tidy:
	clang-tidy $(SOURCES) $(DEMO_SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

demovalgrind: demo
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "==" || true; }

testvalgrind: test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "==" || true; }

clean:
	rm -f *.o demo test
	rm -f src/*.o
	rm -f src/iterators/*.o
	rm -f tests/*.o
