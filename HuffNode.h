#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
This class handle the characters datas.  
The program works with characters of a text file. For the process we need some information about the characters.
This informations are: frequency (the count of the character in the text), deepness (the level in the binary tree),
code(it's huffman code), and for the binary tree the children.
@author    Illes Attila
@date      13.07.16
*/
class HuffNode
{
private:
	int character;				///< an integer representing an ascii character
	int freq;					///< the count of the character int the text 
	int deepness;				///< the level of the binary tree
	string code;				///< the huffman code of the character
	HuffNode *left, *right;		///< for the binary tree
	
public:
	/**
	Constructor
	@param ch the character
	@param fr the frequency @see TextStat::textProcess()
	@param left pointer to the left child, default: nullptr
	@param right pointer to the right child, default: nullptr
	@param deep the deepnes of the node
	*/
	HuffNode(int ch , int fr , HuffNode* left = nullptr, HuffNode* right= nullptr, int deep = 0 ) :
		character(ch),
		freq(fr),
		left(left),
		right(right),
		deepness(deep)
	{	}
	/**
	Retruns the huffman code of the character
	
	*/
	string getCode() const;

	/**
	Returns a reference to the huffman code of the character
	
	*/
	string& setCode();

	/**

	Inkrement the frequency
	*/
	void freqInkr();

	/**

	Returns the frequency
	*/
	int getFreq() const;

	/**

	returns the character
	*/
	int getChar() const;

	/**

	Returns the deepnes
	*/
	int getDeepness()
	{
		return deepness;
	}

	/**
	HuffNode A is less than HuffNode B when:.
	-the frequency of A is less than B's \n
	-if the frequencys are equal, than A is less when A deepnes is less
	@param rhs the HuffNode to compare with
	*/
	bool operator<(HuffNode& rhs);

	/**
	HuffNode A is greater than HuffNode B when:.
	-the frequency of A is greater than B's \n
	-if the frequencys are equal, than A is greater when A deepnes is greater
	@param rhs the HuffNode to compare with
	*/
	bool operator>(HuffNode& rhs) const;

	/**
	returns a pointer to the left child
	*/
	HuffNode* getLeft()
	{
		return left;
	}

	/**
	returns apointer to the right child
	
	*/
	HuffNode* getRight()
	{
		return right;
	}
	
};

/**
writes out a HuffNode to the os stream.
The output format: <character> <frequency> <huffCode>
@param os the output stream
@param node the HuffNode to output
*/
ostream& operator<<(ostream& os, HuffNode& node);

/**
A predicatum for comaparing two HuffNodes. True if lhs is greater than rhs. /n
It uses the HuffNode::operator>()
*/
struct hngreater
{
	bool operator()(HuffNode* lhs, HuffNode* rhs)
	{
		return *lhs > *rhs;
	}
};
