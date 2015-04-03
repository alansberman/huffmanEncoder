//HuffmanTree.cpp
//Author: Alan Berman
//1/4/2015
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <queue>
#include <vector>
#include <string>
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
	void HuffmanTree::setRoot(HuffmanNode h)
	{
		root = make_shared<BRMALA003::HuffmanNode>(h);
	}
	priority_queue<HuffmanNode,vector<HuffmanNode>,fptr>& HuffmanTree::getQueue()
	{
		return q;
	}
	shared_ptr<HuffmanNode> HuffmanTree::getRoot()
	{
		return this->root;
	}
	void HuffmanTree::createCodeTable(shared_ptr<HuffmanNode> nodeptr, string code)
	{
		
		if (nodeptr->getLetter() == 0)
		{
			cout << "The current node doesn't have a letter " << endl;
			HuffmanTree::createCodeTable(nodeptr->getLeft(),(nodeptr->getCode()+"0"));
			if (nodeptr->getLeft()==NULL && nodeptr->getRight() == NULL)
			{
				HuffmanTree::getCodeTable().insert({nodeptr->getLetter(),nodeptr->getCode()});
				cout << HuffmanTree::getCodeTable().size() << " is the code table's size" << endl;
			}
			cout << "Branching right " << endl;
			HuffmanTree::createCodeTable(nodeptr->getRight(),nodeptr->getCode()+"1");
		}
	}
	unordered_map<char,string>& HuffmanTree::getCodeTable()
	{
		return codeTable;
	}
}
