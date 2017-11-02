# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g -Wall
LDFLAGS=-g

all: test util.o

test: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

benchdict: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o benchdict.o

benchhash: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o benchhash.o

DictionaryTrie.o: DictionaryTrie.h

DictionaryBST.o: DictionaryBST.h

DictionaryHashtable.o: DictionaryHashtable.h

util.o: util.h

benchdict.o: benchdict.cpp

benchhash.o: benchhash.cpp

clean:
	rm -f test *.o core* *~

