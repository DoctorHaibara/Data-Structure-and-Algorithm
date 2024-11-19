#include<stdio.h>
#include<stdlib.h>
#include <vector>
// Note: you can add or delete any code/functions whenever needed
/*     判断是否是插入排序的函数    */
using namespace std;
int IsInsertion(int a[], int b[], int N){
    // Your code here
    int n=0;
	while(b[n]<b[n+1]) n++;
	int i=n+1;
	while(i<=N&&a[i]==b[i]) i++;
	if(i==N)
		return n;
	else
		return 0;
}

/*    输出函数    */
void PrintResults(int *b, int N){
    int i;
    printf("%d",b[0]);
    for(i=1;i<N;i++)
        printf(" %d",b[i]);
    printf("\n");
}

/*    进行下一轮插入排序    */
void NextInsertion(int *b, int N, int k){
    // Your code here
    int p=k;
    int tmp=b[k+1];
    while(b[p]>tmp){
    	b[p+1]=b[p];
    	p--;
	}
    b[p+1]=tmp;
}

// Note: you can add or delete any code/functions whenever needed

/*    进行下一轮堆排序    */
void NextHeap(int *b, int N){
    // Your code here
    int tmp=b[0];
	int n=N-1;
	while(tmp<b[n]) n--;
	b[0]=b[n];
	b[n]=tmp;
	 
    int parent=0,child=1;
    while(child<n){
    	if(child<n&&b[child]<b[child+1]){
    		child++;
		}
		swap(b[child],b[parent]);
		parent=child;
		child=parent*2+1;
	}
}  

int main(void){
    int N,i,k;
    scanf("%d",&N);
    int a[N],b[N];
    
    for(i = 0;i<N;i++)
        scanf("%d",&a[i]);
    for(i = 0;i<N;i++)
        scanf("%d",&b[i]);
    
    if(k = IsInsertion(a, b, N)){	//判断是否是插入排序
        printf("Insertion Sort\n");
		NextInsertion(b, N, k);	
	}		//若是，进入下一轮插入排序
    else{
    	printf("Heap Sort\n");
        NextHeap(b, N);				//若不是进行下一轮堆排序
	}
    PrintResults(b,N);
    return 0;
}

