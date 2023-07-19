#Makefile
all: add-nbo

	gcc -o add-nbo add-nbo.c

clean:
	rm -f adb-nbo
	rm -f *.o