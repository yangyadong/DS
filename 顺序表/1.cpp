#include<stdio.h>
#include<iostream.h>
#define OVERFLOW 1
#define OK 0
#define MAXSIZE 20
typedef int ElemType;

//���ֽṹ�嶨��
typedef struct Sqlist{
	int elem[MAXSIZE];
	int length;
}Sqlist_t;
//struct Sqlist{
//	int elem[MAXSIZE];
//	int length;
//};

//��ֵ
int listData(Sqlist &L){
	L.length = 0;
	int i,n;
	printf("�����������ܳ���:");
	scanf("%d",&n);
	fflush(stdin);
	while(n > MAXSIZE){
		printf("Խ�硢���������:");
		scanf("%d",&n);
		fflush(stdin);
	}
	for(i = 0; i < n; i++){
		L.elem[i] = i;
		L.length++;
	}
	return OK;
}
//�������
int addData(Sqlist &L){
	int id,i,data;
	printf("������Ҫ�����λ��:");
	cin>>id;
	while(id < 0 || id > L.length+1){
		printf("�����������������:");
		cin>>id;
	}
	if(L.length == MAXSIZE){
		printf("������\n");
		return OVERFLOW;
	}else{
		printf("������Ҫ���������:");
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
//ɾ��ĳλ������
int deleteData(Sqlist &L){
	int id,i;
	printf("������Ҫɾ���ڼ�������:");
	cin>>id;
	if(id < 0 || id > L.length){
		printf("��������:");
		return OVERFLOW;
	}else{
		for(i = id; i < L.length; i++){
			L.elem[i-1] = L.elem[i];
		}
		L.length--;
		return OK;
	}
}
//ȡ����
int selectData(Sqlist &L){
	int id,data;
	printf("������Ҫ��õڼ�������:");
	cin>>id;
	if(id < 0 || id > L.length){
		printf("��������:");
		return -1;
	}else{
		data = L.elem[id-1];
		return data;
	}
}
//ƥ������
int mateData(Sqlist &L){
	int data;
	cout<<"������Ҫƥ���ֵ:";
	cin>>data;
	for(int i = 0; i < L.length; i++){
		if(L.elem[i] == data){
			printf("��һ�γ�����%d��λ��\n",i+1);
			return OK;
			break;
		}
	}
	cout<<"ƥ������\n";
	return OVERFLOW;
}
//չʾ������
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
	printf("��õ�����Ϊ:%d\n",res);
	mateData(La);
	//Sqlist Lb;
	//listData(Lb);
}