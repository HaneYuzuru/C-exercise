#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::string;

int main(){
	ifstream fin("string.txt");
	string word,line;
	vector<string> vestr;
	while( fin >> line){
		istringstream record(line);
		while(record >> word){
			vestr.push_back(word);
		}
	}
	int count = (int)count_if(vestr.begin(),vestr.end(),[](string &r){return r.size() < 6;});
	cout << "the number of strings whose size is larger than 6 is: " << count << endl;
	system("pause");
	return 0;
}
