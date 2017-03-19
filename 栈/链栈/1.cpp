#include<stdio.h>
#include <malloc.h>
#include<iostream.h>

#define OK 0
#define ERROR 1


typedef struct StackNode{
	char data;
	struct StackNode *next;
}StackNode,*listNode;

void create(listNode &S){
	S=new StackNode;
	S->next=NULL;
}

void add(listNode &S){
	char data;
	cout<<"请输入数据以#结尾:";
	cin>>data;
	listNode q,p;
	p=S;
	while(data!='#'){
		q=new StackNode;
		p->next=q;
		q->data=data;
		q->next=NULL;
		//cout<<"请输入数据以#结尾:";
		p=p->next;
		cin>>data;
	}
}

//出栈
void pop(listNode &S){
	listNode p;
	p=S;
	if(!(p->next)){
		cout<<"链栈为空!"<<endl;
	}else{
		while(p->next->next){
			p=p->next;
		}
		cout<<"数据:"<<p->next->data<<"出栈！"<<endl;
		p->next=NULL;
		delete (p->next);
	}
}

void showData(listNode &S){
	listNode p;
	p=S;
	if(!(p->next)){
		cout<<"链栈为空!"<<endl;
	}else{
		while(p->next){
			cout<<p->next->data<<endl;
			p=p->next;
		}
	}
}

void main(){
	listNode S;
	create(S);
	add(S);
	pop(S);
	showData(S);
}