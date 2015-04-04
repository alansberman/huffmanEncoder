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

//Driver that makes a HuffmanTree, its priority queue,
//an unordered_map used to create the priority queue,
//a tree of HuffmanNodes and a code table of the
//characters (leaves) in the tree
using namespace std;
/*bool compare(BRMALA003::HuffmanNode& a,BRMALA003::HuffmanNode& b)
	{
		if (a.getFrequency()>b.getFrequency())
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/
int main(int argc, char * argv[]) 
{
	string inputFile,outputFile;
	//Read in the txt file to compress and add each char
	//to an unordered_map
	try
	{
		inputFile = string(argv[1]);
	}
	catch (int e)
	{
		cout << "Error - input file name not given." << endl;
	}
	try
	{
		outputFile = string(argv[2]);
	}
	catch (int e)
	{
		cout << "Error - output file name not given." << endl;
	}
	BRMALA003::HuffmanTree tree = BRMALA003::HuffmanTree(BRMALA003::compare);
	string line,buffer;
	char c;
	ifstream i(inputFile.c_str());
	unordered_map<char,int> charfreqmap;
	ofstream out;
	
	if (!i)
	{
	  cout << "Couldn't open the file to decompress" << endl;
	  return -1;
	}
	cout << "Reading in the file to compress... (" << inputFile << ")" << endl;
	cout << "Creating an unordered_map of the characters and their frequencies..." << endl;
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
	cout << "Done!" << endl;
	//For each letter, make a HuffmanNode (and a shared_ptr to it) 
	//and add the latter to the priority_queue 
	cout << "Making HuffmanNodes using the unordered_map..." << endl;
	cout << "Adding these nodes to the HuffmanTree's priority queue..." <<endl;
	for (auto it=charfreqmap.begin();it!=charfreqmap.end();++it)
	{
		BRMALA003::HuffmanNode node = BRMALA003::HuffmanNode(it->first,it->second);
		tree.getQueue().push(node);
	}
	cout << "Done!" << endl;
	//Take out the smallest 2 nodes, and create a node whose left and right children
	//are the nodes just taken out. This creates a tree of nodes, where the last
	//node in the queue is the root of the tree
	cout << "Making a tree of nodes using the priority queue..." <<endl;
	while (tree.getQueue().size()!=1)
	{
		//Remove the smallest node
		BRMALA003::HuffmanNode topNode = tree.getQueue().top();
		shared_ptr<BRMALA003::HuffmanNode> left_ptr = make_shared<BRMALA003::HuffmanNode>(topNode);		
		tree.getQueue().pop();
		//Remove the second-smallest node
		if (tree.getQueue().size()!=0)
		{
			BRMALA003::HuffmanNode secondFromTop = tree.getQueue().top();
			shared_ptr<BRMALA003::HuffmanNode> right_ptr = make_shared<BRMALA003::HuffmanNode>(secondFromTop);
			tree.getQueue().pop();
			//Set the frequency of the parent node equal to the sum of the frequencies
			//of its children
			int sum_of_frequencies = topNode.getFrequency() + secondFromTop.getFrequency();
			BRMALA003::HuffmanNode parent = BRMALA003::HuffmanNode(sum_of_frequencies);
			//Set the parent's left and right children pointers
			parent.getLeft() = left_ptr;
			parent.getRight() = right_ptr;
			tree.getQueue().push(parent);			
		}
		
	}
	cout << "Done!" << endl;
	//Set the root node of the HuffmanTree and create the code table
	cout << "Creating the code table..." <<endl;
	BRMALA003::HuffmanNode rootNode = tree.getQueue().top();
	tree.setRoot(rootNode);
	tree.createCodeTable(tree.getRoot(),"");
	//Set the buffer string
	for (auto i=tree.getCodeTable().begin();i!=tree.getCodeTable().end();++i)
	{
		buffer+=i->second;
	}
	cout << "Done!" << endl;
	//Write out to the specified output file the total number of unique characters,
	//each character and its representation
	cout << "Writing the code table out to the output file... (" << outputFile << ")" << endl;
	out.open(outputFile.c_str());
	out << "Total number of unique characters: " << tree.getCodeTable().size() << endl;
	for (auto iterate=tree.getCodeTable().begin();iterate!=tree.getCodeTable().end();++iterate)
	{
		out << "Character: " << iterate->first << " | Representation: "  << iterate->second  << endl;
		
	}
	cout << "Done!" << endl;
	cout << buffer << " is the buffer string " << endl;
	return 0;
	
}



