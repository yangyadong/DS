#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)

/*----------------���ݶ���----------------------*/ 

//����һ��ѧ����Ϣ�Ľṹ��,����ѧ��,�����ͽṹ�����͵�ָ�� 
struct student
{
    long num;                //ѧ�� 
    char name[128];            //���� 
    struct student *next;    //�ṹ��ָ�� 
};

typedef struct student * stuNode;

int n=0;                    //ȫ�ֱ���,��¼����ĳ��� 
 
/*---------------��������---------------------*/
 
stuNode Create();            //����һ���µ�����                     

void Print(stuNode head);    //ͨ�����������ͷָ���ӡ�������� 

stuNode Delete(stuNode head,int num);    //ͨ�����������ͷָ���ѧ��ѧ��ɾ���ڵ� 

stuNode Insert(stuNode head,stuNode newStu);    //����ѧ��ѧ�ŵ�˳���������в�����Ԫ�� 


/*---------------��������----------------------*/

struct student *Create()
{
    struct student *head,*p1,*p2;
    
    //����һ��LEN��С�Ŀռ�,����p1,p2ָ��ָ���� 
    p2=p1=(struct student *)malloc(LEN);
    //��ͷָ����ΪNULL 
    head=NULL;
    
    //��������ڵ㲢���ڵ��Ԫ�ظ�ֵ 
    printf("������ѧ����ѧ�ź�����:");
    scanf("%ld %s",&p1->num,p1->name);
    while(p1->num!=0)
    {
        n=n+1;
        if(NULL==head)
        {
            head=p1;
        }
        else
        {
            p2->next=p1;
        }
        p2=p1;
        p1=(struct student *)malloc(LEN);
        printf("������ѧ����ѧ�ź�����:");
        scanf("%ld %s",&p1->num,p1->name);
    }
    //��β�ڵ��ָ����ΪNULL 
    p2->next=NULL;
    return head;
}


void Print(struct student *head)
{
    struct student * p;
    p=head;
    
    //�ж������Ƿ�Ϊ�� 
    if(NULL==head)
    {
        printf("����Ϊ��!\n");
        //return head;
    }
    else
    {
        //ѭ����ӡ�����е�Ԫ�� 
        printf("%d ����¼�ֱ�Ϊ:\n",n);
        while(p!=NULL)
        {
            printf("%ld %s\n",p->num,p->name);
            //ָ��ָ����һ���ڵ� 
            p=p->next;
        }
    }
}


struct student *Delete(struct student * head,int num)
{
    struct student *p1;
    struct student *p2;
    p1=head;
    //�ж������Ƿ�Ϊ�� 
    if(NULL==head)
    {
        printf("����Ϊ��!\n");
        return head;
    }
    //�����ڵ�,�жϵ�ǰ�ڵ��ǲ�����Ҫɾ���Ľڵ㼰�Ƿ�Ϊβ�ڵ�
    //����ҵ���Ӧ�ڵ�,�����Ѿ�������β�ڵ������ѭ�� 
    while(p1->num!=num&&p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    //�ж��Ƿ��ҵ���Ӧ�ڵ� 
    if(p1->num==num)
    {
        //Ҫɾ���Ľڵ��ǲ�������ĵ�һ���ڵ�
        //�����,�ͽ�ͷָ��ָ��ýڵ�ĺ�һ���ڵ�
        //�������,�ͽ��ýڵ��ǰһ���ڵ��ָ��ָ��ýڵ�ĺ�һ���ڵ� 
        if(head==p1)
        {
            head=p1->next;
        }
        else
        {
            p2->next=p1->next;
        }
        n=n-1;
        printf("%ld �ڵ���ɾ��.\n",num);
    }
    else
    {
        printf("������û��Ҫɾ����Ԫ��.\n");
    }
    return head;
}


struct student *Insert(struct student * head,struct student * newStu)
{
    struct student *p0;
    struct student *p1;
    struct student *p2;
    p0=newStu;
    p1=head;
    //�ж������Ƿ�Ϊ��,����ǿ�����,�ͽ��½ڵ���Ϊ��һ���ڵ� 
    if(NULL==head)
    {
        head=p0;
        p0->next=NULL;
    }
    else
    {
        //����ÿһ���ڵ��е�ѧ��,����ѧ�űȽϴ�С
        //����ҵ�һ��ѧ�ű���ѧ�Ŵ�,�ͽ���ѧ�ŵĽڵ������֮ǰ 
        //���β�ڵ��ѧ���Ա���ѧ��С,�ͽ��½ڵ���뵽����β�� 
        while((p0->num > p1->num)&&(p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        //�ҵ�һ������ѧ�Ŵ�Ľڵ� 
        if(p0->num <= p1->num)
        {
            //�жϸýڵ��Ƿ�Ϊͷ�ڵ�,�����,���½ڵ�����Ϊͷ�ڵ� 
            if(p1==head)
            {
                head=p0;
            }
            else
            {
                p2->next=p0;
            }
              p0->next=p1;
        }
        else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    //�����ȼ�1 
    n=n+1;
    printf("%ld ����ɹ�!\n",newStu->num);
    return head;
}

void main()
{
    struct student *head;
    struct student *stu;
    int num;
    head=Create();
    Print(head);
    printf("������Ҫɾ����ѧ��:");
    scanf("%ld",&num);
    while(num!=0)
    {
        head=Delete(head,num);
        Print(head);
        printf("������Ҫɾ����ѧ��:");
        scanf("%ld",&num);
    }
    printf("������Ҫ����Ľڵ�:");
    stu=(struct student *)malloc(LEN);
    scanf("%ld %s",&stu->num,stu->name);
    while(stu->num!=0)
    {
        head=Insert(head,stu);
        printf("������Ҫ����Ľڵ�:");
        stu=(struct student *)malloc(LEN);
        scanf("%ld %s",&stu->num,stu->name);
    }
    Print(head);
}