#pragma once
#include <queue>
#include <functional> 
#include "TextStat.h"

using namespace std;

class HuffTreeMaker
{
	priority_queue<HuffNode*, vector<HuffNode*>, hngreater > huffPriQue;

public:
	HuffTreeMaker() {}

	void mapToQue(TextStat &tS);
	void print();
	HuffNode* buildTree();
};