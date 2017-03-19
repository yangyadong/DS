#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>

typedef struct listNode{
	char data;
	struct listNode *next;	
}listNode,*listlistNode;

void create(listlistNode &L){
	L=new listNode;
	L->next=NULL;
}

void add(listlistNode &L){
	listlistNode p,s;
	p=L;
	char data;
	cout<<"请输入数据以#结尾:";
	cin>>data;
	while(data!='#'){
		while(p->next){
			p=p->next;		
		}
		s=new listNode;
		s->data=data;
		s->next=NULL;
		p->next=s;

		cin>>data;
	}
}

void pop(listlistNode &L){
	listlistNode p;
	if(L->next){
		p=L->next->next;
		cout<<"出栈的数据为:"<<L->next->data<<endl;
		delete (L->next);
		L->next->next=NULL;
		L->next=p;
	}
}

void showData(listlistNode &L){
	listlistNode p;
	p=L;
	cout<<"数据为:";
	while(p->next){
		cout<<p->next->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}

void main(){
	listlistNode L;
	create(L);
	add(L);
	pop(L);
	showData(L);
}