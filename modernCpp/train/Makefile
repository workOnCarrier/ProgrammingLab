CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
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

SRC_5 = test_hacker_rank_pointer.cpp
OBJ_5 = test_hacker_rank_pointer.o

SRC_6 = try_leftShift.cpp
OBJ_6 = try_leftShift.o

 
TARGET_1 = try
TARGET_2 = test_assert
TARGET_3 = test_mixin
TARGET_4 = test_exam
TARGET_5 = test_hacker_rank_pointer
TARGET_6 = test_shifting

all:  $(TARGET_6)

# $(TARGET_5)
# $(TARGET_4)
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

$(TARGET_5):  $(OBJ_5)
	$(CC) -o $(TARGET_5) $(LDFLAGS) $(OBJ_5) > buildlog 2>&1
	./$(TARGET_5)

$(TARGET_6):  $(OBJ_6)
	$(CC) -o $(TARGET_6) $(LDFLAGS) $(OBJ_6) > buildlog 2>&1
	./$(TARGET_6)


clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f $(TARGET_2) $(OBJ_2)
	-rm -f $(TARGET_3) $(OBJ_3)
	-rm -f $(TARGET_4) $(OBJ_4)
	-rm -f $(TARGET_5) $(OBJ_5)
	-rm -f $(TARGET_6) $(OBJ_6)
	-rm -f buildlog


