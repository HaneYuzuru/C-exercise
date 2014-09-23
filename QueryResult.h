#include <iostream>
#include <stdlib>
#include <string>
#include <vector>
#include <memory>
#include "TextQuery.h"

using namespace std;


#ifndef QueryResult
#define QueryResult
class QueryResult{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):sought(s), lines(p), file(f) { }

private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};
#endif