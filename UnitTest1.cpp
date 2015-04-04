//UnitTest1.cpp
//Author: Alan Berman
//03/04/2015
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <vector>
#include "HuffmanTree.cpp"
#include "HuffmanNode.cpp"
using namespace std;
int main(void)
{
	//Make a HuffmanTree
	BRMALA003::HuffmanTree testTree = BRMALA003::HuffmanTree(BRMALA003::compare);		
	string buffer;
	string output = "output1.dat";
	ofstream out;
	//Make a unordered_map of characters and their frequencies
	//using the input file
	try 
	{
		unordered_map<char,int> testmap;
		string inputFile = "test.txt";
		char c;
		ifstream i(inputFile.c_str());
		cout << "Reading in the file to compress... (" << inputFile << ")" << endl;
		cout << "Creating an unordered_map of the characters and their frequencies..." << endl;
		while (!i.eof())
		{
			string line;
			getline(i,line);
			for (unsigned int i=0;i<line.length();i++)
			{
				c=line.at(i);
				//Insert a new char into the map 
				if (testmap.count(c)==0)
				{				
					testmap.insert({c,1});
				}
				else
				{
					//Add 1 to the frequency of the given char
					//Adapted from http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
					unordered_map<char,int>::iterator found = testmap.find(c);
					if (found==testmap.end())
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
		cout << "Done!" << endl;
		//Make HuffmanNodes using the unordered_map and add them to 
		//the HuffmanTree's priority queue
		cout << "Making HuffmanNodes using the unordered_map..." << endl;
		cout << "Adding these nodes to the HuffmanTree's priority queue..." <<endl;
		try 
		{
			for (auto it=testmap.begin();it!=testmap.end();++it)
			{
				BRMALA003::HuffmanNode node = BRMALA003::HuffmanNode(it->first,it->second);
				testTree.getQueue().push(node);
			}
		
		}
		catch (int e)
		{
			cout << "Error - failed to create HuffmanNodes and add them to the priority queue. " << endl;
		}
	}
	catch (int e)
	{
		cout << "Error - failed to create the unordered_map, add to it and add HuffmanNodes to the priority queue." << endl;
	}
	cout << "Done!" << endl;
	//Until left with 1 node,take out the smallest 2 nodes,
	//create a node whose left and right children are the nodes
	//just taken out to make a tree of HuffmanNodes
	cout << "Making a tree of nodes using the priority queue..." <<endl;
	try 
	{
		while (testTree.getQueue().size()!=1)
		{
			BRMALA003::HuffmanNode topNode = testTree.getQueue().top();
			shared_ptr<BRMALA003::HuffmanNode> left_ptr = make_shared<BRMALA003::HuffmanNode>(topNode);
			testTree.getQueue().pop();		
			if (testTree.getQueue().size()!=0)
			{
				BRMALA003::HuffmanNode secondFromTop = testTree.getQueue().top();
				shared_ptr<BRMALA003::HuffmanNode> right_ptr = make_shared<BRMALA003::HuffmanNode>(secondFromTop);
				testTree.getQueue().pop();
				int sum_of_frequencies = topNode.getFrequency() + secondFromTop.getFrequency();
				BRMALA003::HuffmanNode parent = BRMALA003::HuffmanNode(sum_of_frequencies);
				parent.getLeft() = left_ptr;
				parent.getRight() = right_ptr;
				testTree.getQueue().push(parent);
			}
		}		
	}
	catch (int e)
	{
		cout << "Error - failed to create a tree of HuffmanNodes. " << endl;
	}
	cout << "Done!" << endl;
	//Set the root node of the HuffmanTree and create the code table
	cout << "Creating the code table..." <<endl;
	try 
	{
		
		BRMALA003::HuffmanNode rootNode = testTree.getQueue().top();
		testTree.setRoot(rootNode);
		testTree.createCodeTable(testTree.getRoot(),"");
		for (auto i=testTree.getCodeTable().begin();i!=testTree.getCodeTable().end();++i)
		{
			buffer+=i->second;
		}		
	}
	catch (int e)
	{
		cout << "Error - failed to create the code table " << endl;
	}
	cout << "Done!" << endl;
	//Write out to the specified output file the total number of unique characters,
	//each character and its representation
	cout << "Writing the code table out to the output file... (" << output << ")" << endl;
	try 
	{
		out.open(output.c_str());
		out << "Total number of unique characters: " << testTree.getCodeTable().size() << endl;
		for (auto iterate=testTree.getCodeTable().begin();iterate!=testTree.getCodeTable().end();++iterate)
		{
			out << "Character: " << iterate->first << " | Representation: "  << iterate->second  << endl;	
		}	
	}
	catch (int e)
	{
		cout << "Error - failed to write the output file. " << endl;
	}
	cout << "Done!" << endl;
	return 0;
}
