ifeq ($(OS),Windows_NT)
#LDFLAGS=-lopengl32 -lglu32 -lglut32 
LDFLAGS=-lfreeglut -lopengl32 -Wl,--subsystem,windows
EXECUTABLE=main.exe
else
LDFLAGS=-lGL -lglut
EXECUTABLE=main
endif

#CFLAGS=-g -DDEBUG -DGLUT_DISABLE_ATEXIT_HACK
CFLAGS=-g -DDEBUG

all:
	g++ main.cpp -c -o main.o $(CFLAGS) 
	g++ main.o $(LDFLAGS) -o $(EXECUTABLE) 

clean:
	rm main.o $(EXECUTABLE) 
