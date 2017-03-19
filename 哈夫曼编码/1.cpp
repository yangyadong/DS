#include<stdio.h>
#define n 5  //Ҷ����Ŀ
#define m (2*n-1)    //�������
#define maxval 10000.0
#define maxsize 100   //��������������λ��
typedef struct{
	char ch;
	float weight;
	int lchild,rchild,parent;
}hufmtree;
typedef struct{
	char bits[n];   //λ��
	int start;      //������λ���е���ʼλ��
	char ch;        //�ַ�
}codetype;

//������������
void huffman(hufmtree tree[]){
	int i,j,p1,p2;//p1,p2�ֱ��סÿ�κϲ�ʱȨֵ��С�ʹ�С�������������±�
	float small1,small2,f;
	char c;
	//��ʼ��
	for(i=0;i<m;i++){
		tree[i].parent=0;
		tree[i].lchild=-1;
		tree[i].rchild=-1;
		tree[i].weight=0.0;
	}
	printf("�����ζ���ǰ%d�������ַ���Ȩֵ(�м��ÿո����)��\n",n);
	//����ǰn�������ַ���Ȩֵ
	for(i=0;i<n;i++){
		printf("�����%d���ַ�Ϊ��Ȩֵ",i+1);
		scanf("%c %f",&c,&f);
		getchar();
		tree[i].ch=c;
		tree[i].weight=f;
	}
	//����n-1�κϲ�������n-1���½��
	for(i=n;i<m;i++){
		p1=0;p2=0;
		small1=maxval;small2=maxval;   //maxval��float���͵����ֵ
		for(j=0;j<i;j++)    //ѡ������Ȩֵ��С�ĸ����
		if(tree[j].parent==0)
		if(tree[j].weight<small1){
			small2=small1;  //�ı���СȨ����СȨ����Ӧ��λ��
			small1=tree[j].weight;
			p2=p1;
			p1=j;
		}else if(tree[j].weight<small2){
			small2=tree[j].weight;  //�ı��СȨ��λ��
			p2=j;
		}
		tree[p1].parent=i;
		tree[p2].parent=i;
		tree[i].lchild=p1;  //��СȨ��������½�������
		tree[i].rchild=p2;  //��СȨ��������½����Һ���
		tree[i].weight=tree[p1].weight+tree[p2].weight;
	}
}//huffman
//���ݹ��������������������
void huffmancode(codetype code[],hufmtree tree[]){
	int i,c,p;
	codetype cd;   //�������
	for(i=0;i<n;i++){
		cd.start=n;
		cd.ch=tree[i].ch;
		c=i;       //��Ҷ���������ϻ���
		p=tree[i].parent;   //tree[p]��tree[i]��˫��
		while(p!=0){
			cd.start--;
			if(tree[p].lchild==c)
				cd.bits[cd.start]='0';   //tree[i]�������������ɴ���'0'
			else
				cd.bits[cd.start]='1';   //tree[i]�������������ɴ���'1'
			c=p;
			p=tree[p].parent;
		}
		code[i]=cd;    //��i+1���ַ��ı������code[i]
	}
}//huffmancode
//���ζ�����ģ����ݹ�����������
void decode(hufmtree tree[]){
	int i,j=0;
	char b[maxsize];
	char endflag='2';    //���Ľ�����־ȡ2
	i=m-1;             //�Ӹ���㿪ʼ��������
	printf("���뷢�͵ı���(��'2'Ϊ������־)��");
	gets(b);
	printf("�������ַ�Ϊ");
	while(b[j]!='2'){
		if(b[j]=='0')
			i=tree[i].lchild;   //��������
		else
			i=tree[i].rchild;   //�����Һ���
		//tree[i]��Ҷ���
		if(tree[i].lchild==-1){
			printf("%c",tree[i].ch);
			i=m-1;      //�ص������
		}
		j++;
	}
	printf("\n");
	if(tree[i].lchild!=-1&&b[j]!='2')   //���Ķ��꣬����δ��Ҷ�ӽ��
	printf("\nERROR\n");  //��������д�
}//decode

void main(){
	printf("�������������롪��\n");
	printf("�ܹ���%d���ַ�\n",n);
	hufmtree tree[m];
	codetype code[n];
	int i,j;//ѭ������
	huffman(tree);//������������
	huffmancode(code,tree);//���ݹ��������������������
	printf("�����ÿ���ַ��Ĺ��������롿\n");
	for(i=0;i<n;i++){
		printf("%c: ",code[i].ch);
		for(j=code[i].start;j<n;j++)
		printf("%c ",code[i].bits[j]);
		printf("\n");
	}
	printf("��������ģ����������롿\n");
	decode(tree);//���ζ�����ģ����ݹ�����������
}