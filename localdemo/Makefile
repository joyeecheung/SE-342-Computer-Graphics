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

_OBJ = teapot.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(EXECUTABLE)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(EXECUTABLE)
