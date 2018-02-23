/*
 * 
 * Copyright 2017  <user@localhost.localdomain>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <functional>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include <cctype>
//#include <cccatch>
using namespace std;
std::string prepare(std::istream &in)
{
    char c;
    std::string res="";
    c=in.get();
    while(!std::isalpha(c) && !in.eof())
    {
        c=in.get();
    }
    while(std::isalpha(c))
    {
        res.push_back(std::tolower(c));
        c=in.get();
    }
    return res;
}
#include <iostream>
#include <fstream>

int main() {
 
	// Creating & Initializing a map of String & Ints
	std::map<std::string, int> mapOfWordCount;
	std::ifstream fin("input.txt");
    std::string s;
    std::string empty ="";
    while((s=prepare(fin))!=empty )
            ++mapOfWordCount[s]; 
	// Declaring the type of Predicate that accepts 2 pairs and return a bool
	typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
 
	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	Comparator compFunctor =
			[](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
			{
				return elem1.second >= elem2.second;
			};
 
	// Declaring a set that will store the pairs using above comparision logic
	std::set<std::pair<std::string, int>, Comparator> setOfWords(
			mapOfWordCount.begin(), mapOfWordCount.end(), compFunctor);
			//creating File
	ofstream outputFile;
	outputFile.open ("output.txt");
	// Iterate over a set using range base for loop
	// It will display the items in sorted order of values
	for (std::pair<std::string, int> element : setOfWords){
		std::cout << element.first << " - " << element.second << std::endl;
		//Outputting overall frequency files 
		outputFile<< element.first << " - " << element.second << "\n";
		
	};
	outputFile.close();
	return 0;
}
