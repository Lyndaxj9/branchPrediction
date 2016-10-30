#Makefile
CC = g++

CFLAGS = -std=c++11 

RM = rm -f

TARGET = a

all: $(TARGET) 

$(TARGET): main.o always.o bimodalOne.o bimodalTwo.o gshare.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o always.o bimodalOne.o bimodalTwo.o gshare.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

always.o: always.cpp
	$(CC) $(CFLAGS) -c always.cpp

bimodalOne.o: bimodalOne.cpp
	$(CC) $(CFLAGS) -c bimodalOne.cpp

bimodalTwo.o: bimodalTwo.cpp
	$(CC) $(CFLAGS) -c bimodalTwo.cpp

gshare.o: gshare.cpp
	$(CC) $(CFLAGS) -c gshare.cpp
	
clean:
	$(RM) $(TARGET) *.o
