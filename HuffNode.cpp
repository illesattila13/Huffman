#include "HuffNode.h"



string HuffNode::getCode() const
{
	return code;
}

string & HuffNode::setCode()
{
	return code;
}

void HuffNode::freqInkr()
{
	++freq;
}


int HuffNode::getFreq() const
{
	return freq;
}

int HuffNode::getChar() const
{
	return character;
}


bool HuffNode::operator<(HuffNode & rhs)
{
	return !(*this>rhs);
	
}

bool HuffNode::operator>(HuffNode & rhs) const
{
	//return this->freq > rhs.freq;
	if (this->freq == rhs.freq)
	{
		if (this->deepness > rhs.deepness)
		{
			return true;
		}
		return false;
	}
	else if (this->freq > rhs.freq)
	{
		return true;
	}
	return false;
}

ostream & operator<<(ostream & os, HuffNode & node)
{
	os <<(char) node.getChar() << " " << node.getFreq()<<" "<<node.getCode();
	return os;
}
