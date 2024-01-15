CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

CW1Final: main.cpp book.o library.o person.o
	$(CXX) $(CXXFLAGS) -o $@ $^

book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) -c $<

library.o: library.cpp library.h
	$(CXX) $(CXXFLAGS) -c $<

person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) *.o CW1Final