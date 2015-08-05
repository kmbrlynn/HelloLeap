# kmbrlynn 2015 08 04
# wtfpl

CFLAGS = -Wall -g -I../include
LEAP_LIBRARY := ../lib/x64/libLeap.so -Wl,-rpath,../lib/x64

all: HelloLeap

HelloLeap: HelloLeap.o helloleap.o
	$(CXX) $(CFLAGS) -o HelloLeap HelloLeap.o helloleap.o $(LEAP_LIBRARY)

HelloLeap.o: HelloLeap.cpp helloleap.cpp helloleap.hpp
	$(CXX) $(CFLAGS) -c HelloLeap.cpp

helloleap.o: helloleap.cpp helloleap.hpp
	$(CXX) $(CFLAGS) -c helloleap.cpp

clean:
	rm -rf HelloLeap *.o *.~
