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
#include "CodeTable.cpp"
#include "HuffmanNode.cpp"
#include "FrequencyMap.cpp"
//Unit test using "test.txt"
//Contents of "test.txt":
//a
//bb
//ccc
//dddd
using namespace std;
int main(void)
{
	BRMALA003::HuffmanTree testTree = BRMALA003::HuffmanTree(BRMALA003::compare);	
	BRMALA003::CodeTable testTable = BRMALA003::CodeTable();	
	BRMALA003::FrequencyMap testFrequencyMap = BRMALA003::FrequencyMap();
	string buffer;
	string output = "output1.dat";
	ofstream out;
	//Make a unordered_map of characters and their frequencies
	//using the input file
	try 
	{
		string inputFile = "test.txt";
		testFrequencyMap.createFrequencyTable(inputFile);
		//Make HuffmanNodes using the unordered_map and add them to 
		//the HuffmanTree's priority queue
		cout << "Making HuffmanNodes using the unordered_map..." << endl;
		cout << "Adding these nodes to the HuffmanTree's priority queue..." <<endl;
		try 
		{
			cout << "------HuffmanNodes added to the Frequency Map------" << endl;
			for (auto it=testFrequencyMap.getFrequencyMap().begin();it!=testFrequencyMap.getFrequencyMap().end();++it)
			{
				cout << it->first << " [character] | " << it->second << " [its frequency] " << endl;
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
	//Set the root node of the HuffmanTree
	try 
	{
		testTree.createTree(testTree.getQueue());
	}
	catch (int e)
	{
		cout << "Error - failed to create a tree of HuffmanNodes. " << endl;
	}
	cout << "Creating the code table..." <<endl;
	try 
	{
		
		testTable.createCodeTable(testTree.getRoot(),"");	
	}
	catch (int e)
	{
		cout << "Error - failed to create the code table " << endl;
	}
	cout << "Done!" << endl;
	//Write out to the specified output file the total number of unique characters,
	//each character and its representation
	testTable.setBuffer();
	cout << "Buffer string: " << testTable.getBuffer() << endl;
	cout << "Writing the code table out to the output file... (" << output << ")" << endl;
	try 
	{
		out.open(output.c_str());
		out << "Total number of unique characters: " << testTable.getCodeTable().size() << endl;
		for (auto iterate=testTable.getCodeTable().begin();iterate!=testTable.getCodeTable().end();++iterate)
		{
			out << "Character: " << iterate->first << " | Representation: "  << iterate->second  << endl;	
		}	
		out.close();
	}
	catch (int e)
	{
		cout << "Error - failed to write the output file. " << endl;
	}
	/*try 
	{
		//Adapted from http://www.cplusplus.com/reference/string/string/c_str/
		char * c_buffer = new char [testTable.getBuffer().length()+1];
		//strcpy(c_buffer,code_table.getBuffer().c_str());	
		out2.open(output2.c_str(), ios::out | ios::binary);
		out2.write(c_buffer,testTable.getBuffer().c_str());
	}
	catch (int e)
	{
		cout << "Error - failed to write binary hdr file"
	}	*/
	cout << "Done!" << endl;
	return 0;
}

