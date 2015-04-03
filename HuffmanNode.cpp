//HuffmanNode.cpp
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
	//Constructor
	HuffmanNode::HuffmanNode(char l, int f)
	{
		letter = l;
		frequency = f;
		left=NULL;
		right=NULL;
		code = "";
	} 
	HuffmanNode::HuffmanNode(int f)
	{
		letter = 0;
		frequency = f;
		left=NULL;
		right=NULL;
	}
	int HuffmanNode::getFrequency()
	{
		return this->frequency;
	}
	shared_ptr<HuffmanNode>& HuffmanNode::getLeft()
	{
		return left;
	}
	shared_ptr<HuffmanNode>& HuffmanNode::getRight()
	{
		return right;
	}
	string HuffmanNode::getCode()
	{
		return code;
	}
	char HuffmanNode::getLetter()
	{
		return letter;
	}
	
}
