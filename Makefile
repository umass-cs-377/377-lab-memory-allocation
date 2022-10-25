CXX=g++
CXXFLAGS += -g -Wall -Wextra -pthread
CPPFLAGS += -isystem src -std=c++11


%.o: %.cpp 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

wood_pile: wood_pile.o
	$(CXX) -o $@ $^

clean:
	rm -f *~ *.o
	rm -f wood_pile
