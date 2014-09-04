#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool findCap(const string &p);
string change(const string &p);

int main(){
	string toConvert;
	cout << "Please input the string you want to convert:" <<endl;
	cin >> toConvert;
	bool have = findCap(toConvert);
	string converted = change(toConvert);
	if(have){
		cout << converted <<endl;
	}
	system("pause");
	return 0;
}

bool findCap(const string &p){
	bool result = false;
	for(size_t i = 0 ; i != p.size() ; i++){
		if(( p[i]>= 'A') && ( p[i]<= 'Z')){
			result = true;
			break;
		}
	}
	return result;
}

string change(const string &p){
	string result = p;
	transform(result.begin(),result.end(),result.begin(),tolower);		//STL引入algorithm类库
	return result;
}