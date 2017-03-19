#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

//#define MAX_VERTEX_NUM 20
typedef int VertexType;
bool *visited;  //���ʱ�־����

typedef struct ArcBox{			//���ṹ��
	int headvex,tailvex;		//�û���ͷ��β�����λ��
	ArcBox *hlink,*tlink;		//��ͷ��ͬ����β��ͬ������
	int weight;
}ArcBox,*PolyNomial;

typedef struct VexNode{			//����ṹ��
	int data;
	int ver;
	ArcBox *firstin,*firstout;		//�ö���ĵ�һ���뻡�ͳ���
}VexNode,*VexNodePolyNomial;

typedef struct{
	VexNode *vex;			//��ͷ���
	//VexNode vex[MAX_VERTEX_NUM];		//��ͷ���
	int vexnum,arcnum;			//����ͼ�Ķ���ͻ���
}OLGraph;


//����
typedef struct listNode{
	VexNode data;
	struct listNode *next;
}listNode,*listPolyNomial;
typedef struct{
	listPolyNomial head;
	listPolyNomial foot;
}Linklist;
Linklist L;

//����ʮ������
void create(OLGraph &OL){
	int i,j;		//ѭ������
	int v1,v2,w;	//�м����-----ͷβ���㣬Ȩֵ
	int n=-1,m=-1;		//�м����-----ͷβ�����λ��
	int vexnum,arcnum;			//����ͼ�Ķ���ͻ���
	PolyNomial p;
	bool on_off = true;
	while(on_off){
		cout<<"����������ͼ�Ķ������ͻ���:";
		cin>>vexnum>>arcnum;
		if(arcnum > vexnum*(vexnum-1)){
			cout<<"�������ͻ��������߼����ٴ�����"<<endl;
		}else{
			on_off = false;
		}
	}
	
	OL.vexnum=vexnum;
	OL.arcnum=arcnum;
	
	//������������ռ�
	OL.vex = new VexNode[OL.vexnum];


	if(!OL.vex){
		cout<<"����ʧ�ܣ�"<<endl;
		return;
	}else{
			cout<<endl<<"�����ɹ�����ʼ��"<<endl<<endl;
	}
	for(i = 0; i < OL.vexnum; i++){
		int data;
		cout<<"�����"<<i+1<<"�������ֵ:";
		cin >> data;
		for(j = 0;j < OL.vexnum;j++){
			if(data == OL.vex[j].data) n = j;
		}
		if(n==-1){
			OL.vex[i].data = data;
			OL.vex[i].ver=i;
			OL.vex[i].firstin = OL.vex[i].firstout = NULL;
		}else{
			cout<<"�ڵ��Ѵ��ڣ��ٴ�����:"<<endl;
			i--;
		}
		n=-1;
	}
	for(i = 0;i < OL.arcnum;i++){
		cout << "�����"<<i+1<<"�ߵĻ�β�뻡ͷ��㼰Ȩֵ:" << endl;
		cin >> v1 >> v2 >> w;
		for(j = 0;j < OL.vexnum;j++){
			if(v1 == OL.vex[j].data) m = j;
			if(v2 == OL.vex[j].data) n = j;
		}
		if(m==-1){
			cout<<"��β�ڵ㲻���ڣ��ٴ�����:"<<endl;
			i--;
		}else if(n==-1){
			cout<<"��ͷ�ڵ㲻���ڣ��ٴ�����:"<<endl;
			i--;
		}else{
			p = new ArcBox;
			p->tailvex = m;
			p->headvex = n;
			p->weight = w;
			p->hlink = OL.vex[n].firstin;
			OL.vex[n].firstin = p;
			p->tlink = OL.vex[m].firstout;
			OL.vex[m].firstout = p;
		}
		m=n=-1;		//��ʼ����ͷ��βλ������
	}
}

//������ȱ���
void depthFirst(OLGraph OL,int v){
    PolyNomial p;
    visited[v]=true;
	cout<<OL.vex[v].data<<"  ";
    p=OL.vex[v].firstout;
    while (p!=NULL){
        if (!visited[p->headvex])
            depthFirst (OL, p->headvex);
        p=p->tlink;
    }
}

void initializeOL(OLGraph OL){
	cout<<"������ȱ���"<<endl;
	int v;
	for(v = 0; v < OL.vexnum; v++){
		visited[v] = false;
	}
	for(v = 0; v < OL.vexnum; v++){
		if(!visited[v]){
			depthFirst(OL,v);
		}
	}
	cout<<endl<<"������ȱ�������"<<endl;
}

//�Զ��еĲ���
void createlist(){
	L.head=L.foot=new listNode;
	L.head->next=NULL;
}
//����
void add(VexNode data){
	listPolyNomial p;
	p = new listNode;
	p->data=data;
	p->next=NULL;
	L.foot->next=p;
	L.foot=p;
}
//����
void pop(){
	listPolyNomial p;
	if(L.head!=L.foot){
		p=L.head->next;
		L.head->next=p->next;
		if(L.foot==p){
			L.head=L.foot;
		}
		delete(p);
	}
}


//������ȱ���
void breadthFirst(OLGraph OL){
	cout<<endl<<"������ȱ���"<<endl;
	for(int v = 0; v < OL.vexnum; v++){
		visited[v] = false;
	}
	
	VexNode node;
	PolyNomial p;
	createlist();
	int num=0;
	for(v = 0; v < OL.vexnum; v++){
		if(!visited[v]){
			add(OL.vex[v]);
			cout<<OL.vex[v].data<<"  ";
			visited[v] = true;
			num++;
			if(num == OL.vexnum){
				return;
			}
		}
		while(L.head!=L.foot){
			node = L.head->next->data;
			if(!visited[node.ver]){
				cout<<node.data<<"  ";
				visited[node.ver] = true;
				num++;
				if(num == OL.vexnum){
					return;
				}
			}
			p = node.firstout;
			while(p){
				if(!visited[OL.vex[p->headvex].ver]){
					add(OL.vex[p->headvex]);
					cout<<OL.vex[p->headvex].data<<"  ";
					visited[p->headvex] = true;
					num++;
					if(num == OL.vexnum){
						return;
					}
				}
				p = p->tlink;
			}
			pop();
		}
	}
	cout<<endl<<"������ȱ�������"<<endl;
}


void main(){
	OLGraph OL;
	cout<<"����ʮ������:"<<endl;
	create(OL);
	int option;//����ѡ��
	bool off_on=true;
	visited=(bool *)malloc(OL.vexnum*sizeof(bool));
	while(off_on){
		cout<<"\nѡ����� -----  1 : ������ȱ���;2 : ������ȱ���;3 : �˳�;"<<endl;
		cout<<"����ѡ��:";
		cin>>option;
		switch(option){
			case 1:
				initializeOL(OL);
				break;
			case 2:
				breadthFirst(OL);
				break;
			case 3:
				off_on=false;
				break;
			default:
				cout<<"���������ٴ�����"<<endl;
		}
	}
}