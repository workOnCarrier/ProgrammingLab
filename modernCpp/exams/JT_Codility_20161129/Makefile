CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  > buildlog 2>&1

SRC_1 = HelloWorld.cpp
OBJ_1 = HelloWorld.o

SRC_2 = question1.cpp
OBJ_2 = question1.o

SRC_3 = .cpp
OBJ_3 = .o

SRC_4 = .cpp
OBJ_4 = .o

SRC_5 = .cpp
OBJ_5 = .o

SRC_6 = .cpp
OBJ_6 = .o

SRC_7 = .cpp
OBJ_7 = .o
 
SRC_8 = .cpp
OBJ_8 = .o
 
SRC_9 = .cpp
OBJ_9 = .o
 
SRC_10 = .cpp
OBJ_10 = .o
 
SRC_11 = .cpp
OBJ_11 = .o
 
SRC_12 = .cpp
OBJ_12 = .o
 
SRC_13 = .cpp
OBJ_13 = .o
 
TARGET_1 = try_helloworld
TARGET_2 = try_q1
TARGET_3 = try_q2
TARGET_4 = test_exam
TARGET_5 = test_hacker_rank_pointer
TARGET_6 = test_shifting
TARGET_7 = test_HR_CD2
TARGET_8 = test_HR_CD3
TARGET_9 = test_HR_RJ
TARGET_10 = test_tricks
TARGET_11 = test_dc
TARGET_12 = test_HR_virt
TARGET_13 = test_HR_maxSubArray

all:   $(TARGET_2) 
# $(TARGET_1)  -- only used to get makefile work
# $(TARGET_3)
#	$(TARGET_13)
# $(TARGET_12)
#  $(TARGET_11)
#  $(TARGET_10)
# $(TARGET_9)
# $(TARGET_8)
# $(TARGET_7)
# $(TARGET_6)
# $(TARGET_5)
# $(TARGET_4)

run:
	./$(TARGET_1)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) > buildlog 2>&1

$(TARGET_2):  $(OBJ_2)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(OBJ_2) > buildlog 2>&1
	./$(TARGET_2)

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

$(TARGET_10):  $(OBJ_10)
	$(CC) -o $(TARGET_10) $(LDFLAGS) $(OBJ_10) > buildlog 2>&1
	./$(TARGET_10)

$(TARGET_11):  $(OBJ_11)
	$(CC) -o $(TARGET_11) $(LDFLAGS) $(OBJ_11) > buildlog 2>&1
	./$(TARGET_11)

$(TARGET_12):  $(OBJ_12)
	$(CC) -o $(TARGET_12) $(LDFLAGS) $(OBJ_12) > buildlog 2>&1
	./$(TARGET_12)

$(TARGET_13):  $(OBJ_13)
	$(CC) -o $(TARGET_13) $(LDFLAGS) $(OBJ_13) > buildlog 2>&1
	./$(TARGET_13)

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
	-rm -f $(TARGET_10) $(OBJ_10)
	-rm -f $(TARGET_11) $(OBJ_11)
	-rm -f $(TARGET_12) $(OBJ_12)
	-rm -f $(TARGET_13) $(OBJ_13)
	-rm -f buildlog


