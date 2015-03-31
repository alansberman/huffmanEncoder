//HuffmanTree.cpp
//Author: Alan Berman
//1/4/2015
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <queue>
#include <vector>
#include <memory>
namespace BRMALA003
{
	using namespace std;
	HuffmanTree::HuffmanTree()
	{
	//this->q=q(compare); 
	q= q(compare);
	}
	shared_ptr<HuffmanNode> HuffmanTree::createTree(priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode>>,fptr> q)
	{
		//for (i=q.begin();i!=q.end();i++)
		//{
		//	
		//}
		return NULL;
	}
	priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode>>,fptr> HuffmanTree::getQueue()
	{
		return this->q;
	}
	shared_ptr<HuffmanNode> HuffmanTree::getRoot()
	{
		return this->root;
	}



}
