#include "HuffTreeMaker.h"
#include <iostream>
#include <algorithm>

using namespace std;

void HuffTreeMaker::mapToQue(TextStat & tS)
{
	while (!tS.empty())
	{
		HuffNode *newNode = new HuffNode(tS.pop());
		huffPriQue.push(newNode);
	}
}

void HuffTreeMaker::print() // Csak debugoláshoz!!!!!!!!!!!!!!!
{
	while (!huffPriQue.empty())
	{
		cout <<(char)huffPriQue.top()->getChar() << ": " << huffPriQue.top()->getFreq() << endl;
		huffPriQue.pop();
	}
}

HuffNode* HuffTreeMaker::buildTree()
{
	while (huffPriQue.size() >= 2)
	{
		HuffNode *left = huffPriQue.top();
		huffPriQue.pop();
		HuffNode *right = huffPriQue.top();
		huffPriQue.pop();
		HuffNode *uj = new HuffNode(0, left->getFreq() + right->getFreq(), left, right, max(left->getDeepness(), right->getDeepness()+1));
		huffPriQue.push(uj);
	}
	return huffPriQue.top();

}
