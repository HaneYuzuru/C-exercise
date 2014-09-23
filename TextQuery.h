#include <fstream>
#include <sstream>
#include <stdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include "QueryResult.h"

using namespace std;

#ifndef TextQuery
#define TextQuery
class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(ifstream &infile)：file(new vector<string>) {
		string text;
		while(getline(infile, text)){
			file -> push_back(text);
			int n = file.size() - 1;
			istringstream line(text);
			shared_ptr<set<line_no>> &lines = wm[word];		//取出相应的set，若不存在此key则将此key加入map中
			if(!lines)  //第一次遇到时指针为空。
				lines.reset(new set<line_no>);    //分配新的set,此处使用的是shared_ptr成员方法故使用点运算符调用方法
			lines -> insert(n);    //在相应的set中加入行。
		}
	 }				//构造函数已经将数据映射到map中
	QueryResult query(const string &s) const;
private:
	shared_ptr<vector<string>> file;             //用来保存文件中每一行的内容
	map<string, shared_ptr<set<line_no>> wm;     //将每个单词映射到对应行中（行数为一个set可以保证不重复）
};

QueryResult TextQuery::query(const string &s) const{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);//若没有找到则返回这个空的指针
	map<string,shared_ptr<set<line_no>>> loc = wm.find(s);
	if(loc == wm.end())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, loc -> second, file);
}
#endif