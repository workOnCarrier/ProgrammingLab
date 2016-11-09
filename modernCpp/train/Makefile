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

SRC_7 = try_HR_codeD2.cpp
OBJ_7 = try_HR_codeD2.o
 
SRC_8 = try_HR_code25_D3.cpp
OBJ_8 = try_HR_code25_D3.o
 
SRC_9 = try_HR_RadleyJames.cpp
OBJ_9 = try_HR_RadleyJames.o
 
TARGET_1 = try
TARGET_2 = test_assert
TARGET_3 = test_mixin
TARGET_4 = test_exam
TARGET_5 = test_hacker_rank_pointer
TARGET_6 = test_shifting
TARGET_7 = test_HR_CD2
TARGET_8 = test_HR_CD3
TARGET_9 = test_HR_RJ

all:  $(TARGET_9)
# $(TARGET_8)
# $(TARGET_7)
# $(TARGET_6)
# $(TARGET_5)
# $(TARGET_4)
# $(TARGET_3)
# $(TARGET_2) 
# $(TARGET_1)

run:
	./$(TARGET_9)

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

$(TARGET_7):  $(OBJ_7)
	$(CC) -o $(TARGET_7) $(LDFLAGS) $(OBJ_7) > buildlog 2>&1
	./$(TARGET_7)

$(TARGET_8):  $(OBJ_8)
	$(CC) -o $(TARGET_8) $(LDFLAGS) $(OBJ_8) > buildlog 2>&1
	./$(TARGET_8)

$(TARGET_9):  $(OBJ_9)
	$(CC) -o $(TARGET_9) $(LDFLAGS) $(OBJ_9) > buildlog 2>&1
	./$(TARGET_9)

clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f $(TARGET_2) $(OBJ_2)
	-rm -f $(TARGET_3) $(OBJ_3)
	-rm -f $(TARGET_4) $(OBJ_4)
	-rm -f $(TARGET_5) $(OBJ_5)
	-rm -f $(TARGET_6) $(OBJ_6)
	-rm -f $(TARGET_7) $(OBJ_7)
	-rm -f $(TARGET_8) $(OBJ_8)
	-rm -f $(TARGET_9) $(OBJ_9)
	-rm -f buildlog


