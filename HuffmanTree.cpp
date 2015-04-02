//HuffmanTree.cpp
//Author: Alan Berman
//1/4/2015
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <queue>
#include <vector>
#include <memory>
#include <iostream> //
namespace BRMALA003
{
		
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
	/*bool compare(HuffmanNode &a,HuffmanNode &b)
	{
	if (a.getFrequency()>b.getFrequency())
		{
			return true;
		}
		else
			return false;
	}*/

	using namespace std;
	
	HuffmanTree::HuffmanTree(fptr compare) : q(compare)
	{
		root = NULL;
	}
//	shared_ptr<HuffmanNode> HuffmanTree::createTree(priority_queue<HuffmanNode,vector<HuffmanNode>,fptr> q)
//	{
//		return NULL;
//	}
	priority_queue<HuffmanNode,vector<HuffmanNode>,fptr>& HuffmanTree::getQueue()
	{
		//cout << "q's size (according to getQueue) is " << q.size() << endl;
		return q;
	}
	shared_ptr<HuffmanNode> HuffmanTree::getRoot()
	{
		return this->root;
	}


}
