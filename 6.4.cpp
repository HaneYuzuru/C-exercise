#include <iostream>
#include <stdlib.h>
#include <string.h>

using std::cout;
using std::endl;
using std::cin;

int fact(int number);

int main(int argc, char const *argv[])
{
	int j;
	cout << "Please input the number you want to fact:" << endl;
	cin >> j;
	int result = fact(j);
	cout << "The fact of the given number is : " << result << endl;

	system("pause");

	return 0;
}

int fact(int number){
	int result = 1;
	if(number > 1 ){
		result = number * fact(number-1);
	} else if(number == 1){
		result = 1;
	}
	return result;
}