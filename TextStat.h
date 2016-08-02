#pragma once
#include <map>
#include "HuffNode.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
Makes a statistic for the characters of the text.
The class counts the presence for each character. It operates with a map container http://www.cplusplus.com/reference/map/map/
@author Illes Attila
@date 13.07.16
*/
class TextStat
{
	map<int, HuffNode> huffNodeMap; ///< container for the statistical data
	
public:
	/**
	Ctor. Does nothing
	*/
	TextStat() {};

	/**
	Process a file. It's count each character in the text the presence. /n
	It puts the data in a map
	@param file the file to process
	*/
	void textProcess(ifstream & file);

	/**
	Prints out the statistics. For debug.
	*/
	void printStat();

	/**
	Removes an element from the map and returns it. 
	*/
	HuffNode pop();

	/**
	True if the container is empty. 
	*/
	bool empty();


};