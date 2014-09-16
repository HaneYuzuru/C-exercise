#include <iostream>
#include <stdlib.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector:

int main(){
	ostream_iterator<int> out(cout," ");
	istream_iterator<int> in(cin), eof;

	vector<int> Integer = (in, eof);
	sort(Integer.begin(),Integer.end());
	vector<int> copy;
	copy(Integer.begin(), Integer.end(), inserter(copy));
	
	out = copy;
	return 0;
}
