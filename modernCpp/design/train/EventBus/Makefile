
CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  

SRC_1 = 
OBJ_1 = 


TARGET_1 = try_EventBus

all: $(TARGET_1) 

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1)  $(OBJ_1) $(LDFLAGS)


clean:
	-rm -f $(TARGET_1) $(OBJ_1)

