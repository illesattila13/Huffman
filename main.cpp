#include"HuffmanCompresser.h"
#include <iostream>
#include <fstream>
#include "HuffmanDecompresser.h"

using namespace std;

int main(int argc, char* argv[])
{
	HuffmanCompresser huffcomp("bible.txt", "bible.bin");
	huffcomp.makeHuffCodes();
	huffcomp.compress();
		
	HuffmanDecompresser decomp("bible.bin", "bible2.txt");
	decomp.readHuffCodes();
	decomp.decompress();
}