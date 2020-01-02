# Arquivo para compilar o código forca bruta
#
#################### Makifile ###############

#Compilador a ser usado
COMP=gcc
EXEC=./edo4
FILE=edo4

all: MyProg run

MyProg: edo4.o 
	$(COMP) $(FILE).o  -o $(FILE)

edo4.o: $(FILE).c $(FILE).h  
	$(COMP) -c $(FILE).c -o $(FILE).o

clean:
	rm -rf *.o
run:
	$(EXEC) 1 3 1 5




