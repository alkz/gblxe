CC=g++
INCLUDES=-Iinclude
CFLAGS=-g -std=c++0x -pedantic


all: gblxe

gblxe: GB.o GB_Cpu.o GB_Cart.o GBException.o
	$(CC) GB.o GB_Cart.o GBException.o  -o gblxe

GB.o:        src/GB.cpp  include/GB.hpp
	$(CC)  $(INCLUDES) -c   src/GB.cpp             -o  obj/GB.o

GB_Cpu.o:   src/GB_Cpu.cpp   include/GB_Cpu.hpp
	$(CC)  $(INCLUDES) -c   src/GB_Cpu.cpp    -o  obj/GB_Cpu.o

GB_Cart.o:   src/GB_Cart.cpp  include/GB_Cart.hpp
	$(CC)  $(INCLUDES) -c   src/GB_Cart.cpp        -o  obj/GB_Cart.o

GBException.o:   src/GBException.cpp   include/GBException.hpp
	$(CC)  $(INCLUDES) -c   src/GBException.cpp    -o  obj/GBException.o


clean:
	rm -rf ./obj/*.o 
	rm -f  gblxe
