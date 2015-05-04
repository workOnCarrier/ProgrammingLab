CC  = g++

CFLAGS = -I../hdr -Wall
CPPFLAGS = -std=c++0x -I../hdr -Wall -ggdb
LDFLAGS = -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

FIRST_SRC = bst.cpp
FIRST_OBJ = bst.o

TARGET_1 = bst
CLEAN_1 = clean_bst


all : ctags $(TARGET_1) 


$(TARGET_1): $(FIRST_OBJ)
	g++ -o $(TARGET_1) $(LDFLAGS) $(FIRST_OBJ)
#	rm *.o

ctags: $(FIRST_SRC)
	$(CTAGS)

$(CLEAN_1) : 
	rm $(TARGET_1) 

$(CLEAN_CTAGS) :
	rm tags

clean: 
	rm -f core;
	rm $(TARGET_1)
	rm $(FIRST_OBJ)
	make $(CLEAN_CTAGS)
	make $(CLEAN_1)

