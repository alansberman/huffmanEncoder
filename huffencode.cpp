//huffencode.cpp
//Author: Alan Berman
//01/04/2015
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <vector>
#include "HuffmanTree.cpp"
#include "HuffmanNode.cpp"

//Driver that makes
using namespace std;
/*namespace BRMALA003{
	
bool compare(HuffmanNode &a, HuffmanNode &b)
	{
	if (a.getFrequency()>b.getFrequency())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}*/
int main(int argc, char * argv[]) //
{
	//Read in the txt file to compress and add each char
	//to an unordered_map
	//string inputFile = string(argv[1]); /////////////////uncomment this
	string inputFile = "test.txt";
	vector<BRMALA003::HuffmanNode> nodevector;

	BRMALA003::HuffmanTree tree = BRMALA003::HuffmanTree(BRMALA003::compare);
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
	//For each letter, make a HuffmanNode (and a shared_ptr to it) 
	//and add the latter to the priority_queue 
	for (auto it=charfreqmap.begin();it!=charfreqmap.end();++it)
	{
		cout << it->first << " is the letter, " << it->second << " is its frequency" << endl;
		BRMALA003::HuffmanNode node = BRMALA003::HuffmanNode(it->first,it->second);
		tree.getQueue().push(node);
		cout << tree.getQueue().size() << " is the size of the priority_queue" << endl;
	}
	while (tree.getQueue().size()!=1)
	{
		BRMALA003::HuffmanNode topNode = tree.getQueue().top();
		cout << topNode.getFrequency() << " is the frequency of the top node" << endl;
		shared_ptr<BRMALA003::HuffmanNode> left_ptr = make_shared<BRMALA003::HuffmanNode>(topNode);
		tree.getQueue().pop();
		
		if (tree.getQueue().size()!=0)
		{
			BRMALA003::HuffmanNode secondFromTop = tree.getQueue().top();
			cout << secondFromTop.getFrequency() << " is the frequency of the second-from-the-top node" << endl;
			shared_ptr<BRMALA003::HuffmanNode> right_ptr = make_shared<BRMALA003::HuffmanNode>(secondFromTop);
			tree.getQueue().pop();
			int sum_of_frequencies = topNode.getFrequency() + secondFromTop.getFrequency();
			BRMALA003::HuffmanNode parent = BRMALA003::HuffmanNode(sum_of_frequencies);//Fix!!! Can't be '0'
			parent.getLeft() = left_ptr;
			parent.getRight() = right_ptr;
			cout << parent.getFrequency() << " is the frequency of the parent node" << endl;
			tree.getQueue().push(parent);
			
		}
		
	}
	BRMALA003::HuffmanNode rootNode = tree.getQueue().top();
	cout << rootNode.getFrequency() << " is the frequency of the root node" << endl;
	return 0;
}


