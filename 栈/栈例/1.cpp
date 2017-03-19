#include<stdio.h>
#include<stdlib.h>

#define STACKINCRESE 100
#define STACK_IN 10
typedef struct
{
    char *base;
    char *top;
    int stacksize;
}SqStack;

void Initstack(SqStack &s)
{
    s.base=(char*)malloc(STACK_IN * sizeof(char));
    if(!s.base) exit(1);
    s.top=s.base;
    s.stacksize=STACK_IN;
}

char Gettop(SqStack &s,char e)
{
    e=*(s.top-1);
    return e;
}

void Push(SqStack &s,char e)
{
    if((s.top-s.base)>s.stacksize)
    {
        s.base=(char *)realloc(s.base,(s.stacksize+STACKINCRESE)*sizeof(char));
        if(!s.base)  exit(1);
        s.top=s.base+s.stacksize;
        s.stacksize=s.stacksize+STACKINCRESE;
    }
    *s.top++=e;
}

void Pop(SqStack &s,char e)
{
     if(s.base==s.top) exit(1);
     e=*--s.top;
}

int main(void)
{
    SqStack s;
    Initstack(s);
    char a,e;
    scanf("%c",&a);
    Push(s,a);
    scanf("%c",&e);
    while(a!='#')
    {
        switch(a)
        {
          case']':
          {
              if(Gettop(s,e)!='[')
              {
                  Push(s,a);
              }
              else Pop(s,e);
              break;
          }
          case')':
          {
              if(Gettop(s,e)!='(')
              {
                  Push(s,a);
              }
              else Pop(s,e);
              break;
          }
          case'}':
          {
              if(Gettop(s,e)!='{')
              {
                  Push(s,a);
              }
              else Pop(s,e);
              break;
          }
          case'[':case'{':case'(':
          {
              Push(s,a);
              break;
          }
      }
      scanf("%c",&a);
    }
    if(s.base==s.top) printf("∆•≈‰");
    else  printf("≤ª∆•≈‰");
    return 0;
}