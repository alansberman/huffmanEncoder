//HuffmanTree.h
//Author: Alan Berman
//1/04/2015

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "HuffmanNode.h"
#include <queue>
#include <vector>
#include <memory>
#include <unordered_map>

namespace BRMALA003 {
using namespace std;
//Via the 'Errata' CSC3022H announcement
typedef bool(*fptr)(const shared_ptr<HuffmanNode>&,const shared_ptr<HuffmanNode>&);
//Compare the frequencies of two nodes
bool compare(const shared_ptr<HuffmanNode> &a,const shared_ptr<HuffmanNode> &b)
	{
	if (a->getFrequency()<b->getFrequency())
			return true;
		else
			return false;
	}

//Adapted from http://www.cprogramming.com/tutorial/lesson18.html
class HuffmanTree
{
	private:
	shared_ptr<HuffmanNode> root;
	//Queue of HuffmanNodes using Comparator's compare method
	priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode> >,fptr> q; //q(compare)
	public:
	HuffmanTree(void); // constructor //:q(compare){}
	//HuffmanTree(std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Comparator> q); //constructor
	HuffmanTree(const HuffmanTree & rhs) = default; //Copy Constructor
	HuffmanTree(HuffmanTree && rhs) = default; //Move Constructor
	//Copy and Move Assignment Operators
	HuffmanTree & operator=(const HuffmanTree & rhs) = default;
	HuffmanTree & operator=(HuffmanTree && rhs) = default;
	~HuffmanTree(void) = default; //Deconstructor
	shared_ptr<HuffmanNode> createTree(priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode>>,fptr> q); //Finds the root node [q(compare)]
	priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode>>,fptr> getQueue();
	shared_ptr<HuffmanNode> getRoot();
};	
	
	
	
	
}
#endif //HUFFMANTREE_H
