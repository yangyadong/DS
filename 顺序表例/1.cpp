#include<stdio.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int length;
}SqList;//顺序表结构定义
void InitList(SqList &L)
{
    //初始化函数
    //操作结果：构造一个空在顺序线性表
    L.length=0;
    return;
}
int ListLength(SqList L)
{
    //求表长函数
    //操作结果：返回表中元素个数
    return L.length;
}
int ListEmpty(SqList L)
{
    //判空函数
    //初始条件：顺序线性表L已存在
    //操作结果：如果不空返回0，否则返回非0值
    if(L.length==0)
		return 1;
    else
        return 0;
}
/////////////////////////////
int GetElem(SqList L,int i,ElemType &e)
{
    //取元素函数
    //初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
    //操作结果：用e返回L中第i个元素的值
    if(i<1||i>L.length)
    {
        printf("i值越界！\n");
        return 0;
    }
    e=L.elem[i-1];
    return 1;
}
int LocateElem(SqList L,ElemType e)
{
    //定位函数
    //初始条件：顺序线性表L已存在，e为指定的查找元素
    //操作结果：返回L中第1个与e相等的元素位序，若这样在元素不存在，则返回0
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
    //求前驱函数
    //初始条件：顺序表已存在
    //操作结果：若存在元素cur_e，且是第一个元素，返回0;若不是第一个元素，则返回前驱元素的值
    int i;
    i=LocateElem(L,cur_e);
    if(i)
    {
        if(i==1)
        {
            printf("这是第一个元素，没有前驱！！！\n");
            return 0;//操作失败
        }
        else
        {
            pre_e=L.elem[i-1];
            return 1;
        }
    }
    else
    {
        printf("中不存在此元素！\n");
        return 0;//操作失败
    }
}
int NextElem(SqList L,ElemType cur_e,ElemType &next_e)
{
    //求后继函数
    //初始条件：顺序表已存在
    //操作结果：若存在元素cur_e，且是最后一个元素，返回0;若不是最后一个元素，则返回后继元素的值
    int i;
    i=LocateElem(L,cur_e);
    if(i)
    {
        if(i==L.length-1)
        {
            printf("这是最后一个元素，没有后继！！！\n");
            return 0;//操作失败
        }
        else
        {
            next_e=L.elem[i+1];
            return 1;
        }
    }
    else
    {
        printf("不存在此元素！\n");
        return 0;//操作失败
    }
}

int ListInsert(SqList &L,int i,ElemType e)
{
    //插入函数
    //初始条件：顺序线性表L已存在，1<=i<=ListLength(L)+1
    //操作结果：在L中第i个位置前插入新的数据元素e，L的长度加1
    int j;
    if(i<1||i>L.length+1)
    {
        printf("插入越界！\n");
        return 0;//插入失败
    }
    if(L.length>=MAXSIZE)
    {
        printf("顺序上溢！\n");
        return 0;//插入失败
    }
    for(j=L.length-1;j>=i-1;--j)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    ++L.length;
    return 1;//成功插入
}
int ListDelete(SqList &L,int i,ElemType &e)
{
    int j;
    if(i<1||i>L.length)
    {
        printf("i值越界！");
        return 0;//操作失败
    }
    if(ListEmpty(L))
    {
        printf("L为空表，不能执行删除操作！\n");
        return 0;//操作失败
    }
    e=L.elem[i-1];
    for(j=i;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
    return 1;//操作成功
}//
void ListTraverse(SqList L)
{
    //输出函数
    //初始条件：顺序表衣襟存在
    //操作结果：若顺序表非空，则输出顺序表中所有元素，否则为空操作
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
    InitList(L);/////////创建一个空的顺序表L
    if(ListEmpty(L))
    {
        printf("顺序表L是一个空表！\n");
    }
    else
    {
        printf("顺序表L不是一个空表！\n");
    }
    ///////////////////////////////////////////////////if语句的输出结果为：
    printf("\n1~10:\n");
    for(i=1;i<=10;i++)
    {
        ListInsert(L,1,i);///////调用插入函数
    }
    ListTraverse(L);///////////////////////////////////输出结果为：
    printf("\n删除指定的元素（输入序号）：");
    scanf("%d",&i);
    ListDelete(L,i,e);
    printf("\n删除的第%d个元素的值为%d\n",i,e);
    printf("\n删除后元素后顺序表中的元素值为：\n");
    ListTraverse(L);
    printf("\n查找前驱操作：\n");
    printf("\n输入元素：");
    scanf("%d",&s);
    if(!PriorElem(L,s,e))
    {
        printf("\n元素%d没有前驱！\n",s);
    }
    else
    {
        printf("\n元素%d的前驱为：%d\n",s,e);
    }
    printf("\n查找后继元素操作：\n");
    printf("\n输入元素：\n");
    scanf("%d",&s);
    if(!NextElem(L,s,e))
    {
        printf("\n元素%d没有后继！\n",s);
    }
    else
    {
        printf("\n元素%d的后继为：%d\n",s,e);
    }
    printf("\n");
    return 0;
}