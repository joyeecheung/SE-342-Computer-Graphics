CC=g++

IDIR=include
ODIR=obj
LDIR=lib
SRCDIR=src
CFLAGS=-g -DDEBUG -I$(IDIR)

ifeq ($(OS),Windows_NT)
    LIBS=-L$(LDIR) -lFreeGLUT -lglu32 -lopengl32
    EXECUTABLE=main.exe
else
    LIBS=-L$(LDIR) -lGL -lGLU -lglut
    EXECUTABLE=main
endif

_DEPS=GLUTWindow.o Polyhedron.o Tracer.o TracingBall.o
DEPS=$(patsubst %,$(ODIR)/%,$(_DEPS))

_OBJ=main.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(EXECUTABLE)

$(ODIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXECUTABLE): $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(EXECUTABLE)
