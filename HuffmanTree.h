//HuffmanTree.h
//Author: Alan Berman
//1/04/2015

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "HuffmanNode.h"
#include <queue>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>
//HuffmanTree header file
namespace BRMALA003 {
using namespace std;
//Via the 'Errata' CSC3022H announcement
typedef bool(*fptr)(const HuffmanNode &,const HuffmanNode&);

//Class that makes a HuffmanTree, containing a root node (which
//points to a tree of HuffmanNodes, as well as a priority queue
//of nodes used to construct the tree and a codeTable which stores
//each character (leaf nodes) and its representation
class HuffmanTree
{
	private:
	shared_ptr<HuffmanNode> root;
	//Queue of HuffmanNodes using Comparator's compare method
	priority_queue<HuffmanNode,vector<HuffmanNode>,fptr> q; //q(bool compare)
	unordered_map<char,string> codeTable;
	public:
	HuffmanTree(fptr compare); // Constructor
	~HuffmanTree(void) = default; //Deconstructor
	void setRoot(HuffmanNode h); //Finds the root node 
	priority_queue<HuffmanNode,vector<HuffmanNode>,fptr>& getQueue();
	shared_ptr<HuffmanNode> getRoot();
	unordered_map<char,string>& getCodeTable();
	void createCodeTable(shared_ptr<HuffmanNode> nodeptr, string code);

};	
	
	
	
	
}
#endif //HUFFMANTREE_H
