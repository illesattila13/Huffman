#pragma once
#include "TextStat.h"
#include "HuffTreeMaker.h"
#include <string>
#include <fstream>
#include "HuffTree.h"
#include <iostream>
#include <map>
#include "BinFileHandler.h"

using namespace std;

class HuffmanCompresser
{
	 ifstream ifile;
	 BinFileHandler binHandler;
	 map<int, string> huffCodes;


public:
	HuffmanCompresser(const char* ifilename, const char* ofilename);
	void makeHuffCodes();
	void compress();
	void writeCodes();
};