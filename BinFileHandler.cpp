#include "BinFileHandler.h"
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Position.h"

using namespace std;

BinFileHandler::BinFileHandler(const char * filename, bool mode) : p(), byte(0)
{
	if (mode)
	{
		bfile.open(filename, ofstream::out | ofstream::binary);
	}
	else
	{
		bfile.open(filename, ofstream::in | ofstream::binary);
	}
}



void BinFileHandler::write(string s)
{
	char masks[8] = {
		0b10000000,
		0b01000000,
		0b00100000,
		0b00010000,
		0b00001000,
		0b00000100,
		0b00000010,
		0b00000001
	};
	int oldpos = p.pos();
	for (int k = 0; k < s.size();k += (8 - oldpos))
	{
		if (k > 0) oldpos = 0;
		for (int i = 0; i < min<int>((8 - oldpos), (s.size()) - k); i++)
		{
			if (s[i + k] == '0')
			{
				char m = masks[p.pos()]; ++p;
				m = ~m;
				byte &= m;
			}
			if (s[i + k] == '1')
			{
				char m = masks[p.pos()]; ++p;
				byte |= m;
			}
		}
		if (p.pos() == 0)
		{
			bfile.write(&byte, 1);
			byte = 0;
		}
	}

}

ostream& BinFileHandler::write(const char * c, streamsize n)
{
	return bfile.write(c, n);
}

void BinFileHandler::close()
{
	if (p.pos() != 0)
	{
		bfile.write(&byte, 1);
	}
	bfile.close();
}

BinFileHandler::~BinFileHandler()
{
	close();
}

bool BinFileHandler::getBit(char &out)
{
	char masks[8] = {
		0b10000000,
		0b01000000,
		0b00100000,
		0b00010000,
		0b00001000,
		0b00000100,
		0b00000010,
		0b00000001
	};

	if (p.pos() == 0)
	{
		if (!(bfile.read(&byte, 1)))
		{
			return false;
		}
	}

	char test = byte & masks[p.pos()]; ++p;

	if (test)
	{
		out = '1';
	}
	else
	{
		out = '0';
	}

	return true;
}

istream & BinFileHandler::read(char * s, streamsize n)
{
	return bfile.read(s, n);
}


