#include<stdio.h>
#include<algorithm>
#include<math.h>
// Note: you can add or delete any code/functions whenever needed
using namespace std;

bool check(int a[],int b[],int number){
	int i=0;
	for(i;i<number&&b[i]<b[i+1];i++);
	for(i;i<number&&a[i]==b[i];i++);
	//printf("i is:%d\n",i);
	if(i==number) return true;
	else return false; 
}

void Insertion_Sort(int* b,int number){
	int i=0;
	int j;
	for(i;i<number&&b[i]<b[i+1];i++);
	int tmp=b[i+1];
	for(j=i;j>=0&&tmp<b[j];j--) b[j+1]=b[j];
	b[j+1]=tmp;
}
void Merge_Sort(int* b,int number){
	int i=0;
	for(i;i<number&&b[i]<b[i+1];i++);
	for(int j=1;;j++){
		if(pow(2,j)-1<=i&&pow(2,j+1)-1>i){
			i=pow(2,j);
			break;
		}
	}

	for(int j=0;j<number/i*i;j+=i*2){
		int p=0;
		int p1=j;
		int p2=j+i;
		int tmp[i*2];
		for(;p1<j+i&&p2<j+i*2;){
			if(b[p1]<b[p2]){
				tmp[p++]=b[p1++];
			}
			else{
				tmp[p++]=b[p2++];
			}
		}
		for(;p1<j+i;) tmp[p++]=b[p1++];
		for(;p2<j+i*2;) tmp[p++]=b[p2++];
		for(int k=0;k<p;k++){
			b[j+k]=tmp[k];
		}
	}
}
int main(){
	int number;
	scanf("%d",&number);
	// Your code here
	int a[number],b[number];
	for(int i=0;i<number;i++) scanf("%d",&a[i]);
	for(int i=0;i<number;i++) scanf("%d",&b[i]);
	if(check(a,b,number)){
		printf("Insertion Sort\n");
		Insertion_Sort(b,number);
	}
	else{
		printf("Merge Sort\n");
		Merge_Sort(b,number);
	}
	for(int i=0;i<number;i++){
		printf("%d ",b[i]);
	}
	return 0;
}

