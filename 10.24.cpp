#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::vector;

int main(){
	vector<int> Integer;
	for(int i = 0; i != 100; i ++ ){
		Integer.push_back(i);
	}
	string standard;
	cout << "Please put in the standard string: " << endl;
	cin >> standard;
	int first = for_each(Integer.begin(),Integer.end(),bind(check_size,standard,_1));
	cout << "The first number that bigger than the string size is: " << first << endl;
	system("pause");
	return 0;
}