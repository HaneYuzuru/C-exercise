#include <iostream>
#include <stdlib.h>
#include <vector>
#include <numeric>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	vector<double> data;
	double word;
	for(int i = 0; i != 10; i++ ){
		cin >> word;
		data.push_back(word);
	}
	double sum = accumulate(data.begin(), data.end(), 0.0);
	cout << "The sum is: " << sum;
	system("pause");
	return 0;
}