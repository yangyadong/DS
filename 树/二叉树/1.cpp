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
		cout<<"请输入"<<preData<<"的左节点:";
	}else if(l_r=='r'){
		cout<<"请输入"<<preData<<"的右节点:";
	}else{
		cout<<"请输入根节点(#代表该节点为空):";
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

//计算深度
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

//统计节点数
int nodeCount(pointer L){
	if(L){
		return nodeCount(L->lnext)+nodeCount(L->rnext)+1;
	}else{
		return 0;
	}
}

//首序遍历
void show1(pointer L){
	if(L){
		cout<<L->data;
		show1(L->lnext);
		show1(L->rnext);
	}
}

//中序遍历
void show2(pointer L,char preData,char l_r){
	if(L){
		show2(L->lnext,L->data,'l');
		if(l_r=='l'){
			cout<<preData<<"左节点为:";
		}else if(l_r=='r'){
			cout<<preData<<"右节点为:";
		}else{
			cout<<"根节点为:";
		}
		cout<<L->data<<endl;
		show2(L->rnext,L->data,'r');
	}
}

//后序遍历
void show3(pointer L){
	if(L != NULL){
		show3(L->lnext);
		show3(L->rnext);
		cout<<L->data;
	}
}

//复制
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
