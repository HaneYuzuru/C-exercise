#include <iostream>
#include <stdlib.h>
#include "Chapter6.h"

using std::cout;
using std::cin;
using std::endl;


int main(int argc, char const *argv[])
{
	for(size_t i = 0 ; i != 20 ; i++){
		size_t Nu = callNumber();
		cout << "The callNumber is : " << Nu << endl;
	}
	system("pause");
	return 0;
}

size_t callNumber(void){
	static size_t callNumber = 0;
	callNumber++;
	return callNumber;
}