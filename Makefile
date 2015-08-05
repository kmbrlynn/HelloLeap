# kmbrlynn 2015 08 04
# wtfpl

CFLAGS = -Wall -g -I../include
LEAP_LIBRARY := ../lib/x64/libLeap.so -Wl,-rpath,../lib/x64

all: HelloLeap

HelloLeap.o: helloleap.cpp helloleap.hpp
	$(CXX) $(CFLAGS) -c HelloLeap.cpp

HelloLeap: HelloLeap.o
	$(CXX) $(CFLAGS) HelloLeap.cpp -o HelloLeap $(LEAP_LIBRARY)

clean:
	rm -rf HelloLeap *.o *.~
