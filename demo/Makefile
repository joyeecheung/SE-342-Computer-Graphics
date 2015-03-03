#LDFLAGS=-lopengl32 -lglu32 -lglut32 
LDFLAGS=-lfreeglut -lopengl32 -Wl,--subsystem,windows
#CFLAGS=-g -DDEBUG -DGLUT_DISABLE_ATEXIT_HACK
CFLAGS=-g -DDEBUG

all:
	g++ main.cpp -c -o main.o $(CFLAGS) 
	g++ main.o $(LDFLAGS) -o main.exe

clean:
	rm main.o main.exe
