//HuffmanNode.cpp
//Author: Alan Berman
//1/4/2015

#include "HuffmanNode.h"
#include <queue>
#include <vector>
#include <memory>
//Class that makes HuffmanNodes which constitute the 
//HuffmanTree
namespace BRMALA003
{	
	using namespace std;
	//Constructor for HuffmanNode with a letter and a frequency
	HuffmanNode::HuffmanNode(char l, int f)
	{
		letter = l;
		frequency = f;
		left=NULL;
		right=NULL;
	} 
	//Constructor for a HuffmanNode with only a frequency
	//(Parent node)
	HuffmanNode::HuffmanNode(int f)
	{
		letter = '\0';
		frequency = f;
		left=NULL;
		right=NULL;
	}
	//Copy Constructor
	HuffmanNode::HuffmanNode(const HuffmanNode & rhs)
	{
		letter=rhs.letter;
		frequency=rhs.frequency;
		left=rhs.left;
		right=rhs.right;
	}
	//Move Constructor
	HuffmanNode::HuffmanNode(HuffmanNode && rhs)
	{
		letter=move(rhs.letter);
		frequency=rhs.frequency;
		left=move(rhs.getLeft());
		right=move(rhs.getRight());
		rhs.letter='\0';
		rhs.frequency=-1;
		rhs.getLeft()=NULL;
		rhs.getRight()=NULL;
	}
	//Copy Assignment Operator
	HuffmanNode & HuffmanNode::operator=(const HuffmanNode & rhs)
	{
		if(this != &rhs) 
		{
			letter=rhs.letter;
			frequency=rhs.frequency;
			left=rhs.left;
			right=rhs.right;
		}
		return *this;
	}
	//Move Assignment Operator
	HuffmanNode & HuffmanNode::operator=(HuffmanNode && rhs)
	{
		if(this != &rhs) 
		{
			letter=move(rhs.letter);
			frequency=rhs.frequency;
			left=move(rhs.getLeft());
			right=move(rhs.getRight());
			rhs.letter='\0';
			rhs.frequency=-1;
			rhs.getLeft()=NULL;
			rhs.getRight()=NULL;
		}
		return *this;
	}
	//Get a node's frequency
	int HuffmanNode::getFrequency() const
	{
		return frequency;
	}
	//Get the pointer to a node's left child
	shared_ptr<HuffmanNode>& HuffmanNode::getLeft()
	{
		return left;
	}
	//Get the pointer to a node's right child
	shared_ptr<HuffmanNode>& HuffmanNode::getRight()
	{
		return right;
	}
	//Get a (non-parent) node's character
	char HuffmanNode::getLetter()
	{
		return letter;
	}
	
}
