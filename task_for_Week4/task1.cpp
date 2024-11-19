#include<stdio.h>
#include <iostream>
// 打印杨辉三角 
// 注：You can add/modify any package or code as you need
#define MAXSIZE 500
typedef struct sq
{
int a[MAXSIZE];
int front,rear;
}*SeqQue;

void addQ(SeqQue q,int num){
	q->a[++q->rear]=num;
}

int delQ(SeqQue q){
	return q->a[q->front++];
}


int main(){
	// Your code here
	int n;
	scanf("%d",&n);
	n++;//元素的个数 
	SeqQue b[n];
	b[1]=(SeqQue)malloc(sizeof(sq));
	b[1]->a[0]=b[1]->a[1]=1;
	for(int i=2;i<n;i++){//i+1 is the size of the queue
		b[i]=(SeqQue)malloc(sizeof(struct sq));
		b[i]->a[0]=b[i]->a[i]=1;
		for(int j=1;j<i;j++){
			b[i]->a[j]=delQ(b[i-1]);
			b[i]->a[j]+=b[i-1]->a[b[i-1]->front];
		}
	}
	for(int i=0;i<n;i++){
		std::cout<<b[n-1]->a[i]<<" ";
	}
	return 0; 
} 

