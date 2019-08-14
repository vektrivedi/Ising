CC=g++
INC=./../inc
INCDIRS=-I${INC}
CFLAGS=${INCDIRS} -c -Wall -std=c++11
VPATH=./../src
SOURCES=main.cpp SMNormalizer.cpp IsingModel.cpp DataHelper.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Ising

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean :
	-rm *.o $(EXECUTABLE)


