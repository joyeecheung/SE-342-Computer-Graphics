CC=g++

ifeq ($(OS),Windows_NT)
    #LDFLAGS=-lopengl32 -lglu32 -lglut32
    LDFLAGS=-lFreeGLUT -lglu32 -lopengl32
    EXECUTABLE=main.exe
else
    LDFLAGS=-lGL -lGLU -lglut
    EXECUTABLE=main
endif

#CFLAGS=-g -DDEBUG -DGLUT_DISABLE_ATEXIT_HACK
CFLAGS=-g -DDEBUG
OBJ=main.o

all: $(EXECUTABLE)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm $(OBJ) $(EXECUTABLE)
