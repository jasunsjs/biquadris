CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Isrc/includes

EXEC = biquadris
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
OBJECTS = $(SOURCES:.cc=.o)
DEPENDS = $(OBJECTS:.o=.d)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC) -lX11

-include $(DEPENDS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(EXEC) $(DEPENDS)
