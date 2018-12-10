IDIR =../include
CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11

ODIR=../obj

LIBS= -lm -lGL -lGLU -lglut `pkg-config --libs --cflags opencv`

_DEPS= ControlClass.hpp ViewClass.hpp City.hpp BuildingsClass.hpp HousesClass.hpp LightClass.hpp Utils.hpp
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ= ControlClass.o ViewClass.o City.o HousesClass.o LightClass.o Utils.o
OBJ= $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBS)

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o City Main.cpp $(OBJ) $(LIBS)

.PHONY: call

call: $(OBJ)
	$(CXX) $(CXXFLAGS) -o City Main.cpp $(OBJ) $(LIBS)
	./City

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
	rm City