//HuffmanNode.h
//Author: Alan Berman
//1/04/2015

//HuffmanNode header file
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <memory>
#include <string>
namespace BRMALA003 {
using namespace std;	
//Class that makes HuffmanNodes which constitute the 
//HuffmanTree
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
	int getFrequency() const;
	char getLetter();
	shared_ptr<HuffmanNode>& getLeft();
	shared_ptr<HuffmanNode>& getRight();

};		
}
#endif //HUFFMANNODE_H

