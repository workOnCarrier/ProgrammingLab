CC = g++

CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb -D_GLIBCXX_USE_NANOSLEEP
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o: $<
		$(CC) -c $(CPPFLAGS) -o $@ $<  > build.log 2>&1
#		> buildlog 2>&1

SRC = connection.cpp connection_manager.cpp main.cpp mime_types.cpp reply.cpp request_handler.cpp request_parser.cpp server.cpp

OBJ = connection.o connection_manager.o main.o mime_types.o reply.o request_handler.o request_parser.o server.o

TARGET_1 = 1_server

all: $(TARGET_1) 

$(TARGET_1):  $(OBJ)
	$(CC) -o $(TARGET_1)  $(OBJ) $(LDFLAGS) 2>&1  > build.log ;

clean:
	-rm -f $(TARGET_1) $(OBJ)
	-rm -f *.o

