#include<stdio.h>
#include<stdlib.h>
#include <iostream>
// ×¢£ºYou can add/modify any package or code as you need
using namespace std;
struct st
{
	int data[1005];
	int front,rear;
};
typedef struct st *Qnode;
typedef Qnode queue;

void addQ(queue q,int n){
		q->data[q->rear++]=n;
}

int delQ(queue q){
	return q->data[++q->front];
}

bool isempty(queue q){
	if(q->front+1==q->rear){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	int n,t;
	scanf("%d",&n);
	// Your code here
	queue qa,qb;
	qa=(queue)malloc(sizeof(struct st));
	qb=(queue)malloc(sizeof(struct st));
	qa->front=qb->front=0;
	qa->rear=qb->rear=1;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t%2==0){
			addQ(qb,t);
		}
		if(t%2==1){
			addQ(qa,t);
		}
	}
	/*for(int i=qa->front+1;i<=qa->rear;i++){
		cout<<i<<"->"<<qa->data[i]<<" ";
		cout<<endl;
	}
	
	for(int i=qb->front+1;i<=qb->rear;i++){
		cout<<i<<"->"<<qb->data[i]<<" ";
		cout<<endl;
	}*/
	for(int i=0;i<n;i+=3){
	   	if(!isempty(qa)) cout<<delQ(qa)<<" ";
		if(!isempty(qa)) cout<<delQ(qa)<<" ";
		if(!isempty(qb)) cout<<delQ(qb)<<" ";
	}
	return 0; 
}

