#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

//create template for word,occurence
template <class keyWord, class numWord> 
void printMap(map<keyWord, numWord> map)
{
	//define type as template
	typedef std::map<keyWord, numWord>::iterator iterator;
	
	//iterate from beginning of map to end
	for (iterator pos = map.begin(); pos != map.end(); pos++)
	{
		//print keyword then value
		cout << pos->first << ": " << pos->second << endl;
	}
}

int countWords(string inputFile, string listWords[])
{
	//target will be keyword
	string target;
	//declare map
	map<string, unsigned int> wordCount;

	//begin streaming input file provided
	ifstream fileStream(inputFile);

	//if file opens successfully
	if (fileStream.is_open())
	{
		//loops for every word in target list
		for (int i = 0; i < sizeof(listWords); i++)
		{	
			wordCount[listWords[i]] = 0;
		}
		
		//while not end of stream, checks error flags
		while (fileStream.good())
		{
			//push next word to target
			fileStream >> target;
			
			//loops for every word in target list
			for (int j = 0; j < sizeof(listWords); j++)
			{	
				//if the target is equal to list word
				if (target == listWords[j])
				{	
					//if it is the first occurence of the word
					if (wordCount.find(target) == wordCount.end())
					{
						wordCount[target] = 1;
					}
					//if it is not the first occurence of the word
					else
					{
						wordCount[target]++;
					}
				}
			}
		}
	}
	//if file fails to open
	else
	{
		cout << "Error opening file!" << endl;
		return 0;
	}
	
	//print the map
	printMap(wordCount);
	
	//return to main
	return 0;
}

int main(void)
{
	string inputFile;
	int i = 0;

	cout << "Specify filename: " << endl;
	getline(cin, inputFile);
	cout << endl;
	
	cout << "Specify words to count: " << endl;

	//declare array to hold all our target words
	string listWords[10];

	//if line retrieved form input and 
	while (getline(cin, listWords[i]) && !listWords[i].empty() && i!=10)
	{
		i++;
	}

	cout << endl;
	cout << "Counting..." << endl;

	countWords(inputFile, listWords);

	return 0;
}