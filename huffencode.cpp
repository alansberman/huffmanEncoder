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
#include "CodeTable.cpp"
#include "HuffmanNode.cpp"
#include "FrequencyMap.cpp"

//Driver that makes a HuffmanTree, a character frequency map
//(an unordered_map used to create the priority queue),
//a tree of HuffmanNodes using HuffmanTree, a code table of the
//characters (leaves) in the tree using CodeTable and outputs a 
//buffer string representing the compression as well as a file detailing
//the contents of the code table
using namespace std;
int main(int argc, char * argv[]) 
{
	string inputFile,outputFile;
	//Read in the txt file to compress and add each char
	//to an unordered_map
	if (argv[1] == NULL)
	{
		cout << "Error - input file name not given." << endl;
		return -1;	
	}
	inputFile = string(argv[1]);
	if (argv[2] == NULL)
	{
		cout << "Error - output file name not given." << endl;
		return -1;	
	}
	outputFile = string(argv[2]);
	BRMALA003::HuffmanTree tree = BRMALA003::HuffmanTree(BRMALA003::compare);
	BRMALA003::FrequencyMap charfreqmap = BRMALA003::FrequencyMap();
	ofstream out;
	charfreqmap.createFrequencyTable(inputFile);
	cout << "Making HuffmanNodes using the unordered_map..." << endl;
	cout << "Adding these nodes to the HuffmanTree's priority queue..." <<endl;
	for (auto it=charfreqmap.getFrequencyMap().begin();it!=charfreqmap.getFrequencyMap().end();++it)
	{
		BRMALA003::HuffmanNode node = BRMALA003::HuffmanNode(it->first,it->second);
		tree.getQueue().push(node);
	}
	cout << "Done!" << endl;
	tree.createTree(tree.getQueue());
	cout << "Creating the code table..." <<endl;
	BRMALA003::CodeTable code_table = BRMALA003::CodeTable();
	code_table.createCodeTable(tree.getRoot(),"");
	cout << "Done!" << endl;
	code_table.setBuffer();
	cout << "Buffer string: " << code_table.getBuffer() << endl;
	//Write out to the specified output file the total number of unique characters,
	//each character and its representation
	cout << "Writing the code table out to the output file... (" << outputFile << ")" << endl;
	out.open(outputFile.c_str());
	out << "Total number of unique characters: " << code_table.getCodeTable().size() << endl;
	for (auto iterate=code_table.getCodeTable().begin();iterate!=code_table.getCodeTable().end();++iterate)
	{
		out << "Character: " << iterate->first << " | Representation: "  << iterate->second  << endl;
	}
	out.close();
	cout << "Done!" << endl;
	return 0;
}
