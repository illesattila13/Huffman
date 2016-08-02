#include "HuffmanCompresser.h"
#include <string>


HuffmanCompresser::HuffmanCompresser(const char * ifilename, const char* ofilename) :binHandler(ofilename, 1), ifile(ifilename, ios::in)
{
}

void HuffmanCompresser::makeHuffCodes()
{
	TextStat t;
	t.textProcess(ifile);
	//	t.printStat();
	HuffTreeMaker htree;
	htree.mapToQue(t);

	HuffTree tr;
	tr.setRoot(htree.buildTree());

	//	tr.sorban_kiir(tr.getRoot());


	tr.makeCodes(huffCodes, tr.getRoot());

	for (map<int, string>::iterator mit = huffCodes.begin(); mit != huffCodes.end(); ++mit)
	{
		cout << (char)mit->first << ": " << mit->second << endl;
	}
}

void HuffmanCompresser::compress()
{
	ifile.clear();
	ifile.seekg(0, ifile.beg);
	
	ifile.seekg(0, ios::end);
	int size;
	size  = ifile.tellg();
	ifile.seekg(0, ios::beg);
	int pos = 0;


	writeCodes();
	
	char c;
	int kiirt = -1;
	while (ifile>>c)
	{
		pos++;
		int szazalek = ((double)pos / size)*100;
	
		if (szazalek != kiirt)
		{
			cout << szazalek << endl;
			kiirt = szazalek;
		}
		
		binHandler.write(huffCodes[c]);
	
	}
	binHandler.close();
	
}

void HuffmanCompresser::writeCodes()
{
	map<int, string>::iterator mit;
	char ch;
	for (mit = huffCodes.begin(); mit != huffCodes.end(); ++mit)
	{
		ch = mit->first;
		binHandler.write(&ch, 1);
		for (int i = 0; i < mit->second.size(); i++)
		{
			ch = mit->second[i];
			binHandler.write(&ch, 1);
		}
		ch = '\0';
		binHandler.write(&ch, 1);
	}
	ch = '\0';
	binHandler.write(&ch, 1);
}


