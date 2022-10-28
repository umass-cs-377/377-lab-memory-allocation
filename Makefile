CXX=g++
CXXFLAGS += -g -Wall -Wextra -pthread
CPPFLAGS += -isystem src -std=c++11


all: wood_pile allocate

wood_pile: wood_pile.o
	$(CXX) -o $@ $^

wood_pile.o: wood_pile.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

allocate: allocate.o
	$(CXX) -o $@ $^

allocate.o: allocate.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *~ *.o
	rm -f wood_pile allocate
