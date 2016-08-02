#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Position.h"
using namespace std;

class BinFileHandler
{
	fstream bfile;
	Position<8> p;
	char byte;

public:
	BinFileHandler(const char* filename, bool mode);
	void write(string s);
	ostream& write(const char* c, streamsize n);
	void close();
	~BinFileHandler();
	bool getBit(char &out);
	istream& read(char* s, streamsize n);

};