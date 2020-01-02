# Arquivo para compilar o código forca bruta
#
#################### Makifile ###############

#Compilador a ser usado
COMP=gcc
EXEC=./edo2
FILE=edo2

all: MyProg run

MyProg: edo2.o 
	$(COMP) -lm $(FILE).o -o $(FILE)

edo2.o: $(FILE).c $(FILE).h  
	$(COMP) -c $(FILE).c -o $(FILE).o

clean:
	rm -rf *.o
run:
	$(EXEC) 0 100 0 100 1.0 9.8 10.0




