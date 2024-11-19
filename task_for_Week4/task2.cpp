#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std; 
// ע��You can add/modify any package or code as you need
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    int *Data;  /* �洢Ԫ�ص�����*/
    Position Front;     /* ���е�ͷָ��*/
    int Count;          /* ������Ԫ�ظ���*/
    int MaxSize;        /* �����������*/
};
typedef PtrToQNode Queue; 

bool AddQ(Queue Q, int X)
{
	// Your code here
	if(Q->Count==Q->MaxSize){
		cout<<"Queue Full"<<endl;
		return false;
	}
	else{
		int c=++Q->Count;
		Position rear=(Q->Front+c-1)%Q->MaxSize;
		Q->Data[rear]=X;
		cout<<"element add successful"<<endl;
	}
	return true;
}
int DeleteQ(Queue Q)
{
	// Your code here
	if(Q->Count==0){
		cout<<"Queue Empty"<<endl;
		return false;
	}
	else{
		Q->Count--;
		Q->Front=(Q->Front+1)%Q->MaxSize;
	    cout<<"element delete successful"<<endl;
	}
	return true;
}

int main(){
	// ��������1 2 3 4 ɾ���Ĵ�
	QNode *MyCircularQueue = (QNode *)malloc(sizeof(QNode));
	MyCircularQueue->MaxSize = 3;
	MyCircularQueue->Front = MyCircularQueue->Count = 0;
	MyCircularQueue->Data = (int *)malloc(sizeof(int) * MyCircularQueue->MaxSize);
	AddQ(MyCircularQueue,1);
	AddQ(MyCircularQueue,2);
	AddQ(MyCircularQueue,3);
	AddQ(MyCircularQueue,4);
    DeleteQ(MyCircularQueue);
    DeleteQ(MyCircularQueue);
    DeleteQ(MyCircularQueue);
    DeleteQ(MyCircularQueue);
	return 0;
} 
