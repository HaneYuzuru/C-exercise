#ifndef _LINEARLIST
#define _LINEARLIST

#include <stdlib.h>
#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

class LinearList{
public:
	LinearList() :head(NULL), size(0){ }
	~LinearList(){ delete head; }

	bool insert(int x, int pos);	//在位置pos之后插入一个元素x。
	//pos为0时，在第一个元素之前插入。
	//操作成功时返回true，否则返回false。
	bool remove(int &x, int pos);	//删除位置pos处的元素。
	//操作成功时返回true，否则返回false。
	int element(int pos) const;		//返回位置pos处的元素。
	int search(int x) const;		//查找值为x的元素，返回元素的位置（第一个元素的位置为1）。未找到时返回0。
	int length() const; 			//返回元素个数。
	void print();
private:
	node *head;
	int size;
};

bool LinearList::insert(int x, int pos){
	if (size < pos){
		return false;
	}
	else{
		node *p = head;		//start from head
		node* insert = new node();
		insert -> data = x;
		insert -> next = NULL;		//initialize the node
		if (pos == 0){
			if (head == NULL){
				head = insert;
				size++;
				return true;
			}
			insert->next = p;
			head = insert;
			size++;
			return true;
		}
		for (int i = 1; i != pos; i++){
			p = p->next;
		}
		insert -> next = p->next;
		p->next = insert;
		size++;
		return true;
	}
}

bool LinearList::remove(int &x, int pos){
	if (size < pos){
		return false;
	}
	else{
		node *p = head;
		if (pos == 1){
			x = p->data;
			head = p->next;
			size--;
			return true;
		}
		for (int i = 1; i != pos - 1; i++){
			p = p->next;
		}
		x = p->next->data;
		p->next = p->next->next;
		size--;
		return true;
	}
}

int LinearList::element(int pos) const{
	//if there is no element
	if (size < pos){
		return -99999999;
	}
	else{
		node *p = head;
		for (int i = 1; i != pos; i++){
			p = p->next;
		}
		return p->data;
	}
}

int LinearList::search(int x) const{
	int pos = 1;
	//if list is empty then return 0
	if (head == NULL){
		return 0;
	}
	for (node *p = head; p->next != NULL; p = p->next){
		if (p->data == x){
			return pos;
		}
		pos++;
	}
	return 0;			//can't find
}

int LinearList::length() const{
	return size;
}

void LinearList::print(){
	node *p = head;
	if (p == NULL){
		cout << "NULL" << endl;
	}
	while (p->next != NULL){
		cout << p->data << endl;
		p = p->next;
	}
	cout << p->data << endl;

	cout << "---------------------------------------" << endl;
}
#endif