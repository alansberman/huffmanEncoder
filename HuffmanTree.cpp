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
	//Comparator Comparator;
	std::shared_ptr<HuffmanNode> HuffmanTree::createTree(std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Comparator> q)
	{
		//for (i=q.begin();i!=q.end();i++)
		//{
		//	
		//}
		return NULL;
	}
	std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Comparator> HuffmanTree::getQueue()
	{
		return this->q;
	}




}
