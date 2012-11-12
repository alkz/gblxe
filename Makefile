CC=g++
INCLUDES=-Iinclude
CFLAGS=-g -std=c++0x -pedantic


all: gblxe

gblxe: GB.o Cpu.o Cart.o Exception.o Register.o
	$(CC) GB.o Cart.o Exception.o Register.o -o gblxe

GB.o:      src/GB.cpp    include/GB.hpp
	$(CC)  $(INCLUDES) -c   src/GB.cpp           -o  obj/GB.o

Cpu.o:     src/Cpu.cpp   include/Cpu.hpp
	$(CC)  $(INCLUDES) -c   src/Cpu.cpp          -o  obj/Cpu.o

Cart.o:    src/Cart.cpp  include/Cart.hpp
	$(CC)  $(INCLUDES) -c   src/Cart.cpp         -o  obj/Cart.o

Exception.o:   src/Exception.cpp   include/Exception.hpp
	$(CC)  $(INCLUDES) -c   src/Exception.cpp    -o  obj/Exception.o

Register.o:    src/Register.cpp    include/Register.hpp
	$(CC)  $(INCLUDES) -c   src/Register.cpp     -o  obj/Register.o

clean:
	rm -rf ./obj/*.o 
	rm -f  gblxe

