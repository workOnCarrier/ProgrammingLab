
CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  

SRC_1 = observer_1.cpp try_observer_1.cpp numgen.cpp observable_1.cpp
OBJ_1 = observer_1.o try_observer_1.o numgen.o observable_1.o


TARGET_1 = try_observer_1

all: $(TARGET_1)  $(TARGET_2) 

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1)  $(OBJ_1) $(LDFLAGS)


clean:
	-rm -f $(TARGET_1) $(OBJ_1)

