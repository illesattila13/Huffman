#include "HuffTree.h"



void HuffTree::destroy(HuffNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	destroy(root->getLeft());
	destroy(root->getRight());
	delete root;
}

void HuffTree::sorban_kiir(HuffNode * gyoker)
{
	if (gyoker == NULL)   /* leállási feltétel */
		return;

	sorban_kiir(gyoker->getLeft());     /* 1 */
	cout << *gyoker << endl;
	sorban_kiir(gyoker->getRight());    /* 3 */
}

void HuffTree::makeCodes(map<int, string> &codes, HuffNode * node, string code, bool side)
{
	if (node == nullptr)
	{
		return;
	}
	string tmpCode = code;
	if (side == false)
	{
		tmpCode += "0";
		node->setCode().resize(tmpCode.size() - 1);
		copy(tmpCode.begin() + 1, tmpCode.end(), node->setCode().begin());
	}
	else
	{
		tmpCode += "1";
		node->setCode().resize(tmpCode.size() - 1);
		copy(tmpCode.begin() + 1, tmpCode.end(), node->setCode().begin());
	}
	if (node->getLeft() == nullptr && node->getRight() == nullptr)
	{
		if (node->getCode() == "")
		{
			node->setCode() += "0";
		}
		codes.insert(make_pair(node->getChar(), node->getCode()));
	}
	makeCodes(codes, node->getLeft(), tmpCode, false);
	makeCodes(codes, node->getRight(), tmpCode, true);
}

HuffTree::~HuffTree()
{
	destroy(root);
}