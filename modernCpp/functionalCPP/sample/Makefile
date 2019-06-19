CC = g++

CPPFLAGS = -std=c++11 -I. -I../hdr -Wall -ggdb
# LDFLAGS =   -ggdb -lboost_system -lpthread
LDFLAGS =   -ggdb -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $< 

SRC_1 = CustomerBunch.cpp \
		main.cpp
OBJ_1 = CustomerBunch.o \
		main.o

TARGET_1 = testCust

all: $(TARGET_1)

run:
	./$(TARGET_1)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) 


clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f buildlog
