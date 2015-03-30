//huffencode.cpp
//Author: Alan Berman
//01/04/2015
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <fstream>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

//Driver that makes
using namespace std;
int main(int argc, char * argv[])
{
	//Read in the txt file to compress and add each char
	//to an unordered_map
	string inputFile = string(argv[1]);
	BRMALA003::HuffmanTree tree;
	//BRMALA003::HuffmanNode node;
	string line;
	char c;
	ifstream i(inputFile.c_str());
	unordered_map<char,int> charfreqmap;
	if (!i)
	{
	  cout << "Couldn't open the file to decompress" << endl;
	  return -1;
	}
	//Read in each line of the txt file
	while (!i.eof())
	{
		getline(i,line);
		for (unsigned int i=0;i<line.length();i++)
		{
			c=line.at(i);
			//Insert a new char into the map 
			if (charfreqmap.count(c)==0)
			{
				BRMALA003::HuffmanNode node
				charfreqmap.insert({c,1});
			}
			else
			{
				//Add 1 to the frequency of the given char
				//Adapted from http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
					unordered_map<char,int>::iterator found = charfreqmap.find(c);
					if (found==charfreqmap.end())
					{
						cout << "Didn't find char " << c << " in the map" << endl;
					}
					else
					{
						//Add to the frequency
						found->second++;
					}
				
			}	
			
		}
	}
	
	return 0;
}
