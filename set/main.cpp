#include "Set.h"
#include <stdlib.h>
#include <iostream>

int main(int argc, char* argv[]){
	Set set1;
	Set set2;
	set1 += 0;
	set1.print();
	set1 += 1;
	set1.print();
	set1 += 2;
	set1.print();
	set1 += 3;
	set1.print();
	set1 += 2;
	set1.print();
	set1 -= 3;
	set1.print();
	set1 -= 4;
	set1.print();
	set2 += 1;
	set2 += 2;
	set2.print();
	if (set2 <= set1){
		cout << "°üº¬" << endl;
	}
	if (set1 == set2){
		cout << "µÈÓÚ" << endl;
	}
	set2 += 6;
	set2.print();
	Set set3 = set2 & set1;
	set3.print();
	Set set4 = set2 | set1;
	set4.print();
	Set set5 = set2 - set1;
	set5.print();
	Set set6 = set1 - set2;
	set6.print();

	cout << "---------------------------" << endl;
	set1.print();
	set2.print();
	system("pause");
}