##
## @file Makefile
##
## @author Dennis Addo <ic16b026@technikum-wien.at> (tdxxx)
## @date 2017/07/13
##
## @version 0.1 $
##
## @todo solving Hackerrank questions
##
## Last Modified: $Author: Dennis $
##

CCXX=g++
CXXFLAGS=-DDEBUG -Wall -pedantic -Werror -Wextra -Wshadow  -Weffc++  -g -O3 -std=c++11

OBJECTS=main.o


##
## ----------------------------------------------------------------- rules --
##


%.o: %.cpp
	$(CCXX) $(CXXFLAGS) -c $<

##
## --------------------------------------------------------------- targets --
##

.PHONY: all
all: runmain

runmain: $(OBJECTS)
	$(CCXX) $(CXXFLAGS) -o $@ $^
test:
	./runmain <./sample.txt

.PHONY: clean
clean:
	$(RM) -r *.dSYM runmain* *.o *~ runmain 