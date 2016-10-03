CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  > buildlog 2>&1

SRC_1 = SRP.cpp
OBJ_1 = SRP.o

SRC_2 = OCP.cpp
OBJ_2 = OCP.o

SRC_3 = Monad.cpp
OBJ_3 = Monad.o

TARGET_1 = srp
TARGET_2 = ocp
TARGET_3 = monad

all: $(TARGET_1) $(TARGET_2) $(TARGET_3)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) > buildlog 2>&1

$(TARGET_2):  $(OBJ_2)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(OBJ_2) > buildlog 2>&1

$(TARGET_3):  $(OBJ_3)
	$(CC) -o $(TARGET_3) $(LDFLAGS) $(OBJ_3) > buildlog 2>&1

clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f $(TARGET_2) $(OBJ_2)
	-rm -f $(TARGET_3) $(OBJ_3)
	-rm -f buildlog


