CC = g++-5

CPPFLAGS = -std=c++11 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  > buildlog 2>&1

SRC_1 = test_lambda.cpp
OBJ_1 = test_lambda.o

# SRC_1 = 1.cpp
SRC_2 = trying_assert.cpp
OBJ_2 = trying_assert.o

TARGET_1 = try
TARGET_2 = tryAssert

all: $(TARGET_1) $(TARGET_2)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) > buildlog 2>&1

$(TARGET_2):  $(OBJ_2)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(OBJ_2) > buildlog 2>&1

clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f $(TARGET_2) $(OBJ_2)
	-rm -f buildlog


