CC = g++

CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb \
	-I ../../../framewrk/usr/local/include 
# -I../../../framework/include
LDFLAGS =	-ggdb -lboost_system  \
			-L../../../framewrk/usr/local/lib \
			-lgtest \
			-lgtest_main \
			-lgmock  \
			-lgmock_main \
			-lstdc++ -lpthread 
# LDFLAGS =   -ggdb -lboost_system -lpthread -lcurl -lgtest -lgmock  -lstdc++

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $< 
#		> buildlog 2>&1

SRC = first.cpp
OBJ = first.o

TARGET_1 = 1_first

$(TARGET_1):  $(OBJ)
	$(CC) -o $(TARGET_1)  $(OBJ) $(LDFLAGS) > build.log 2>&1

clean:
	-rm -f $(TARGET_1) $(OBJ)
	-rm -f build.log
