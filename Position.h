#pragma once

template<int N>
class Position
{
	unsigned int posi;

public:

	Position(): posi(0)
	{

	}
	Position& operator++()
	{
		posi++;
		if (posi >= N) posi = 0;
		return *this;
	}
	Position operator++(int)
	{
		Position tmp = *this;
		++posi;
		if (posi >= N) posi = 0;
		return tmp;
	}
	unsigned int pos()
	{
		return posi;
	}
};


