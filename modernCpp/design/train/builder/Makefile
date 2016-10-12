
CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  > buildlog 2>&1

SRC_1 = 0_noBuilder.cpp
OBJ_1 = 0_noBuilder.o

SRC_2 = htmlBuilder.cpp htmlElement.cpp htmlBuilderDriver.cpp
OBJ_2 = htmlBuilder.o htmlElement.o htmlBuilderDriver.o


TARGET_1 = 0_noBuilderTest
TARGET_2 = 1_builderTest

all: $(TARGET_1)  $(TARGET_2) 

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) > buildlog 2>&1

$(TARGET_2):  $(OBJ_2)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(OBJ_2) > buildlog 2>&1

clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f $(TARGET_2) $(OBJ_2)
	-rm -f buildlog


