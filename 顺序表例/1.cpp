#include<stdio.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int length;
}SqList;//˳���ṹ����
void InitList(SqList &L)
{
    //��ʼ������
    //�������������һ������˳�����Ա�
    L.length=0;
    return;
}
int ListLength(SqList L)
{
    //�������
    //������������ر���Ԫ�ظ���
    return L.length;
}
int ListEmpty(SqList L)
{
    //�пպ���
    //��ʼ������˳�����Ա�L�Ѵ���
    //���������������շ���0�����򷵻ط�0ֵ
    if(L.length==0)
		return 1;
    else
        return 0;
}
/////////////////////////////
int GetElem(SqList L,int i,ElemType &e)
{
    //ȡԪ�غ���
    //��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
    //�����������e����L�е�i��Ԫ�ص�ֵ
    if(i<1||i>L.length)
    {
        printf("iֵԽ�磡\n");
        return 0;
    }
    e=L.elem[i-1];
    return 1;
}
int LocateElem(SqList L,ElemType e)
{
    //��λ����
    //��ʼ������˳�����Ա�L�Ѵ��ڣ�eΪָ���Ĳ���Ԫ��
    //�������������L�е�1����e��ȵ�Ԫ��λ����������Ԫ�ز����ڣ��򷵻�0
    int i=0;
    while(i<L.length&&L.elem[i]!=e)
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}
int PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
{
    //��ǰ������
    //��ʼ������˳����Ѵ���
    //���������������Ԫ��cur_e�����ǵ�һ��Ԫ�أ�����0;�����ǵ�һ��Ԫ�أ��򷵻�ǰ��Ԫ�ص�ֵ
    int i;
    i=LocateElem(L,cur_e);
    if(i)
    {
        if(i==1)
        {
            printf("���ǵ�һ��Ԫ�أ�û��ǰ��������\n");
            return 0;//����ʧ��
        }
        else
        {
            pre_e=L.elem[i-1];
            return 1;
        }
    }
    else
    {
        printf("�в����ڴ�Ԫ�أ�\n");
        return 0;//����ʧ��
    }
}
int NextElem(SqList L,ElemType cur_e,ElemType &next_e)
{
    //���̺���
    //��ʼ������˳����Ѵ���
    //���������������Ԫ��cur_e���������һ��Ԫ�أ�����0;���������һ��Ԫ�أ��򷵻غ��Ԫ�ص�ֵ
    int i;
    i=LocateElem(L,cur_e);
    if(i)
    {
        if(i==L.length-1)
        {
            printf("�������һ��Ԫ�أ�û�к�̣�����\n");
            return 0;//����ʧ��
        }
        else
        {
            next_e=L.elem[i+1];
            return 1;
        }
    }
    else
    {
        printf("�����ڴ�Ԫ�أ�\n");
        return 0;//����ʧ��
    }
}

int ListInsert(SqList &L,int i,ElemType e)
{
    //���뺯��
    //��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1
    //�����������L�е�i��λ��ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
    int j;
    if(i<1||i>L.length+1)
    {
        printf("����Խ�磡\n");
        return 0;//����ʧ��
    }
    if(L.length>=MAXSIZE)
    {
        printf("˳�����磡\n");
        return 0;//����ʧ��
    }
    for(j=L.length-1;j>=i-1;--j)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    ++L.length;
    return 1;//�ɹ�����
}
int ListDelete(SqList &L,int i,ElemType &e)
{
    int j;
    if(i<1||i>L.length)
    {
        printf("iֵԽ�磡");
        return 0;//����ʧ��
    }
    if(ListEmpty(L))
    {
        printf("LΪ�ձ�����ִ��ɾ��������\n");
        return 0;//����ʧ��
    }
    e=L.elem[i-1];
    for(j=i;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
    return 1;//�����ɹ�
}//
void ListTraverse(SqList L)
{
    //�������
    //��ʼ������˳����½����
    //�����������˳���ǿգ������˳���������Ԫ�أ�����Ϊ�ղ���
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%5d",L.elem[i]);
    }
    return;
}

int main(void)
{
    SqList L;
    int i,s,e;
    InitList(L);/////////����һ���յ�˳���L
    if(ListEmpty(L))
    {
        printf("˳���L��һ���ձ�\n");
    }
    else
    {
        printf("˳���L����һ���ձ�\n");
    }
    ///////////////////////////////////////////////////if����������Ϊ��
    printf("\n1~10:\n");
    for(i=1;i<=10;i++)
    {
        ListInsert(L,1,i);///////���ò��뺯��
    }
    ListTraverse(L);///////////////////////////////////������Ϊ��
    printf("\nɾ��ָ����Ԫ�أ�������ţ���");
    scanf("%d",&i);
    ListDelete(L,i,e);
    printf("\nɾ���ĵ�%d��Ԫ�ص�ֵΪ%d\n",i,e);
    printf("\nɾ����Ԫ�غ�˳����е�Ԫ��ֵΪ��\n");
    ListTraverse(L);
    printf("\n����ǰ��������\n");
    printf("\n����Ԫ�أ�");
    scanf("%d",&s);
    if(!PriorElem(L,s,e))
    {
        printf("\nԪ��%dû��ǰ����\n",s);
    }
    else
    {
        printf("\nԪ��%d��ǰ��Ϊ��%d\n",s,e);
    }
    printf("\n���Һ��Ԫ�ز�����\n");
    printf("\n����Ԫ�أ�\n");
    scanf("%d",&s);
    if(!NextElem(L,s,e))
    {
        printf("\nԪ��%dû�к�̣�\n",s);
    }
    else
    {
        printf("\nԪ��%d�ĺ��Ϊ��%d\n",s,e);
    }
    printf("\n");
    return 0;
}