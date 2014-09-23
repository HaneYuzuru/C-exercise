#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "TextQuery.h"
#include "QueryResult.h"


using namespace std;

void runQueries(ifstream &infile);
std::ostream& print(std::ostream&, const QueryResult&)

int main(int argc, char const *argv[])
{
	ifstream infile("infile.txt");
	runQueries(infile);
	return 0;
}

void runQueries(ifstream &infile){
	TextQuery tq(infile); //保存文件并建立查询map
	//提示用户输入要查询的单词，完成查询并打印结果
	while (true) {
		cout << "enter word to look for, or q to quit";
		string s;
		//遇到文件尾或用户输入q时循环终止
		if(!(cin >> s) || s == "q") break;
		//指向查询并 打印结果
		print(cout, tq.query(s)) <<endl;
	}
}

std::ostream& print(std::ostream& os, const QueryResult& qr){
	os << qr.sought << " occurs" << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
	for (line_no num : *qr.lines){
		os << "\t(line " << num +1 << ")" << *(qr.file -> begin() + num) << endl;
	}
	return os;
}