CC  = g++

CFLAGS = -I../hdr -DDEBUG -Wall
CPPFLAGS = -std=c++0x -I./ -I../hdr -I/home/nitin/work/framework/include -Wall -ggdb 
LDFLAGS = -lboost_thread-mt -L/home/nitin/work/framework/lib -llog4cpp
LDFLAGS2 = -lboost_thread-mt -L/home/nitin/work/framework/lib -llog4cpp

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

#FIRST_SRC = setupThreads.cpp crewStart.c main.c workRoutine.c
FIRST_SRC = fileDetails_Linux.cpp fileWorkItem_Linux.cpp main.cpp workRoutine.cpp trace.cpp
SECOND_SRC = mylogtest.cpp trace.cpp


FIRST_OBJ = fileDetails_Linux.o fileWorkItem_Linux.o main.o workRoutine.o trace.o
SECOND_OBJ = mylogtest.o trace.o

TARGET_1 = search
CLEAN_1 = clean_search

TARGET_2 = testLog
CLEAN_2 = clean_testlog

#all : $(TARGET_1)  $(TARGET_3)
#all : $(TARGET_1) $(TARGET_2) $(TARGET_3)
#all : $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4)
all : tags $(TARGET_1)  $(TARGET_2)


$(TARGET_1): $(FIRST_OBJ)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(FIRST_OBJ)

$(TARGET_2): $(SECOND_OBJ)
	$(CC) -o $(TARGET_2) $(LDFLAGS2) $(SECOND_OBJ)
#	rm *.o

tags: $(FIRST_SRC)
	$(CTAGS)

$(CLEAN_1) : 
	rm $(TARGET_1) 
	rm $(FIRST_OBJ)
$(CLEAN_2) : 
	rm $(TARGET_2) 
	rm $(SECOND_OBJ)

$(CLEAN_CTAGS) :
	rm tags

clean: 
	rm -f core;
	make $(CLEAN_CTAGS)
	make $(CLEAN_1)
	make $(CLEAN_2)

