//CodeTable.h
//Author: Alan Berman
//5/04/2015

//CodeTable header file
#ifndef CODETABLE_H
#define CODETABLE_H
#include <string>
#include <memory>
#include <unordered_map>
#include "HuffmanNode.h"
namespace BRMALA003 {
using namespace std;	
//Class that makes a code table using a HuffmanTree
class CodeTable 
{
	private:
	unordered_map<char,string> codeTable;
	string buffer;
	public:
	CodeTable();
	CodeTable(const CodeTable & rhs) = default; //Copy Constructor
	CodeTable(CodeTable && rhs) = default; //Move Constructor
	//Copy and Move Assignment Operators
	CodeTable & operator=(const CodeTable & rhs) = default;
	CodeTable & operator=(CodeTable && rhs) = default;
	~CodeTable(void) = default; //Destructor
	unordered_map<char,string>& getCodeTable();
	string& getBuffer();
	void setBuffer();
	void createCodeTable(shared_ptr<HuffmanNode> nodeptr, string code);
};		
}
#endif //CODETABLE_H
