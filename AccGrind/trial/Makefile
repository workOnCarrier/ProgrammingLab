CC = /usr/bin/g++-4.8
CFLAGS = -I. -I../include -I../interface -Wall
CPPFLAGS = -std=c++0x -I. -I../include -I../interface -Wall -ggdb  -c
LDFLAGS = -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

TARGET = regexTrial
REGEX_SRC = regExTrial.cpp
REGEX_OBJ = regExTrial.o

all: $(TARGET) 


$(TARGET) : $(REGEX_OBJ)
	$(CC) -o $(TARGET) $(LDFLAGS) $(REGEX_OBJ)
	./$(TARGET) >> buildlog

.cpp.o :
	echo "$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1 "
	$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	-rm tags

clean:
	-rm buildlog 
	-rm $(TARGET)
	-rm ../bin/$(TARGET)
	-rm $(REGEX_OBJ)
	-make $(CLEAN_CTAGS)
	-rm -f core
