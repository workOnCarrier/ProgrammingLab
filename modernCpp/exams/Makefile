CC = g++-5

CPPFLAGS = -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  > buildlog 2>&1

all:  
	-make -C JT_Codility_20161129

run:
	echo "Not implemented -- run in subdirectories"

clean:
	-make -C JT_Codility_20161129 clean

