##
## @file Makefile
##
## @author Dennis Addo <ic16b026@technikum-wien.at> (tdxxx)
## @date 2017/07/15
##
## @version 0.1 $
##
## @todo Playing with c++ string and manipulation library
##
## Last Modified: $Author: Dennis $
##

CCXX=g++
CXXFLAGS=-DDEBUG -Wall -pedantic -Werror -Wextra  -g -O3 -std=c++11

OBJECTS=libgrades.o grades.o


##
## ----------------------------------------------------------------- rules --
##


%.o: %.cpp
	$(CCXX) $(CXXFLAGS) -c $<

##
## --------------------------------------------------------------- targets --
##

.PHONY: all
all: grades

grades: $(OBJECTS)
	$(CCXX) $(CXXFLAGS) -o $@ $^
run:
	./grades

.PHONY: clean
clean:
	$(RM) *.o *~ grades