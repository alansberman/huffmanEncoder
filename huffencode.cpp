//huffencode.cpp
//Author: Alan Berman
//01/04/2015
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include <unordered_map>
//Driver that makes
using namespace std;
int main(int argc, char * argv[])
{
	//Read in the txt file to compress and add each char
	//to an unordered_map
	string inputFile = string(argv[1]);
	string line;
	ifstream i(inputFile.c_str());
	unordered_map<char,int> charfreqmap;
	if (!i)
	{
	  cout << "Couldn't open the file to decompres" << endl;
	  return -1;
	}
	//Read in each line of the txt file
	while (!i.eof())
	{
		getline(i,line);
	//	istringstream ss(info);
	//	ss >> width;
	//	ss >> height;
	//	ss >> this->number_images;
	}
	
	return 0;
}
