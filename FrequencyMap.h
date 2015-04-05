//FrequencyMap.h
//Author: Alan Berman
//5/04/2015

//FrequencyMap header file
#ifndef FREQUENCYMAP_H
#define FREQUENCYMAP_H
#include <string>
#include <unordered_map>
#include <fstream>
namespace BRMALA003 {
using namespace std;	
//Class that makes a frequency map of characters using a file
class FrequencyMap 
{
	private:
	unordered_map<char,int> frequencyMap;
	public:
	FrequencyMap() = default;
	FrequencyMap(const FrequencyMap & rhs) = default; //Copy Constructor
	FrequencyMap(FrequencyMap && rhs) = default; //Move Constructor
	//Copy and Move Assignment Operators
	FrequencyMap & operator=(const FrequencyMap & rhs) = default;
	FrequencyMap & operator=(FrequencyMap && rhs) = default;
	~FrequencyMap(void) = default; //Deconstructor
	unordered_map<char,int>& getFrequencyMap();
	void createFrequencyTable(string FileName);
	
};		
}
#endif //CODETABLE_H
