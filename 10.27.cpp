#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
	vector<string> str;
	cout << "Please put in ten strings to convert: " << endl;
	string word;
	for(int i = 0; i != 10; i ++){
		cin >> word;
		str.push_back(word);
	}
	vector<string> copy;
	unique_copy(str.begin(), str.end(), inserter(copy));
	for(vector<string>::size i = 0; i != copy.size(); i ++){
		cout << copy[i] << endl;
	}
	system("pause");
	return 0;
}
