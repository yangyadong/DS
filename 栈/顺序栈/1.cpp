#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#define OK 0
#define ERROR 1
#define OVERFLOW -1
#define MAXSIZE 100
#define ADDSIZE 10
typedef char elemType;

typedef struct{
	char *top;
	char *base;
	int stacksize;
}SqStack;

//初始化栈
int InitStack(SqStack &s){
	s.base=new elemType[MAXSIZE];

	//s.base=(elemType *)malloc(MAXSIZE*sizeof(elemType));
	if(!s.base) exit(OVERFLOW);
	s.top=s.base;
	s.stacksize=MAXSIZE;
	return OK;
}
//数据添加
void addData(SqStack &s){
	elemType adddata;
	cout<<"请输入数据:";
	cin>>adddata;
	if(s.top-s.base==s.stacksize){
		s.base=(elemType *)realloc(s.base,(s.stacksize+ADDSIZE)*sizeof(elemType));
		if(!s.base){
			exit(OVERFLOW);
		}else{
			s.top=s.base+ADDSIZE;
		}
	}
	*s.top++=adddata;
}
//出栈
void pop(SqStack &s){
	if(s.top!=s.base){
		cout<<*--s.top<<endl;
	}else{
		cout<<"栈为空!"<<endl;
	}
}
//展示数据
void showData(SqStack &s){
	SqStack p;
	p=s;
	while(p.base!=p.top){
		cout<<*--p.top<<endl;
	}
}
void main(){
	SqStack L;
	InitStack(L);
	addData(L);
	//pop(L);
	addData(L);
	//pop(L);
	showData(L);
}