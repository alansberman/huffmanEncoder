//huffencode.cpp
//Author: Alan Berman
//01/04/2015
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <memory>
#include <fstream>
#include "HuffmanTree.cpp"
#include "HuffmanNode.cpp"

//Driver that makes
using namespace std;
int main(int argc, char * argv[]) //
{
	//Read in the txt file to compress and add each char
	//to an unordered_map
	//string inputFile = string(argv[1]); /////////////////uncomment this
	string inputFile = "test.txt";
	BRMALA003::HuffmanTree tree;
	//BRMALA003::HuffmanNode() node;
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
				charfreqmap.insert({c,1});
			}
			else
			{
				//Add 1 to the frequency of the given char
				//Adapted from http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
					unordered_map<char,int>::iterator found = charfreqmap.find(c);
					if (found==charfreqmap.end())
					{
						cerr << "Didn't find char " << c << " in the map" << endl;
					}
					else
					{
						//Add to the frequency
						found->second++;
					}
				
			}	
			
		}
	}
	//For each letter, make a HuffmanNOde and add it to the 
	for (auto it=charfreqmap.begin();it!=charfreqmap.end();++it)
	{
		cout << it->first << " is the letter, " << it->second << " is its frequency" << endl;
		BRMALA003::HuffmanNode node = BRMALA003::HuffmanNode(it->first,it->second);
		shared_ptr<BRMALA003::HuffmanNode> nodeptr = make_shared<BRMALA003::HuffmanNode>(node) ; //(&node)
		tree.getQueue().push(nodeptr);
		cout << tree.getQueue().size() << " is the size " << endl;
		
	}
	
	while (tree.getQueue().size()!=0)
	{
		cout << tree.getQueue().top()->getFrequency() <<  " is the frequency " << endl;
	}
	
	return 0;
}
