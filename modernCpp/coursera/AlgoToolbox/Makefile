CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $< 

SRC_1 = .cpp
OBJ_1 = .o


TARGET_1 = maxPairProd

all:    $(TARGET_1)

run:
	./$(TARGET_19)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) 

clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f buildlog


