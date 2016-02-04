CC = /usr/bin/g++-4.8
CFLAGS = -I. -I../include -I../interface -Wall
CPPFLAGS = -std=c++0x -I. -I../include -I../interface -Wall -ggdb  -c
LDFLAGS = -lpthread -ggdb -Wall -L../../bin

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

TARGET_1 = regexTrial
REGEX_SRC = regExTrial.cpp
REGEX_OBJ = regExTrial.o

TARGET_2	= tryDlOpen
DL_OPEN_SRC = testdlOpen.cpp
DL_OPEN_OBJ = testdlOpen.o

all: $(TARGET_1) $(TARGET_2)

$(TARGET_2) : $(DL_OPEN_OBJ)
	$(CC)  $(LDFLAGS) $(DL_OPEN_OBJ)  -ldl  -o $(TARGET_2)
	cp ../bin/libtextEcho.so .
	./$(TARGET_2) >> execLog_2
	-rm ./libtextEcho.so

$(TARGET_1) : $(REGEX_OBJ)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(REGEX_OBJ)
	#-./$(TARGET_1) >> execLog_1

.cpp.o :
	echo "$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1 "
	$(CC) -c $(CPPFLAGS) -o $@ $< >> buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	-rm tags

clean:
	-rm buildlog execLog_1 execLog_2
	-rm $(TARGET_1)
	-rm $(TARGET_2)
	-rm ../bin/$(TARGET_1)
	-rm ../bin/$(TARGET_2)
	-rm $(REGEX_OBJ)
	-rm $(DL_OPEN_OBJ)
	-make $(CLEAN_CTAGS)
	-rm -f core
