#include"HuffmanCompresser.h"
#include <iostream>
#include <fstream>
#include "HuffmanDecompresser.h"

using namespace std;

int main(int argc, char* argv[] )
{
	//argv[0] == 1 : compress
	try {
		if (stoi(argv[1]) == 1)
		{
			HuffmanCompresser huffcomp(argv[2], argv[3]);
			huffcomp.makeHuffCodes();
			huffcomp.compress();
		}
		else if (stoi(argv[1]) == 2) ////argv[0] == 1 : decompress
		{
			HuffmanDecompresser decomp(argv[2], argv[3]);
			decomp.readHuffCodes();
			decomp.decompress();
		}
		else
		{
			cout << "Wrong 1. argument. ABORT";

		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}