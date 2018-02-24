

#include <functional>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include <cctype>
//#include <cccatch>
using namespace std;
typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
 
	// Defining a  function to compare two pairs. It will compare two pairs using second field
Comparator compFunctor =
			[](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
			{
				return elem1.second >= elem2.second;
			};
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
	// Declaring the type of function that accepts 2 pairs and return a bool

 
	// Declaring a set that will store the pairs using above comparision logic
	std::set<std::pair<std::string, int>, Comparator> setOfWords(
			mapOfWordCount.begin(), mapOfWordCount.end(), compFunctor);
			//creating File
	ofstream outputFile;
	outputFile.open ("output.txt");
	// Iterate over a set using range base for loop
	// It will display the items in sorted order of values
	for (std::pair<std::string, int> element : setOfWords){//possibly auto would be better 
		std::cout << element.first << " - " << element.second << std::endl;
		//Outputting overall frequency files 
		outputFile<< element.first << " - " << element.second << "\n";
		
	};
	outputFile.close();
	return 0;
}
