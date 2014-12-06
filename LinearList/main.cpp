#include <stdlib.h>
#include <iostream>
#include "LinearList.h"

int main(int argc, char *argv[]){
	LinearList list;
	bool result = false;
	result = list.insert(1, 0);
	list.print();
	result = list.insert(2, 1);
	list.print();
	int i;
	result = list.remove(i, 2);
	cout << i << endl;
	cout << "-----------------" << endl;
	list.print();
	result = list.insert(3, 0);
	list.print();
	result = list.insert(4, 2);
	list.print();
	result = list.insert(5, 1);
	list.print();
	int j = list.element(2);
	cout << j << endl;

	system("pause");
}