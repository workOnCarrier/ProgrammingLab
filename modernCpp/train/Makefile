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

SRC_3 = trying_mixin.cpp
OBJ_3 = trying_mixin.o

SRC_4 = test_exam.cpp
OBJ_4 = test_exam.o

TARGET_1 = try
TARGET_2 = test_assert
TARGET_3 = test_mixin
TARGET_4 = test_exam

all: $(TARGET_4)

	#$(TARGET_1) $(TARGET_2) 
	#$(TARGET_3)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) > buildlog 2>&1

$(TARGET_2):  $(OBJ_2)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(OBJ_2) > buildlog 2>&1

$(TARGET_3):  $(OBJ_3)
	$(CC) -o $(TARGET_3) $(LDFLAGS) $(OBJ_3) > buildlog 2>&1

$(TARGET_4):  $(OBJ_4)
	$(CC) -o $(TARGET_4) $(LDFLAGS) $(OBJ_4) > buildlog 2>&1
	./$(TARGET_4)

clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f $(TARGET_2) $(OBJ_2)
	-rm -f $(TARGET_3) $(OBJ_3)
	-rm -f $(TARGET_4) $(OBJ_4)
	-rm -f buildlog


