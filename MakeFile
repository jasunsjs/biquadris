CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a.out
SOURCES = $(wildcard *.cc)   # Pick up all implementation files
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
