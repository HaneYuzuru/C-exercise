#include <iostream>
#include <stdlib.h>
#include "circularLinkedlist.h"
#include "node.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Please put in the total number to start a Josephus: " << endl;
	int number = 0;
	cin >> number;
	circularLinkedlist circu(number);
	cout << "Please put in the count number to start a Josephus: " << endl;
	int count = 0;
	cin >> count;
	circularLinkedlist result(0);
	result = circu.Josephus(circu, count);
	result.printout(result);
	system("pause");
	

	return 0;
}