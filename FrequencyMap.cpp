//FrequencyMap.cpp
//Author: Alan Berman
//5/04/2015
#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include "FrequencyMap.h"
namespace BRMALA003
{
	//Creates an unordered_map of each char in the given file and each
	//char's frequency
	void FrequencyMap::createFrequencyTable(string fileName)
	{
		string line;
		char c;
		ifstream i(fileName.c_str());
		if (!i)
		{
			cout << "Couldn't open the file to decompress" << endl;
			return;
		}
		cout << "Reading in the file to compress... (" << fileName << ")" << endl;
		cout << "Creating an unordered_map of the characters and their frequencies..." << endl;
		//Read in each line of the txt file
		while (!i.eof())
		{
			getline(i,line);
			for (unsigned int i=0;i<line.length();i++)
			{
				c=line.at(i);
				//Insert a new char into the map 
				if (frequencyMap.count(c)==0)
				{				
					frequencyMap.insert({c,1});
				}
				else
				{
					//Add 1 to the frequency of the given char
					//Adapted from http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
					unordered_map<char,int>::iterator found = frequencyMap.find(c);
					if (found==frequencyMap.end())
					{
						cerr << "Didn't find char " << c << " in the map" << endl;
					}
					else
					{
						//Add to the frequency
						found->second++;
					}				
				}	
			}
		}
		cout << "Done!" << endl;
	}
	//Returns a reference to the map
	unordered_map<char,int>& FrequencyMap::getFrequencyMap()
	{
		return frequencyMap;
	}
}
