
CC = g++-5

CPPFLAGS = -std=c++14 -I. -I.. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  

SRC_1 = test_numgen.cpp ../numgen.cpp
OBJ_1 = test_numgen.o numgen.o

TARGET_1 = test_numgen

all: $(TARGET_1)  

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) 

numgen.o : ../numgen.cpp
		$(CC) -c $(CPPFLAGS) -o numgen.o ../numgen.cpp  


clean:
	-rm -f $(TARGET_1) $(OBJ_1)

