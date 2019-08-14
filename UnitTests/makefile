CC=g++
INC=./../inc
INCDIRS=-I${INC}
CFLAGS=${INCDIRS} -c -Wall -std=c++11
VPATH=../src
LDFLAGS=
SOURCES= TestMatrixEntry.cpp TestSMNormalizer.cpp TestDataHelper.cpp SMNormalizer.cpp IsingModel.cpp DataHelper.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Ising_UnitTest

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lboost_unit_test_framework

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean :
	-rm *.o Ising_UnitTest

