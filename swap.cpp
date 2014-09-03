#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

void swap(int *a,int *b);

int main(int argc, char const *argv[])
{
	int m,*a;
	int n,*b;
	m = 1;
	n = 2;
	a = &m;
	b = &n;
	swap(a,b);
	cout << m << n << endl;
	system("pause");
	return 0;
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}