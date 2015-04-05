//CodeTable.cpp
//Author: Alan Berman
//5/4/2015
#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>
#include "CodeTable.h"
#include "HuffmanNode.h"
//Class that makes a code table using a HuffmanTree
namespace BRMALA003
{
	using namespace std;
	CodeTable::CodeTable()
	{
		buffer="";
	}
	unordered_map<char,string>& CodeTable::getCodeTable()
	{
		return codeTable;
	}
	//Recursive method that creates the code table,
	//using inorder traversal of the HuffmanTree
	void CodeTable::createCodeTable(shared_ptr<HuffmanNode> nodeptr, string code)
	{
		//If the pointer to the node is not null
		if (nodeptr)
		{
			//Do the node's left child
			CodeTable::createCodeTable(nodeptr->getLeft(),code+"0");
			//If the node is a leaf (i.e. has a character),
			//insert it into the code table
			if (nodeptr->getLeft()==NULL && nodeptr->getRight() == NULL)
			{
				CodeTable::getCodeTable().insert({nodeptr->getLetter(),code});
				
			}
			//Do the node's right child
			CodeTable::createCodeTable(nodeptr->getRight(),code+"1");
		}
	}
	//Returns a reference to the buffer string
	string& CodeTable::getBuffer()
	{
		return buffer;
	}
	void CodeTable::setBuffer()
	{
		//Set the buffer string
		for (auto i=getCodeTable().begin();i!=getCodeTable().end();++i)
		{
			buffer+=i->second;
		}
	}

}
