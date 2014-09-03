#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;

struct course
{
	string name;
	int student;
};
struct node
{
	course courseData;
	struct node *next;
};

struct node *insert(node *head);
struct node *search(node *head,string x);
struct node *delete(node *head,string x);
void print(node *head);

int main(int argc, char const *argv[])
{
	string courseName;
	string operate;
	node *head,*searchpoint;
	head = NULL; 
	cout << "请输入您想执行的操作(insert,search,sortNumber,sortCourse)：\n" << endl;
	cin >> operate;
	switch(operate){
		case "insert": insert(head);
		case "search": {
			cout << "请输入您要查找的课程名：\n" << endl;
			cin >> courseName;
			searchpoint = search(head,courseName);
		}
		case "sortNumber"{

		}
		case "sortCourse"{

		}
		case "delete"{
			cout << "请输入您要删除的课程名：\n" << endl;
			cin >> courseName;

		}
	}

	print(head);
	
	system("pause");

	return 0;
}

struct node *insert(node *head){
	int i;
	node *p,*p2;
	p = p2 = (node*)malloc( sizeof(struct node) );			//分配长度为sizeof(struct node)长度的内存块，并返回分配内存块的指针，若没成功则返回空指针
	p -> next = NULL;   //将新节点的指针设置为空
	course newcourse,*pCourse;
	pCourse = &newcourse;
	cout << "Please input the course name:\n" << endl;
	cin >> pCourse -> name;
	cout << "Please input the number of student who selected this course\n" << endl;
	cin >> pCourse -> student;
	p -> courseData = newcourse;									
	if(head == NULL){
		head = p;    //若为空表则接入表头；
	}else{					//非空表则接到表尾
		p2 = head -> next;
		while(p2 != NULL){
			p2 = p2 -> next;
		}
		p2 -> next ->courseData = p;
	}													
	return head;
}

struct node *search(node *head,string x){
	node *p;
	string y;
	course thisCourse,*pthis;
	p = head -> next;
	while(p!=NULL){
		thisCourse = p -> courseData;
		pthis = &thisCourse;
		y = pthis -> name;
		if(strcmp(y,x) == 0){
			return p;
		}else{
			p = p -> next;
		}
	}
	if(p == NULL){
		cout << "没有查找到该数据" << endl;
		return p;
	}
}

struct node *delete(node *head,string x){
	node *pToDelete;
	string y;
	course thisCourse,*pthis;
	course firstCourse,*pthis;
	p = head -> next;
	firstCourse = p -> courseData;
	pfirst = &firstCourse;
	if(strcmp(pfirst -> name,x) == 0){
		head -> next = p ->next;
		delete(p);
	} else{
		while((p -> next) != NULL){
			thisCourse = p -> next -> courseData;
			pthis = &thisCourse;
			y = pthis -> name;
			if(strcmp(y,x) == 0){
				if((p -> next -> next) != NULL){
					p -> next = p -> next -> next; 
				}else{
					p -> next = NULL;
				}
				delete(p -> next);
			}else{
				p = p -> next;
			}
		}
		if(p -> next == NULL){
			cout << "没有查找到该数据" << endl;
		}
	}
	return head;
}
