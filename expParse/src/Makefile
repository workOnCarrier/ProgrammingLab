
INCLUDE = -I../hdr
RM = rm -f
CXX = g++
CPPFLAGS = -g -Wall $(INCLUDE)

TARGET = expr
SRC = brackEnd.cpp brackStart.cpp div.cpp expFactory.cpp expres.cpp main.cpp minus.cpp multi.cpp num.cpp oper.cpp \
    plus.cpp  token.cpp 

OBJ = brackEnd.o brackStart.o div.o \
    expFactory.o expres.o main.o minus.o \
    multi.o num.o oper.o plus.o token.o 

STATEOBJ = state/context.o state/halfExp.o state/listEndExp.o state/startExp.o 


$(TARGET) : $(OBJ) $(STATEOBJ)
	$(MAKE) -C state
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJ) $(STATEOBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(TARGET)
	$(RM) state/*.o



