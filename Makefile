EXE = MAE_exe
CC = g++
FLAG = -I /usr/include/python2.7 -lpython2.7 -g -Wall -Wextra
SROC = ./lib/include/python_script.cpp
all:$(EXE) 
$(EXE): main.o
	$(CC) $^ -o $(EXE) -lpython2.7

main.o:$(SROC) 
	$(CC) -c $< -o $@ $(FLAG)

clean:
	rm *.o $(EXE)
