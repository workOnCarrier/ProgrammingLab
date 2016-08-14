CC = g++-5

CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb -D_GLIBCXX_USE_CXX11_ABI=0
# -I../../../framework/include
LDFLAGS =	-ggdb -lboost_system  \
			-L../../../framewrk/lib/libcurl.a  \
			-L../../../framewrk/lib -lgtest \
			-L../../../framewrk/lib -lgtest_main \
			-L../../../framewrk/lib -lgmock  \
			-L../../../framewrk/lib -lgmock_main \
			-lstdc++ -lpthread 
# LDFLAGS =   -ggdb -lboost_system -lpthread -lcurl -lgtest -lgmock  -lstdc++

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $< 
#		> buildlog 2>&1

SRC = first.cpp
OBJ = first.o

TARGET = 1_first

$(TARGET):  $(OBJ)
	$(CC) -o $(TARGET)  $(OBJ) $(LDFLAGS) > build.log 2>&1

clean:
	-rm -f $(TARGET) $(OBJ)
