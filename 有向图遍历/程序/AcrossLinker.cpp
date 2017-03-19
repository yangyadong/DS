#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

//#define MAX_VERTEX_NUM 20
typedef int VertexType;
bool *visited;  //访问标志数组

typedef struct ArcBox{			//弧结构体
	int headvex,tailvex;		//该弧的头和尾顶点的位置
	ArcBox *hlink,*tlink;		//弧头相同，弧尾相同的链域
	int weight;
}ArcBox,*PolyNomial;

typedef struct VexNode{			//顶点结构体
	int data;
	int ver;
	ArcBox *firstin,*firstout;		//该顶点的第一条入弧和出弧
}VexNode,*VexNodePolyNomial;

typedef struct{
	VexNode *vex;			//表头结点
	//VexNode vex[MAX_VERTEX_NUM];		//表头结点
	int vexnum,arcnum;			//有向图的顶点和弧数
}OLGraph;


//队列
typedef struct listNode{
	VexNode data;
	struct listNode *next;
}listNode,*listPolyNomial;
typedef struct{
	listPolyNomial head;
	listPolyNomial foot;
}Linklist;
Linklist L;

//创建十字链表
void create(OLGraph &OL){
	int i,j;		//循环变量
	int v1,v2,w;	//中间变量-----头尾顶点，权值
	int n=-1,m=-1;		//中间变量-----头尾顶点的位置
	int vexnum,arcnum;			//有向图的顶点和弧数
	PolyNomial p;
	bool on_off = true;
	while(on_off){
		cout<<"请输入有向图的顶点数和弧数:";
		cin>>vexnum>>arcnum;
		if(arcnum > vexnum*(vexnum-1)){
			cout<<"顶点数和弧数不符逻辑！再次输入"<<endl;
		}else{
			on_off = false;
		}
	}
	
	OL.vexnum=vexnum;
	OL.arcnum=arcnum;
	
	//按顶点数分配空间
	OL.vex = new VexNode[OL.vexnum];


	if(!OL.vex){
		cout<<"创建失败！"<<endl;
		return;
	}else{
			cout<<endl<<"创建成功！初始化"<<endl<<endl;
	}
	for(i = 0; i < OL.vexnum; i++){
		int data;
		cout<<"输入第"<<i+1<<"个顶点的值:";
		cin >> data;
		for(j = 0;j < OL.vexnum;j++){
			if(data == OL.vex[j].data) n = j;
		}
		if(n==-1){
			OL.vex[i].data = data;
			OL.vex[i].ver=i;
			OL.vex[i].firstin = OL.vex[i].firstout = NULL;
		}else{
			cout<<"节点已存在！再次输入:"<<endl;
			i--;
		}
		n=-1;
	}
	for(i = 0;i < OL.arcnum;i++){
		cout << "输入第"<<i+1<<"边的弧尾与弧头结点及权值:" << endl;
		cin >> v1 >> v2 >> w;
		for(j = 0;j < OL.vexnum;j++){
			if(v1 == OL.vex[j].data) m = j;
			if(v2 == OL.vex[j].data) n = j;
		}
		if(m==-1){
			cout<<"弧尾节点不存在！再次输入:"<<endl;
			i--;
		}else if(n==-1){
			cout<<"弧头节点不存在！再次输入:"<<endl;
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
		m=n=-1;		//初始化弧头弧尾位置坐标
	}
}

//深度优先遍历
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
	cout<<"深度优先遍历"<<endl;
	int v;
	for(v = 0; v < OL.vexnum; v++){
		visited[v] = false;
	}
	for(v = 0; v < OL.vexnum; v++){
		if(!visited[v]){
			depthFirst(OL,v);
		}
	}
	cout<<endl<<"深度优先遍历结束"<<endl;
}

//对队列的操作
void createlist(){
	L.head=L.foot=new listNode;
	L.head->next=NULL;
}
//进队
void add(VexNode data){
	listPolyNomial p;
	p = new listNode;
	p->data=data;
	p->next=NULL;
	L.foot->next=p;
	L.foot=p;
}
//出对
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


//广度优先遍历
void breadthFirst(OLGraph OL){
	cout<<endl<<"广度优先遍历"<<endl;
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
	cout<<endl<<"广度优先遍历结束"<<endl;
}


void main(){
	OLGraph OL;
	cout<<"创建十字链表:"<<endl;
	create(OL);
	int option;//操作选项
	bool off_on=true;
	visited=(bool *)malloc(OL.vexnum*sizeof(bool));
	while(off_on){
		cout<<"\n选项操作 -----  1 : 深度优先遍历;2 : 广度优先遍历;3 : 退出;"<<endl;
		cout<<"输入选项:";
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
				cout<<"输入有误！再次输入"<<endl;
		}
	}
}