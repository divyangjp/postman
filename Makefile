########################################################
# command		output
# -------   	-----------------------------------
# make			Makes executable without debug info
# make debug	Makes executable with debug info
# make clean	Cleans executable, object files and core
#######################################################

#------------------------------------------------------------------------------

SOURCEDIR=.

SOURCE=\
	$(SOURCEDIR)/testmain.cpp\
	$(SOURCEDIR)/Utils.cpp\
	$(SOURCEDIR)/Common.cpp\
	$(SOURCEDIR)/CurlWrap.cpp

OBJECTS=\
	testmain.o\
	Utils.o\
	Common.o\
	CurlWrap.o

MYPROGRAM=postman.out
MYINCLUDES=\
	-I./

MYLIBRARIES= -lboost_regex -lhtmlcxx -lcurl

CFLAGS= -Wall -pthread -std=c++11
CDEBUGFLAGS= -g -DDEBUG

CC=g++

#------------------------------------------------------------------------------


all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) $(CFLAGS) $(MYINCLUDES) $(SOURCE) $(MYLIBRARIES) -o $(MYPROGRAM)

debug: $(SOURCE)
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) $(MYINCLUDES) $(SOURCE) $(MYLIBRARIES) -o $(MYPROGRAM)


.cpp.o:
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) $(MYINCLUDES) $(MYLIBRARIES) -c $<

clean:
	rm -f $(MYPROGRAM) *.o core a.out.stackdump
