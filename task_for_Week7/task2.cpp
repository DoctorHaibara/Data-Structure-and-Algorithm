#include<stdio.h>
#include<stdlib.h>
#include <iostream>
// You can add or change any code as you need
typedef int ElementType;

typedef struct AVLNode* Position;
typedef Position AVLTree;
struct AVLNode{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height ;
};

int MAX(int a, int b)
{
    return a>b?a:b;
}

int GetHeight(AVLTree T);
AVLTree LL(AVLTree A);
AVLTree RR(AVLTree A);
AVLTree LR(AVLTree A);
AVLTree RL(AVLTree A);
AVLTree Insert(AVLTree T, ElementType X);
void PrintTree(AVLTree T);    
int main()
{
    int N,i,X;
    scanf("%d",&N);
    AVLTree T = NULL;
    for ( i=0 ; i<N ; i++ )
    {
        scanf("%d",&X);
        T = Insert(T,X);
    }
    //PrintTree(T);
    //std::cout<<std::endl;
    printf("%d",T ->Data);
    return 0 ;
}

int GetHeight(AVLTree T)
{
    int HL,HR,MaxH;
    if(T)
    {
        HL = GetHeight(T ->Left);
        HR = GetHeight(T ->Right);
        MaxH = HL>HR?HL:HR;
        return (MaxH+1);
    }
    else  return 0 ;
}

AVLTree LL(AVLTree A)
{
    AVLTree B = A ->Left;
    A ->Left = B ->Right;
    B ->Right = A;
    A ->Height = MAX(GetHeight(A ->Left),GetHeight(A ->Right)) + 1;
    B ->Height = MAX(GetHeight(B ->Left),A ->Height) + 1;
    return B;
}

AVLTree RR(AVLTree A)
{
    AVLTree B = A ->Right;
    A ->Right = B ->Left;
    B ->Left = A;
    A ->Height = MAX(GetHeight(A ->Left),GetHeight(A ->Right)) + 1;
    B ->Height = MAX(GetHeight(B ->Right),A ->Height) + 1;
    return B;
}
    
AVLTree LR(AVLTree A)
{
    // Your code here; you may need to change the return A;
    AVLTree B = A ->Left;
    A->Left=RR(B);
    return LL(A);
}
    
    
AVLTree RL(AVLTree A)
{
    // Your code here; you may need to change the return A;
    AVLTree B = A ->Right;
    A->Right=LL(B); 
    return RR(A);
}
    
    
AVLTree Insert(AVLTree T, ElementType X)
{
    // Your code here
    AVLTree t=T;
    if(!T){//the tree is empty
    	T=(AVLTree)malloc(sizeof(struct AVLNode));
    	T->Data=X;
    	T->Left=T->Right=nullptr;
	}
	else{
		if(X>T->Data){
			//std::cout<<"data:"<<T->Data<<" left:"<<GetHeight(T->Left)<<" right:"<<GetHeight(T->Right)<<std::endl;
			T->Right=Insert(T->Right,X);  //insert the element,no need to change the root
			if(GetHeight(T->Right)>=GetHeight(T->Left)+2){ //compare whether is balanced
				if(T->Right->Data>X){ //rotation&&change the root node if necessary
					T=RL(T);
				}
				else{
					T=RR(T);
				}
			}
		}
		else{
			//std::cout<<"data:"<<T->Data<<" left:"<<GetHeight(T->Left)<<" right:"<<GetHeight(T->Right)<<std::endl;
			T->Left=Insert(T->Left,X);
			if(GetHeight(T->Left)>=GetHeight(T->Right)+2){
				//unbalanced
				if(T->Left->Data>X){
					T=LL(T);
				}
				else{
					T=LR(T);
				}
			}
		}
	}
	//std::cout<<"data:"<<T->Data<<" left:"<<GetHeight(T->Left)<<" right:"<<GetHeight(T->Right)<<" input is:"<<X<<std::endl;
    return T;
}

void PrintTree(AVLTree T){
	if(T){
		PrintTree(T->Left);
		std::cout<<T->Data<<" ";
		PrintTree(T->Right);
	}
}

