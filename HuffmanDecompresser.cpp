#include "HuffmanDecompresser.h"
#include <string>

using namespace std;

HuffmanDecompresser::HuffmanDecompresser(const char * binfilename, const char * outfilename): binput(binfilename, 0), output(outfilename, ios::out)
{

}

void HuffmanDecompresser::readHuffCodes()
{
	char in;
	int ch;
	
	binput.read(&in, 1);
	while (in != 0)
	{
		string code;
		ch = in;
		while (in != 0)
		{
			binput.read(&in, 1);
			if (in == '1')
			{
				code += '1';
			}
			else if(in == '0')
			{
				code += '0';
			}
		}
		huff2Ascii.insert(make_pair(code, ch));
		//code.clear();
		binput.read(&in, 1);
	}
	for (map<string, int>::iterator mit = huff2Ascii.begin(); mit != huff2Ascii.end(); ++mit)
	{
		cout << (char)mit->second << ": " << mit->first   << endl;
	}
}

void HuffmanDecompresser::decompress()
{
	char in;
	map<string, int>::iterator it;
	string code;
	while (binput.getBit(in))
	{
		code += in;
		it = huff2Ascii.find(code);
		if (it != huff2Ascii.end())
		{
			output << (char)it->second;
			code.clear();
		}
	}
}
