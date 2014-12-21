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

	vector<int>::iterator getIteratorBegin();	//�õ�Ԫ�صĵ�����
	vector<int>::iterator getIteratorEnd();
	int size();								//�õ�Ԫ�ظ���
	void print();
	bool operator +=(int newelem);			//����Ԫ��
	bool operator -=(int ele);				//ɾ��Ԫ��
	bool operator <=(Set& rhs);		//������
	bool operator ==(Set& rhs);		//���
	bool operator !=(Set& rhs);		//����
	Set operator |(Set& rhs);			//����
	Set operator &(Set& rhs);			//����
	Set operator -(Set& rhs);			//�
private:
	//�����е�����
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
	vector<int>::iterator iterLhs;	//��������ĵ�����
	vector<int>::iterator iterRhs;	//�Ҳ������ĵ�����
	for (iterLhs = elem.begin(); iterLhs != elem.end(); iterLhs++){
		bool find = false;
		for (iterRhs = rhs.getIteratorBegin(); iterRhs != rhs.getIteratorEnd(); iterRhs++){
			if (*iterRhs == *iterLhs){
				find = true;
				break;
			}
		}
		//��û���ҵ���ӦԪ�أ��򷵻�false
		if (!find){
			return false;
		}
	}
	//���������������Ԫ�ض����Ҳ������У��򷵻�true
	return true;
}

bool Set::operator ==(Set& rhs){
	if (this->size() != rhs.size()){
		return false;
	}
	else{
		vector<int>::iterator iterLhs;	//��������ĵ�����
		vector<int>::iterator iterRhs;	//�Ҳ������ĵ�����
		for (iterLhs = elem.begin(); iterLhs != elem.end(); iterLhs++){
			bool find = false;
			for (iterRhs = rhs.getIteratorBegin(); iterRhs != rhs.getIteratorEnd(); iterRhs++){
				if (*iterRhs == *iterLhs){
					find = true;
					break;
				}
			}
			//��û���ҵ���ӦԪ�أ��򷵻�false
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
		//����������
		Set copy(*this);
		//����һ�����ض���
		Set product;
		vector<int>::iterator iter;
		for (iter = rhs.getIteratorBegin(); iter != rhs.getIteratorEnd(); iter++){
			vector<int>::iterator findresult = find(copy.getIteratorBegin(), copy.getIteratorEnd(), *iter);
			//����ҵ���
			if (findresult != copy.getIteratorEnd()){
				//��������ɾ�����Ԫ��
				copy -= *iter;
			}
			product += *iter;
		}
		//�����������ʣ��Ԫ�ظ��Ƶ����ض�����
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