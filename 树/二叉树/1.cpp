#include<stdio.h>
#include<iostream.h>

typedef struct node{
	char data;
	struct node *lnext;
	struct node *rnext;
}node,*pointer;

void addnode(pointer &L,char preData,char l_r){
	char data;
	if(l_r=='l'){
		cout<<"������"<<preData<<"����ڵ�:";
	}else if(l_r=='r'){
		cout<<"������"<<preData<<"���ҽڵ�:";
	}else{
		cout<<"��������ڵ�(#����ýڵ�Ϊ��):";
	}
	cin>>data;
	if(data=='#'){
		L=NULL;
	}else{
		L=new node;
		L->data=data;
		addnode(L->lnext,data,'l');
		addnode(L->rnext,data,'r');
	}
}

//�������
int depth(pointer L){
	if(!L){
		return 0;
	}else{
		int m=depth(L->lnext);
		int n=depth(L->rnext);
		if(m>n){
			return m+1;
		}else{
			return n+1;
		}
	}
}

//ͳ�ƽڵ���
int nodeCount(pointer L){
	if(L){
		return nodeCount(L->lnext)+nodeCount(L->rnext)+1;
	}else{
		return 0;
	}
}

//�������
void show1(pointer L){
	if(L){
		cout<<L->data;
		show1(L->lnext);
		show1(L->rnext);
	}
}

//�������
void show2(pointer L,char preData,char l_r){
	if(L){
		show2(L->lnext,L->data,'l');
		if(l_r=='l'){
			cout<<preData<<"��ڵ�Ϊ:";
		}else if(l_r=='r'){
			cout<<preData<<"�ҽڵ�Ϊ:";
		}else{
			cout<<"���ڵ�Ϊ:";
		}
		cout<<L->data<<endl;
		show2(L->rnext,L->data,'r');
	}
}

//�������
void show3(pointer L){
	if(L != NULL){
		show3(L->lnext);
		show3(L->rnext);
		cout<<L->data;
	}
}

//����
void copy(pointer L,pointer &newL){
	if(L==NULL){
		newL=NULL;
	}else{
		newL=new node;
		newL->data=L->data;
		copy(L->lnext,newL->lnext);
		copy(L->rnext,newL->rnext);
	}
}

void main(){
	pointer L,newL;
	addnode(L,NULL,NULL);
	show2(L,NULL,NULL);
	copy(L,newL);
	show1(L);
	cout<<endl;
	show3(L);
	cout<<endl;
	cout<<depth(L)<<endl;
	cout<<nodeCount(L)<<endl;
}
