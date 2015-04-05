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
	//Returns a reference to the code table
	unordered_map<char,string>& HuffmanTree::getCodeTable()
	{
		return codeTable;
	}
	void HuffmanTree::createTree(priority_queue<HuffmanNode,vector<HuffmanNode>,fptr> q)
	{
	//Take out the smallest 2 nodes, and create a node whose left and right children
	//are the nodes just taken out. This creates a tree of nodes, where the last
	//node in the queue is the root of the tree
	cout << "Making a tree of nodes using the priority queue..." <<endl;
	while (q.size()!=1)
	{
		//Remove the smallest node
		HuffmanNode topNode = q.top();
		shared_ptr<HuffmanNode> left_ptr = make_shared<HuffmanNode>(topNode);		
		q.pop();
		//Remove the second-smallest node
		if (q.size()!=0)
		{
			HuffmanNode secondFromTop = q.top();
			shared_ptr<HuffmanNode> right_ptr = make_shared<HuffmanNode>(secondFromTop);
			q.pop();
			//Set the frequency of the parent node equal to the sum of the frequencies
			//of its children
			int sum_of_frequencies = topNode.getFrequency() + secondFromTop.getFrequency();
			HuffmanNode parent = HuffmanNode(sum_of_frequencies);
			//Set the parent's left and right children pointers
			parent.getLeft() = left_ptr;
			parent.getRight() = right_ptr;
			q.push(parent);			
		}	
	}
	cout << "Done!" << endl;
	//Set the root node of the HuffmanTree and create the code table
	HuffmanNode rootNode = q.top();
	setRoot(rootNode);
	}
}
