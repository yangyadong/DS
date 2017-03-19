#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>

#define MAXSIZE 10

typedef struct{
	char *base;
	int foot;
	int head;
}List;

void create(List &L){
	L.base=new char[MAXSIZE];
	if(!L.base){
		exit(-1);
	}else{
		L.foot=L.head=0;
	}
}

void add(List &L){
	char data;
	cout<<"������������#��β:";
	cin>>data;
	while(data!='#'){
		if((L.foot+1)%MAXSIZE==L.head){
			cout<<"����������"<<endl;
		}else{
			L.base[L.foot]=data;
			L.foot=(L.foot+1)%MAXSIZE;
			cin>>data;
		}
	}
}
void pop(List &L){
	if(L.foot==L.head){
		cout<<"����Ϊ�գ�"<<endl;
	}else{
		cout<<"��ջ����λ:"<<L.base[L.head]<<endl;
		L.head=(L.head+1)%MAXSIZE;
	}
}

void show(List &L){
	int num=L.head;
	if(L.foot==num){
		cout<<"����Ϊ�գ�"<<endl;
	}else{
		while(L.base[num]){
			cout<<"����:"<<L.base[num]<<"   ";
			num=(num+1)%MAXSIZE;
		}
		cout<<endl;
	}
}

void main(){
	List L;
	create(L);
	add(L);
	pop(L);
	show(L);
}