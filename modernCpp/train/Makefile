CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $< 

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
 
SRC_10 = test_tricks.cpp
OBJ_10 = test_tricks.o
 
SRC_11 = test_dynamic_cast.cpp
OBJ_11 = test_dynamic_cast.o
 
SRC_12 = try_HR_virtual.cpp
OBJ_12 = try_HR_virtual.o
 
SRC_13 = try_HR_maxSubArray.cpp
OBJ_13 = try_HR_maxSubArray.o
 
SRC_14 = try_HR_101_15_GamingArray.cpp
OBJ_14 = try_HR_101_15_GamingArray.o
 
SRC_15 = try_call_seq.cpp
OBJ_15 = try_call_seq.o
 
SRC_16 = try_enable_shared_from_this.cpp
OBJ_16 = try_enable_shared_from_this.o

SRC_17 = try_HR_treeLevelDisplay.cpp
OBJ_17 = try_HR_treeLevelDisplay.o
 
TARGET_1 = try
TARGET_2 = test_assert
TARGET_3 = test_mixin
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
TARGET_14 = test_HR_GA
TARGET_15 = try_call_seq
TARGET_16 = try_enable_sft
TARGET_17 = try_tree_bf

all:    $(TARGET_17)
#     $(TARGET_15)
# $(TARGET_14)
# $(TARGET_13)
# $(TARGET_12)
#  $(TARGET_11)
#  $(TARGET_10)
# $(TARGET_9)
# $(TARGET_8)
# $(TARGET_7)
# $(TARGET_6)
# $(TARGET_5)
# $(TARGET_4)
# $(TARGET_3)
# $(TARGET_2) 
# $(TARGET_1)

run:
	./$(TARGET_17)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) 

$(TARGET_2):  $(OBJ_2)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(OBJ_2) 
	$(TARGET_2)

$(TARGET_3):  $(OBJ_3)
	$(CC) -o $(TARGET_3) $(LDFLAGS) $(OBJ_3) 

$(TARGET_4):  $(OBJ_4)
	$(CC) -o $(TARGET_4) $(LDFLAGS) $(OBJ_4) 
	./$(TARGET_4)

$(TARGET_5):  $(OBJ_5)
	$(CC) -o $(TARGET_5) $(LDFLAGS) $(OBJ_5) 
	./$(TARGET_5)

$(TARGET_6):  $(OBJ_6)
	$(CC) -o $(TARGET_6) $(LDFLAGS) $(OBJ_6) 
	./$(TARGET_6)

$(TARGET_7):  $(OBJ_7)
	$(CC) -o $(TARGET_7) $(LDFLAGS) $(OBJ_7) 
	./$(TARGET_7)

$(TARGET_8):  $(OBJ_8)
	$(CC) -o $(TARGET_8) $(LDFLAGS) $(OBJ_8) 
	./$(TARGET_8)

$(TARGET_9):  $(OBJ_9)
	$(CC) -o $(TARGET_9) $(LDFLAGS) $(OBJ_9) 
	./$(TARGET_9)

$(TARGET_10):  $(OBJ_10)
	$(CC) -o $(TARGET_10) $(LDFLAGS) $(OBJ_10) 
	./$(TARGET_10)

$(TARGET_11):  $(OBJ_11)
	$(CC) -o $(TARGET_11) $(LDFLAGS) $(OBJ_11)
	./$(TARGET_11)

$(TARGET_12):  $(OBJ_12)
	$(CC) -o $(TARGET_12) $(LDFLAGS) $(OBJ_12)
	./$(TARGET_12)

$(TARGET_13):  $(OBJ_13)
	$(CC) -o $(TARGET_13) $(LDFLAGS) $(OBJ_13)
	./$(TARGET_13)

$(TARGET_14):  $(OBJ_14)
	$(CC) -o $(TARGET_14) $(LDFLAGS) $(OBJ_14)

$(TARGET_15):  $(OBJ_15)
	$(CC) -o $(TARGET_15) $(LDFLAGS) $(OBJ_15)

$(TARGET_16):  $(OBJ_16)
	$(CC) -o $(TARGET_16) $(LDFLAGS) $(OBJ_16)

$(TARGET_17):  $(OBJ_17)
	$(CC) -o $(TARGET_17) $(LDFLAGS) $(OBJ_17)

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
	-rm -f $(TARGET_14) $(OBJ_14)
	-rm -f $(TARGET_15) $(OBJ_15)
	-rm -f $(TARGET_16) $(OBJ_16)
	-rm -f $(TARGET_17) $(OBJ_17)
	-rm -f buildlog


