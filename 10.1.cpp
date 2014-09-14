#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::istringstream;

int main(int argc, char const *argv[])
{
	std::vector<string> strInFile;
	ifstream fstem("string.txt");
	string line,word;
	while(getline(fstem, line)){
		istringstream record(line);
		while(record >> word){
			strInFile.push_back(word);
		}
	}

	cout << "Please put in the string you want to count:" << endl;
	string val;
	cin >> val;
	int Count = count(strInFile.begin(), strInFile.end(), val);
	cout << "The number of the counted string in the sequence is: " << Count <<endl;
	system("pause");
	return 0;
}