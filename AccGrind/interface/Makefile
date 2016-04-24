CC = /usr/bin/g++-4.8

CFLAGS = -I. -Wall
#CPPFLAGS = -std=c++0x -Wall -ggdb -fpic -c
CPPFLAGS = -std=c++0x -Wall -ggdb -c
LDFLAGS = -shared -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

TEST_INTERPRETER_SRC = genUtils.cpp
TEST_INTERPRETER_OBJ = genUtils.o

TARGET = libGenUtils.a

all: $(TARGET) 

$(TARGET) : $(TEST_INTERPRETER_OBJ)
#	$(CC) -o $(TARGET) $(LDFLAGS) $(TEST_INTERPRETER_OBJ)
	ar -q $(TARGET)  $(TEST_INTERPRETER_OBJ)
	ranlib $(TARGET) 
	cp $(TARGET) ../bin

#.o.cpp:
.cpp.o :
	echo "$(CC) $(CPPFLAGS) -o $@ $<" > buildlog 2>&1
	$(CC) $(CPPFLAGS) -o $@ $< >> buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	rm tags
 
clean: 
	-rm -f core
	-rm $(TARGET)
	-rm $(TEST_INTERPRETER_OBJ)
	-make $(CLEAN_CTAGS)
	-rm buildlog
	-rm ../bin/$(TARGET)
