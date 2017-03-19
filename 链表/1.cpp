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

//ͷ�巨
void topInsert(PolyNomial &L){
	char data;
	cout<<"����������:";
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
		//���ɽڵ�����ַ�ʽ
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
//β�巨
void footInsert(PolyNomial &L){
	char data;
	cout<<"����������:";
	cin>>data;
	PolyNomial q,s;

	//���ɽڵ�����ַ�ʽ
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
//ɾ���ڵ�
void delectNode(PolyNomial &L,int deleteId){
	int num=1,id;
	PolyNomial p;
	p=L;
	p=p->next;
	if(!deleteId){
		cout<<"��Ҫɾ���ڼ�������:";
		cin>>id;	
	}else{
		id=deleteId;
	}
	while(id > num && p){
		p=p->next;
		num++;
	}
	if(!p){
		cout<<"�ýڵ㲻����"<<endl;
	}else{
		p->pre->next=p->next;
		if(p->next){
			p->next->pre=p->pre;
		}
		//cout<<p->next;
		//cout<<p->pre;
		cout<<"ɾ������Ϊ:"<<p->nodeData<<endl;
		//cout<<p->nodeData;
		//delete p;
		free(p);
	}
}
//ȥ��
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
//����չʾ
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
	printf("��������������:%d\n",dataNum);
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
