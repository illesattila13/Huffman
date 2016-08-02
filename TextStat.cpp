#include "TextStat.h"
#include <iterator>
using namespace std;

void TextStat::textProcess(ifstream & file)
{
	char ch;
	/*file.seekg(0, file.end);
	int size = file.tellg();
	file.seekg(0, file.beg);
	int n = size / 10;
	int i = 0, szazalek = 10;*/
	file >> noskipws;
	while (file  >> ch)
	{
		/*i++;
		if (i == n)
		{
			cout << szazalek <<" %"<< endl;
			szazalek += 10;
			i = 0;
		}*/
		map<int, HuffNode>::iterator it = huffNodeMap.find(ch);
		if (it != huffNodeMap.end())
		{
			it->second.freqInkr();
		}
		else
		{
			HuffNode newNode(ch, 1);
			huffNodeMap.insert(make_pair(ch, newNode));
		}
	}
}

void TextStat::printStat()
{
	for (map<int, HuffNode>::iterator it = huffNodeMap.begin(); it != huffNodeMap.end(); ++it)
	{
		cout << (char)it->first << ": " << it->second.getFreq() << endl;
	}
}

HuffNode TextStat::pop()
{

	//HuffNode tmp(huffNodeMap.begin()->second.getChar, huffNodeMap.begin()->second.getFreq );
	HuffNode tmp(huffNodeMap.begin()->second);
	huffNodeMap.erase(huffNodeMap.begin());
	return tmp;
}

bool TextStat::empty()
{
	return huffNodeMap.empty();
}
