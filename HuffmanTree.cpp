//HuffmanTree.cpp
//Author: Alan Berman
//1/4/2015
#include "HuffmanTree.h"
#include <queue>
#include <vector>
#include <string>
#include <memory>
#include <iostream> 

namespace BRMALA003
{
	using namespace std;
	//Compares the frequencies of two HuffmanNodes
	//such that the node with the smallest frequency
	//is at the head of the queue
	bool compare(const HuffmanNode &a,const HuffmanNode &b)
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
	//Constructor
	//Sets the priority queue to include the compare method
	HuffmanTree::HuffmanTree(fptr compare) : q(compare)
	{
		root = NULL;
	}
	//Sets the root HuffmanNode
	void HuffmanTree::setRoot(HuffmanNode h)
	{
		root = make_shared<BRMALA003::HuffmanNode>(h);
	}
	//Returns a reference to the priority queue
	priority_queue<HuffmanNode,vector<HuffmanNode>,fptr>& HuffmanTree::getQueue()
	{
		return q;
	}
	//Gets the root HuffmanNode
	shared_ptr<HuffmanNode> HuffmanTree::getRoot()
	{
		return root;
	}
	//Recursive method that creates the code table,
	//using inorder traversal of the HuffmanTree
	void HuffmanTree::createCodeTable(shared_ptr<HuffmanNode> nodeptr, string code)
	{
		//If the pointer to the node is not null
		if (nodeptr)
		{
			//Do the node's left child
			HuffmanTree::createCodeTable(nodeptr->getLeft(),code+"0");
			//If the node is a leaf (i.e. has a character),
			//insert it into the code table
			if (nodeptr->getLeft()==NULL && nodeptr->getRight() == NULL)
			{
				HuffmanTree::getCodeTable().insert({nodeptr->getLetter(),code});
				
			}
			//Do the node's right child
			HuffmanTree::createCodeTable(nodeptr->getRight(),code+"1");
		}
	}
	//Returns a reference to the code table
	unordered_map<char,string>& HuffmanTree::getCodeTable()
	{
		return codeTable;
	}
}
