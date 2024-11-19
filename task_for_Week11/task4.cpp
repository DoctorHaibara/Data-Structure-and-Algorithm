#include <vector>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

//you can freely add the functions and packages you need
//Try 'Greedy Thinking' to solve this problem

void sort(string* str,int n){
	for(int i=0;i<n-1;i++){
		int k=i;
		for(int j=k+1;j<n;j++){
			if(str[k]<str[j]) k=j;
		}
		//cout<<i<<k<<endl;
		if(k!= i) swap(str[i],str[k]);
	}
}

void print(string* str,int n){
	for(int i=0;i<n;i++){
		cout<<str[i];
	}
}
int main(){
    //Your code here
	int n;
	cin>>n;
	string str[n];
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	sort(str,n);
	print(str,n);
    return 0;
}
