#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>

typedef struct node{
	struct node *lnext;
	struct node *rnext;
	int l,r;
	char data;
}*pointer;
pointer pre=NULL;

void addNode(pointer &L,char preData,char l_r){
	char addData;
	if(l_r=='l'){
		cout<<"请输入"<<preData<<"左节点:";
	}else{
		cout<<"请输入"<<preData<<"右节点:";
	}
	cin>>addData;
	if(addData!='#'){
		L=new node;
		L->data=addData;
		addNode(L->lnext,L->data,'l');
		addNode(L->rnext,L->data,'r');
	}else{
		L=NULL;
	}
}

void create(pointer &L){
	char data;
	cout<<"请输入根节点(#代表为空):";
	cin>>data;
	if(data!='#'){
		L = new node;
		L->data=data;
		addNode(L->lnext,L->data,'l');
		addNode(L->rnext,L->data,'r');
	}else{
		L=NULL;
	}
}


//线索化
void clue(pointer &L){
	if(L){
		clue(L->lnext);
		if(!L->lnext){
			L->l=1;
			L->lnext=pre;
		}else{
			L->l=0;
		}
		if(!pre->rnext){
			pre->r=1;
			pre->rnext=L;
		}else{
			pre->r=0;
		}
		pre = L;
		clue(L->rnext);
	}
}

void topNodeClue(pointer &T,pointer L){
	T = new node;
	T->l=0;
	T->r=1;
	T->rnext=T;
	if(!L){
		T->lnext=T;
	}else{
		T->lnext=L;
		pre = T;
		clue(L);
		pre->rnext=T;
		pre->r=1;
		T->rnext=pre;
	}
}


void show(pointer L){
	if(L){
		show(L->lnext);
		cout<<L->data;
		show(L->rnext);
	}
}

void show1(pointer T){
	pointer p=T->lnext;
	while(p!=T){
		while(p->l==0){
			p=p->lnext;
		}
		cout<<p->data;
		while(p->r==1&&p->rnext!=T){
			p=p->rnext;
			cout<<p->data;
		}
		p=p->rnext;
	}
}

void main(){
	pointer L,T;		//T表示头结点
	create(L);
	show(L);
	cout<<endl;
	topNodeClue(T,L);
	show1(T);
	cout<<endl;
}
