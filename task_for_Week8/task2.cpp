#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

// You can add or modify any code when needed

int IsPrime(int N)//判断
{
	if(N==0||N==1)
	{
		return 0;
	}
	if(N>2)//判断是否是素数
	{
		int i;
		for(i=2;i<=sqrt(N)+1;i++)
			if(N%i==0)return 0;
	}
	return 1;
}
int NextPrime(int N)
{
	int i=N+1;//进行+1
	while(1)
	{
		if(IsPrime(i))//判断是否是素数
			return i;
		i++;//加1
	}
	return i;
}

int Hash(int val,int* table,int maxsize){
	int p=val%maxsize;
	int i=0;
	while(table[p+i*i]!=val&&table[p+i*i]!=-1&&i*i<maxsize){
		i++;
	}
	if(i*i>=maxsize){
		return -1;
	}
	else{
		return p+i*i;
	}
}

int main()
{
	int M,N;
	scanf("%d %d",&M,&N);
	if(!IsPrime(M))
		M=NextPrime(M);
	// Your code here
	int* table=(int*)malloc(sizeof(int)*M);
	
	for(int i=0;i<M;i++){
		table[i]=-1;
	}
	
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		int position=Hash(tmp,table,M);
		if(position==-1){
			if(i==N-1){
				printf("-");
			} 
			else{
				printf("- ");
			}
		}
		else{
			table[position]=tmp;
			if(i==N-1){
				printf("%d",position);
			} 
			else{
				printf("%d ",position);
			}
		}
	} 
    return 0;
}

