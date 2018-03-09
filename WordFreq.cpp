

#include <functional>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include <cctype>
//#include <cccatch>

/*
fixit:
вы все равно везде пишете префикс std::
давайте уберем строку
using namespace std;
*/
using namespace std;

/*
fixit: не усложняйте то, что можно сделать просто:

using Pair = std::pair<std::string, int>;
bool compare(const Pair& lhs, const Pair& rhs)
{
	return lhs.second >= rhs.second;
}
*/
typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
 
	// Defining a  function to compare two pairs. It will compare two pairs using second field
Comparator compFunctor =
			[](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
			{
				return elem1.second >= elem2.second;
			};


/*
fixit:
из названия неясно, что делает ф-я.
что значить "подготовить стандартный поток ввода"?
чем не понравился вариант из презентации?
*/
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
	/*
	зачем отдельная переменная под пустую строку?
	*/
    	std::string empty ="";
    	while((s=prepare(fin))!=empty )
            ++mapOfWordCount[s]; 
	// Declaring the type of function that accepts 2 pairs and return a bool

 
	// Declaring a set that will store the pairs using above comparision logic
	/*
	Я понял вашу задумку с компаратором только когда долистал до этого места.
	Если что-то можно сделать просто, то лучше так и сделать.
	Когда вы пойдете работать, от вас будут требовать максимально простой/понятный код, а не просто
	работающий. Понятный код -> новый разработчик меньше тратит времени на вникание -> вы экономите деньги компании.
	*/
	std::set<std::pair<std::string, int>, Comparator> setOfWords(
			mapOfWordCount.begin(), mapOfWordCount.end(), compFunctor);
			//creating File
	ofstream outputFile;
	outputFile.open ("output.txt");
	// Iterate over a set using range base for loop
	// It will display the items in sorted order of values
	/*
	может
	for (const auto& element : setOfWords) ?
	*/
	for (std::pair<std::string, int> element : setOfWords){//possibly auto would be better 
		std::cout << element.first << " - " << element.second << std::endl;
		//Outputting overall frequency files 
		outputFile<< element.first << " - " << element.second << "\n";
		
	};
	outputFile.close();
	return 0;
}
