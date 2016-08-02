#pragma once
#include "HuffNode.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class HuffTree
{
	HuffNode *root;
public:
	HuffTree() {};
	void setRoot(HuffNode *r)
	{
		root = r;
	}
	HuffNode* getRoot()
	{
		return root;
	}
	~HuffTree();

	void destroy(HuffNode* root);

	void sorban_kiir(HuffNode *gyoker);

	void makeCodes(map<int, string> &codes ,HuffNode* node, string code = "", bool side = false);


};