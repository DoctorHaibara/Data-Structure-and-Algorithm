#include<bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct polynode
{
    float coef;  //系数
    int expn;    //指数
    struct polynode *next;
}polynode,*polylist;

int s=1;
void poly_create(polylist &L) //多项式链表创建
{
    int m;
    printf("请输入第 %d 个一元多项式项数：",s);
    scanf("%d",&m);
    L=(polylist)malloc(sizeof(polynode)); //申请头节点指针
    polylist p;
    p=L;
    for(int i=1;i<=m;i++)
    {
        p->next=(polylist)malloc(sizeof(polynode)); //不断申请
        p=p->next;
        printf("请输入第 %d 项的系数：",i);
        scanf("%f",&p->coef);
        printf("请输入第 %d 项的指数：",i);
        scanf("%d",&p->expn);
    }
    p->next=NULL;
}

void display(polylist L) //打印多项式
{
    polylist p;
    p=L->next;
    if(!p){
	 printf("0\n");
	 return;
    } 
    printf("%.0fx(%d)",p->coef,p->expn);
    p=p->next;
    while(p!=NULL)
    {
        if(p->coef>0)
        {
            printf("+%.0fx(%d)",p->coef,p->expn);
        }
        else
        {
            printf("%.0fx(%d)",p->coef,p->expn);
        }
        p=p->next;
    }
    printf("\n");
}

void add(polylist La, polylist Lb, polylist &Lc)
{
    //Your code here
    Lc=(polylist)malloc(sizeof(polynode));
    Lc->next=NULL;
    polylist pa=La->next;
    polylist pb=Lb->next;
    polylist pc=Lc;
    while(pa&&pb){
        if (pa->expn<pb->expn){
		
            pc->next=(polylist)malloc(sizeof(polynode));
            pc=pc->next;
            pc->coef=pa->coef;
            pc->expn=pa->expn;
            pa=pa->next;
        }
        else if(pa->expn>pb->expn){
            pc->next=(polylist)malloc(sizeof(polynode));
            pc=pc->next;
            pc->coef=pb->coef;
            pc->expn=pb->expn;
            pb=pb->next;
        }
        else{
            if (pa->coef+pb->coef!=0){
                pc->next=(polylist)malloc(sizeof(polynode));
                pc=pc->next;
                pc->coef=pa->coef+pb->coef;
                pc->expn=pa->expn ;
            }
            pa=pa->next ;
            pb=pb->next;
        }
    }
    while(pa){
        pc->next=(polylist)malloc(sizeof(polynode)) ;
        pc=pc->next;
        pc->coef=pa->coef;
        pc->expn=pa->expn;
        pa=pa->next;
    }
    while(pb){
        pc->next=(polylist)malloc(sizeof(polynode)) ;
        pc=pc->next;
        pc->coef=pb->coef ;
        pc->expn=pb->expn;
        pb=pb->next;
    }
    pc->next=NULL;
}

void subtract(polylist La,polylist Lb,polylist &Lc)
{
    //Your code here
    Lc=(polylist)malloc(sizeof(polynode));
    Lc->next=NULL;
    polylist pa=La->next;
    polylist pb=Lb->next;
    polylist pc=Lc;
    while(pa&&pb){
        if (pa->expn<pb->expn){
		
            pc->next=(polylist)malloc(sizeof(polynode));
            pc=pc->next;
            pc->coef=pa->coef;
            pc->expn=pa->expn;
            pa=pa->next;
        }
        else if(pa->expn>pb->expn){
            pc->next=(polylist)malloc(sizeof(polynode));
            pc=pc->next;
            pc->coef=-pb->coef;
            pc->expn=pb->expn;
            pb=pb->next;
        }
        else{
            if (pa->coef-pb->coef!=0){
                pc->next=(polylist)malloc(sizeof(polynode));
                pc=pc->next;
                pc->coef=pa->coef-pb->coef;
                pc->expn=pa->expn ;
            }
            pa=pa->next ;
            pb=pb->next;
        }
    }
    while(pa){
        pc->next=(polylist)malloc(sizeof(polynode)) ;
        pc=pc->next;
        pc->coef=pa->coef;
        pc->expn=pa->expn;
        pa=pa->next;
    }
    while(pb){
        pc->next=(polylist)malloc(sizeof(polynode)) ;
        pc=pc->next;
        pc->coef=-pb->coef ;
        pc->expn=pb->expn;
        pb=pb->next;
    }
    pc->next=NULL;
}

int main()
{
    polylist La,Lb,Lc,Ld;
    poly_create(La);
    s++;
    poly_create(Lb);
    printf("一元多项式1：");
    display(La);
    printf("一元多项式2：");
    display(Lb);
    add(La,Lb,Lc);
    printf("加的结果：");
    display(Lc);
    subtract(La,Lb,Ld);
    printf("减的结果: ");
    display(Ld);
    return 0;
}

