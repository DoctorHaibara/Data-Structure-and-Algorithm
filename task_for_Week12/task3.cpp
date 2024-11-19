#include<bits/stdc++.h>
// Note: you can add or delete any code/functions whenever needed

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	// Your code here
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int sum=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				sum++;
				//printf("%d %d\n",a[i],a[j]);
			}
		}
	}
	printf("%d",sum); 
	return 0;
}

