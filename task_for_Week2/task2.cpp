#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;
int A[100005],B[100005];
int findMidNum(int A[], int B[], int len)
{
	// Your code here
	int C[len*2];
	int i=0;
	int i1=0;
	int i2=0;
	while(i<=len){
		if(A[i1]>=B[i2]){
			C[i++]=B[i2++];
		}
		else{
			C[i++]=A[i1++];
		}
	}
	/*for(int j=0;j<=len;j++){
		cout<<j<<"->"<<C[j]<<" ";
	}*/
	//cout<<" "<<i<<endl;
	return (C[len-1]+C[len])/2; 
	return 0;
}
int main()
{
	int n,i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &B[i]);
	}
	int ans = findMidNum(A, B, n);
	cout << ans << endl;
	return 0;
}

