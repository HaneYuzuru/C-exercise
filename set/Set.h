#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#ifndef _SET
#define _SET
class Set{
public:
	Set(){ }
	Set(Set &set){
		vector<int>::iterator iter;
		for (iter = set.getIteratorBegin(); iter != set.getIteratorEnd(); iter++){
			elem.push_back(*iter);
		}
	}
	~Set(){ }

	vector<int>::iterator getIteratorBegin();	//得到元素的迭代器
	vector<int>::iterator getIteratorEnd();
	int size();								//得到元素个数
	void print();
	bool operator +=(int newelem);			//增加元素
	bool operator -=(int ele);				//删除元素
	bool operator <=(Set& rhs);		//包含于
	bool operator ==(Set& rhs);		//相等
	bool operator !=(Set& rhs);		//不等
	Set operator |(Set& rhs);			//并集
	Set operator &(Set& rhs);			//交集
	Set operator -(Set& rhs);			//差集
private:
	//集合中的数字
	vector<int> elem;
};

vector<int>::iterator Set::getIteratorBegin(){
	return elem.begin();
}

vector<int>::iterator Set::getIteratorEnd(){
	return elem.end();
}

int Set::size(){
	return elem.size();
}

void Set::print(){
	vector<int>::iterator iter;
	for (iter = elem.begin(); iter != elem.end(); iter++){
		cout << *iter << " " << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
}

bool Set::operator +=(int newelem){
	bool find = false;
	vector<int>::iterator iter;
	for (iter = elem.begin(); iter != elem.end(); iter++){
		if (*iter == newelem){
			find = true;
			break;
		}
	}
	if (!find){
		elem.push_back(newelem);
		return true;
	}
	else{
		return false;
	}
}

bool Set::operator -=(int ele){
	vector<int>::iterator iter;
	for (iter = elem.begin(); iter != elem.end();){
		if (*iter == ele){
			elem.erase(iter);
			return true;
		}
		else{
			iter++;
		}
	}
	return false;
}

bool Set::operator <=(Set& rhs){
	vector<int>::iterator iterLhs;	//左操作数的迭代器
	vector<int>::iterator iterRhs;	//右操作数的迭代器
	for (iterLhs = elem.begin(); iterLhs != elem.end(); iterLhs++){
		bool find = false;
		for (iterRhs = rhs.getIteratorBegin(); iterRhs != rhs.getIteratorEnd(); iterRhs++){
			if (*iterRhs == *iterLhs){
				find = true;
				break;
			}
		}
		//若没有找到相应元素，则返回false
		if (!find){
			return false;
		}
	}
	//所有在左操作数中元素都在右操作数中，则返回true
	return true;
}

bool Set::operator ==(Set& rhs){
	if (this->size() != rhs.size()){
		return false;
	}
	else{
		vector<int>::iterator iterLhs;	//左操作数的迭代器
		vector<int>::iterator iterRhs;	//右操作数的迭代器
		for (iterLhs = elem.begin(); iterLhs != elem.end(); iterLhs++){
			bool find = false;
			for (iterRhs = rhs.getIteratorBegin(); iterRhs != rhs.getIteratorEnd(); iterRhs++){
				if (*iterRhs == *iterLhs){
					find = true;
					break;
				}
			}
			//若没有找到相应元素，则返回false
			if (!find){
				return false;
			}
		}
		return true;
	}
}

bool Set::operator !=(Set& rhs){
	bool equal = (*this == rhs);
	return !equal;
}

Set Set::operator |(Set& rhs){
	if (*this <= rhs){
		return rhs;
	}
	else if (rhs <= *this){
		return *this;
	}
	else{
		//拷贝本对象
		Set copy(*this);
		//构建一个返回对象
		Set product;
		vector<int>::iterator iter;
		for (iter = rhs.getIteratorBegin(); iter != rhs.getIteratorEnd(); iter++){
			vector<int>::iterator findresult = find(copy.getIteratorBegin(), copy.getIteratorEnd(), *iter);
			//如果找到了
			if (findresult != copy.getIteratorEnd()){
				//拷贝对象删除这个元素
				copy -= *iter;
			}
			product += *iter;
		}
		//将拷贝对象的剩余元素复制到返回对象中
		for (iter = copy.getIteratorBegin(); iter != copy.getIteratorEnd(); iter++){
			product += *iter;
		}
		return product;
	}
}

Set Set::operator &(Set& rhs){
	if (*this <= rhs){
		return *this;
	}
	else if (rhs <= *this){
		return rhs;
	}
	else{
		vector<int>::iterator iterLhs;
		vector<int>::iterator iterRhs;
		Set set;
		if (this->size() < rhs.size()){
			for (iterLhs = elem.begin(); iterLhs != elem.end(); iterLhs++){
				for (iterRhs = rhs.getIteratorBegin(); iterRhs != rhs.getIteratorEnd(); iterRhs++){
					if (*iterLhs == *iterRhs){
						set += *iterLhs;
						break;
					}
				}
			}
		}
		else{
			for (iterRhs = rhs.getIteratorBegin(); iterRhs != rhs.getIteratorEnd(); iterRhs++){
				for (iterLhs = elem.begin(); iterLhs != elem.end(); iterLhs++){
					if (*iterLhs == *iterRhs){
						set += *iterLhs;
						break;
					}
				}
			}
		}
		return set;
	}
}


Set Set::operator -(Set& rhs){
	if (*this == rhs){
		return *(new Set());
	}
	else{
		vector<int>::iterator iterRhs;
		vector<int>::iterator iterLhs;
		Set copy(*this);
		for (iterRhs = rhs.getIteratorBegin(); iterRhs != rhs.getIteratorEnd(); iterRhs++){
			for (iterLhs = copy.getIteratorBegin(); iterLhs != copy.getIteratorEnd(); ){
				if (*iterLhs == *iterRhs){
					copy -= *iterLhs;
					break;
				}
				else{
					iterLhs++;
				}
			}
		}
		return copy;
	}
}

#endif