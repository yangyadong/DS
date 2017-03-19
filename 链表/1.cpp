#include<stdio.h>
#include <malloc.h>
#include<iostream.h>
#define OK 1
#define ERROR 0

typedef struct PNode{
    char nodeData;
    struct PNode *next;
	struct PNode *pre;
}PNode,*PolyNomial;

void create(PolyNomial &L){
	L = new PNode;
	L->next=NULL;
	L->pre=NULL;
}

//头插法
void topInsert(PolyNomial &L){
	char data;
	cout<<"请输入数据:";
	cin>>data;
	PolyNomial s;

	s=new PNode;
	s->nodeData=data;
	s->next=L->next;
	s->pre=L;
	L->next=s;
	if(s->next){
		s->next->pre=s;
	}

	for(int i=0;i<10;i++){
		//生成节点的两种方式
		s=new PNode;
		//s=(PolyNomial)malloc(sizeof(PNode));
		
		s->nodeData=char((int)(48+i/2));
		s->next=L->next;
		s->pre=L;
		L->next=s;
		if(s->next){
			s->next->pre=s;
		}
	}
}
//尾插法
void footInsert(PolyNomial &L){
	char data;
	cout<<"请输入数据:";
	cin>>data;
	PolyNomial q,s;

	//生成节点的两种方式
	s=new PNode;
	//s=(PolyNomial)malloc(sizeof(PNode));
	
	q=L;
	while(q->next){
		q=q->next;
	}
	q->next=s;
	s->pre=q;
	s->nodeData=data;
	s->next=NULL;
}
//删除节点
void delectNode(PolyNomial &L,int deleteId){
	int num=1,id;
	PolyNomial p;
	p=L;
	p=p->next;
	if(!deleteId){
		cout<<"你要删除第几个数据:";
		cin>>id;	
	}else{
		id=deleteId;
	}
	while(id > num && p){
		p=p->next;
		num++;
	}
	if(!p){
		cout<<"该节点不存在"<<endl;
	}else{
		p->pre->next=p->next;
		if(p->next){
			p->next->pre=p->pre;
		}
		//cout<<p->next;
		//cout<<p->pre;
		cout<<"删除数据为:"<<p->nodeData<<endl;
		//cout<<p->nodeData;
		//delete p;
		free(p);
	}
}
//去重
void nodList(PolyNomial &L){
	PolyNomial q, p,s;
	p=L;
	p=p->next;
	while(p){
		q=p->next;
		while(q){
			s=q->next;
			if(p->nodeData == q->nodeData){	
				q->pre->next=s;
				if(s){
					s->pre=q->pre;
				}
				delete q;
				//q->nodeData=NULL;
			}
			q=s;   
		}
		p=p->next;
	}
}
//数据展示
void printData(PolyNomial &L){
	int dataNum=0;
	PolyNomial q;
	q=L;
	while(q->next){
		cout<<q->next->nodeData<<endl;
		//if(q->pre){
			//printf("%d\n",q->pre->nodeData);
		//}
		q=q->next;
		dataNum++;
	}
	printf("数据输出完毕总量:%d\n",dataNum);
}
 
void main(){
	PolyNomial La;
	create(La);
	topInsert(La);
	footInsert(La);
	printData(La);
	delectNode(La,NULL);
	printData(La);
	nodList(La);
	printData(La);
}
