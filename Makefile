CC=g++ 
CFLAGS=-c -Wall 
LIBP=-L/usr/X11R6/lib/ -L/usr/lib/ 
INCP=-I/usr/include/GL/ 

all: hw12-main.o hw12-A.o hw12-B.o hw12-C.o hw12-D.o $(CC) hw12-main.o hw12-A.o hw12-B.o hw12-C.o hw12-D.o $(LIBP) $(LIBS) -o hw12  
hw12-main.o: hw12-main.c 
	$(CC) $(CFLAGS) $(INCP) hw12-main.c 
hw12-A.o: hw12-A.c 
	$(CC) $(CFLAGS) $(INCP) hw12-A.c
hw12-B.o: hw12-B.c 
	$(CC) $(CFLAGS) $(INCP) hw12-B.c
hw12-C.o: hw12-C.c 
	$(CC) $(CFLAGS) $(INCP) hw12-C.c
hw12-D.o: hw12-D.c 
	$(CC) $(CFLAGS) $(INCP) hw12-D.c
clean: 
	rm *.o $(objects) hw12

