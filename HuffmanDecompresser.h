#pragma once
#include <fstream>
#include <iostream>
#include "BinFileHandler.h"
#include <map>

using namespace std;

class HuffmanDecompresser
{
	ofstream output;
	BinFileHandler binput;
	map<string, int> huff2Ascii;
public:
	HuffmanDecompresser(const char* binfilename, const char* outfilename);
	void readHuffCodes();
	void decompress();
};
