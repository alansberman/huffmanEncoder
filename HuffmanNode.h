//HuffmanNode.h
//Author: Alan Berman
//1/04/2015

//Adapted from http://www.cprogramming.com/tutorial/lesson18.html
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <memory>
namespace BRMALA003 {
using namespace std;	
class HuffmanNode 
{
	private:
	int frequency;
	char letter;
	shared_ptr<HuffmanNode> left;
	shared_ptr<HuffmanNode> right;
	
	public:
	HuffmanNode(char l, int f);
	HuffmanNode(int f);
	HuffmanNode(const HuffmanNode & rhs) = default; //Copy Constructor
	HuffmanNode(HuffmanNode && rhs) = default; //Move Constructor
	//Copy and Move Assignment Operators
	HuffmanNode & operator=(const HuffmanNode & rhs) = default;
	HuffmanNode & operator=(HuffmanNode && rhs) = default;
	~HuffmanNode(void) = default; //Deconstructor
	int getFrequency();
	shared_ptr<HuffmanNode> getLeft();
	shared_ptr<HuffmanNode> getRight();
};	
	
	
	
}
#endif //HUFFMANNODE_H

