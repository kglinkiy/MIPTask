

#include <functional>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include <cctype>

using Pair = std::pair<std::string, int>;
typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
/*
using Comparator = std::function<bool(const Pair&, const Pair&)>;
*/

bool compare(const Pair& lhs, const Pair& rhs)
{
	return lhs.second >= rhs.second;
};

/*
название переменных, ф-й и т.д. должны быть в одном стиле.
например, первое слово со строчной, остальные в заглавной:
prepareInputToLower ... либо все с заглавной, тогда Compare
*/
std::string prepareInputToLower(std::istream &in)
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
	   	
    	while((s=PrepareInputToLower(fin))!="" )
            ++mapOfWordCount[s]; 
	// Declaring the type of function that accepts 2 pairs and return a bool

 
	// Declaring a set that will store the pairs using above comparision logic
	
	std::set<std::pair<std::string, int>, Comparator> setOfWords(
			mapOfWordCount.begin(), mapOfWordCount.end(),compare);
			//creating File
	ofstream outputFile;
	outputFile.open ("output.txt");
	// Iterate over a set using range base for loop
	// It will display the items in sorted order of values
	
	for (const auto& element : setOfWords){//possibly auto would be better 
		std::cout << element.first << " - " << element.second << std::endl;
		//Outputting overall frequency files 
		outputFile<< element.first << " - " << element.second << "\n";
		
	};
	outputFile.close();
	return 0;
}
