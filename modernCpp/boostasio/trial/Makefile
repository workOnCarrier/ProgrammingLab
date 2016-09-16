CC = g++-5

CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $< 
#		> buildlog 2>&1

SRC = tryPropertyTree.cpp
OBJ = tryPropertyTree.o

# SRC_1 = 1.cpp
SRC_1 = 2.cpp
OBJ_1 = 2.o

TARGET = xmltry
TARGET_1 = try

all: $(TARGET) $(TARGET_1)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1)


$(TARGET):  $(OBJ)
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJ)

clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f $(TARGET) $(OBJ)
