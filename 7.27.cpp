#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "screen.h"

using std::cout;

int main(int argc, char const *argv[])
{
	screen myScreen(5,5,'X');
	myScreen.move(4,0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	system("pause");
	return 0;
}