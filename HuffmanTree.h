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

namespace BRMALA003 {
using namespace std;
//Via the 'Errata' CSC3022H announcement
typedef bool(*fptr)(HuffmanNode &, HuffmanNode&);

//Compare the frequencies of two nodes
/*bool compare(const shared_ptr<HuffmanNode> &a,const shared_ptr<HuffmanNode> &b)
	{
	if (a->getFrequency()<b->getFrequency())
		{
			return true;
		}
		else
			return false;
	}*/

//Adapted from http://www.cprogramming.com/tutorial/lesson18.html
class HuffmanTree
{
	private:
	shared_ptr<HuffmanNode> root;
	
	//Queue of HuffmanNodes using Comparator's compare method
	priority_queue<HuffmanNode,vector<HuffmanNode>,fptr> q; //q(bool compare)
	unordered_map<char,string> codeTable;
	public:
	HuffmanTree(fptr compare); // constructor //:q(compare){}
	HuffmanTree(const HuffmanTree & rhs) = default; //Copy Constructor
	HuffmanTree(HuffmanTree && rhs) = default; //Move Constructor
	//Copy and Move Assignment Operators
	HuffmanTree & operator=(const HuffmanTree & rhs) = default;
	HuffmanTree & operator=(HuffmanTree && rhs) = default;
	~HuffmanTree(void) = default; //Deconstructor
	void setRoot(HuffmanNode h); //Finds the root node [q(compare)]
	priority_queue<HuffmanNode,vector<HuffmanNode>,fptr>& getQueue();
	shared_ptr<HuffmanNode> getRoot();
	unordered_map<char,string>& getCodeTable();
	void createCodeTable(shared_ptr<HuffmanNode> nodeptr, string code);
	//void setQueue(priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode>>,fptr>  q);
};	
	
	
	
	
}
#endif //HUFFMANTREE_H
