#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;
using std::string;
using std::vector;
using ifstream;
using istringstream;

int main(){
	ifstream str("string.txt");
	string word,line;
	vector<string> vestr;
	while(str >> line){
		istringsream record(line);
		while(record >> word){
			vestr.push_back(word);
		}
	}

	auto count = count_if(vestr.begin(),vestr.end(),bind(check_size,_1,6));
	cout << "The count is: " << count <<endl;
	system("pause");
	return 0;
}
