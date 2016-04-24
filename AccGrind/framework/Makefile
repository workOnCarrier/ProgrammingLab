
CC = /usr/bin/g++-4.8

CFLAGS = -I. -I../include -I../interface -Wall
CPPFLAGS = -std=c++0x -I. -I../include -I../interface -Wall   -ggdb  -c
## http://www.informit.com/articles/article.aspx?p=22435
LDFLAGS = -L../bin -lpthread -export-dynamic -ggdb -Wall -ldl -lboost_filesystem -lboost_system -lGenUtils

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

AccGrind_SRC = main.cpp HostInputHandler.cpp InputRouter.cpp HostInterpret.cpp PluginLoader.cpp PluginManager.cpp
AccGrind_OBJ = main.o HostInputHandler.o InputRouter.o HostInterpret.o PluginLoader.o PluginManager.o

TARGET = AccGrind

all: $(TARGET) 

$(TARGET) : $(AccGrind_OBJ)
	$(CC)  $(AccGrind_OBJ) $(LDFLAGS) -o $(TARGET)
	cp $(TARGET) ../bin

#.o.cpp:
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
	-rm $(AccGrind_OBJ)
	-make $(CLEAN_CTAGS)
	-rm -f core
