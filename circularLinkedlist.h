#include <iostream>
#include <stdlib.h>
#include "node.h"

using namespace std;

#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_


class circularLinkedlist{
public:
	circularLinkedlist(int n) :head(new Node), number(n){
		Node* p = head;
		for (int i = 1; i < n; i++){
			p -> data = i;
			p->next = new Node;
			p = p->next;
		}
		p->data = n;
		p->next = head;
	}
	circularLinkedlist& Josephus(circularLinkedlist&, int m);
	void printout(circularLinkedlist& result);
	Node* head;
	int number;
};

circularLinkedlist& circularLinkedlist::Josephus(circularLinkedlist& origin, int m){
	Node* rear = origin.head;	//rear指向头结点(第一个元素)
	circularLinkedlist result(0);
	Node* resultP = result.head;
	for (int i = 1; i != origin.number; i++){
		if (i == 1){
			for (int j = 1; j != m - 1; j++){
				rear = rear->next;
			}
		}
		else{
			for (int j = 1; j != m ; j++){
				rear = rear->next;
			}
		}
		resultP->next = rear->next;	//resultP指向第一个要出列的元素
		resultP = rear->next;
		rear->next = rear->next->next;
		resultP->next = NULL;		//出列
	}
	resultP->next = rear -> next;
	resultP = rear -> next;
	rear -> next = NULL;
	return result;
}

void circularLinkedlist::printout(circularLinkedlist& result){
	Node* p = result.head;
	while (p->next != NULL){
		cout << p->next->data;
		p = p->next;
	}
	cout << endl;
}


#endif /* CIRCULARLINKEDLIST_H_ */
