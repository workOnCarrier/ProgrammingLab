# /home/genius3/work/github/ProgrammingLab/modernCpp/boostasio/eg2
#
CC = g++
CFLAGS = -I. -I../hdr -Wall
CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb -fpermissive
LDFLAGS = -lpthread -ggdb -Wall -lboost_system

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

SRC1 = t1.cpp
SRC2 = t2.cpp
SRC3 = t3.cpp
SRC4 = t4.cpp
SRC5 = t5.cpp

OBJ1 = t1.o
OBJ2 = t2.o
OBJ3 = t3.o
OBJ4 = t4.o
OBJ5 = t5.o

T1 = T1
T2 = T2
T3 = T3
T4 = T4
T5 = T5

#	$(T1) \
	$(T3) \
	$(T4) \
	$(T5) \
#
all: \
	$(T2) \


$(T1) : $(OBJ1)
	$(CC) -o $(T1) $(LDFLAGS) $(OBJ1)

$(T2) : $(OBJ2)
	$(CC) -o $(T2) $(LDFLAGS) $(OBJ2)

$(T3) : $(OBJ3)
	$(CC) -o $(T3) $(LDFLAGS) $(OBJ3)

$(T4) : $(OBJ4)
	$(CC) -o $(T4) $(LDFLAGS) $(OBJ4)

$(T5) : $(OBJ5)
	$(CC) -o $(T5) $(LDFLAGS) $(OBJ5)

ctags:
	$(CTAGS)

$(CLEAN) : 
	-rm $(T1) 

$(CLEAN_CTAGS) :
	-rm tags
 
clean: 
	-rm -f core;
	-rm $(T1) $(T2)	$(T3) $(T4) $(T5)
	-rm $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)
	-make $(CLEAN_CTAGS)


