#include<stdio.h>
#include<iostream.h>
#define OVERFLOW 1
#define OK 0
#define MAXSIZE 20
typedef int ElemType;

//两种结构体定义
typedef struct Sqlist{
	int elem[MAXSIZE];
	int length;
}Sqlist_t;
//struct Sqlist{
//	int elem[MAXSIZE];
//	int length;
//};

//表赋值
int listData(Sqlist &L){
	L.length = 0;
	int i,n;
	printf("请输入数据总长度:");
	scanf("%d",&n);
	fflush(stdin);
	while(n > MAXSIZE){
		printf("越界、请从新输入:");
		scanf("%d",&n);
		fflush(stdin);
	}
	for(i = 0; i < n; i++){
		L.elem[i] = i;
		L.length++;
	}
	return OK;
}
//添加数据
int addData(Sqlist &L){
	int id,i,data;
	printf("请输入要插入的位置:");
	cin>>id;
	while(id < 0 || id > L.length+1){
		printf("输入有误、请从新输入:");
		cin>>id;
	}
	if(L.length == MAXSIZE){
		printf("表已满\n");
		return OVERFLOW;
	}else{
		printf("请输入要插入的整数:");
		cin>>data;
		//if(){
			
		//}
		for(i = L.length-1; i >= id-1; i--){
			L.elem[i+1] = L.elem[i];
		}
		L.elem[id-1] = data;
		L.length++;
		return OK;
	}
}
//删除某位置数据
int deleteData(Sqlist &L){
	int id,i;
	printf("请输入要删除第几个数据:");
	cin>>id;
	if(id < 0 || id > L.length){
		printf("输入有误:");
		return OVERFLOW;
	}else{
		for(i = id; i < L.length; i++){
			L.elem[i-1] = L.elem[i];
		}
		L.length--;
		return OK;
	}
}
//取数据
int selectData(Sqlist &L){
	int id,data;
	printf("请输入要获得第几个数据:");
	cin>>id;
	if(id < 0 || id > L.length){
		printf("输入有误:");
		return -1;
	}else{
		data = L.elem[id-1];
		return data;
	}
}
//匹配数据
int mateData(Sqlist &L){
	int data;
	cout<<"请输入要匹配的值:";
	cin>>data;
	for(int i = 0; i < L.length; i++){
		if(L.elem[i] == data){
			printf("第一次出现在%d个位置\n",i+1);
			return OK;
			break;
		}
	}
	cout<<"匹配有误\n";
	return OVERFLOW;
}
//展示表数据
int listPrintf(Sqlist &L){
	for(int i = 0; i < L.length; i++){
		printf("%d\n",L.elem[i]);
	}
	return 0;
}
void main(){
	Sqlist La;
	listData(La);
	listPrintf(La);
	//addData(La);
	//listPrintf(La);
	deleteData(La);
	listPrintf(La);
	int res = selectData(La);
	printf("获得的数据为:%d\n",res);
	mateData(La);
	//Sqlist Lb;
	//listData(Lb);
}