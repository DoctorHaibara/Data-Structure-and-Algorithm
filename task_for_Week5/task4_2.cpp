#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;
// You can add/modify any package or code as you need
// Definition for a binary tree node.

bool compare(queue<int> q1,queue<int> q2){
	queue<int> q1_left,q1_right,q2_left,q2_right;
	if(q1.front()==q2.front()){
		if(q1.size()==1&&q2.size()==1){
		  return true;
	    }
	    else if(q1.size()!=q2.size()){
	    	return false;
		}
		else{
			int head=q1.front(); 
			q1.pop();
			for(int i=0;i<q1.size();i++){
				if(q1.front()<head){
					q1_left.push(q1.front());
					q1.pop();
				}
				else{
					q1_right.push(q1.front());
					q1.pop();
				}
			}
			
			head=q2.front(); 
			q2.pop();
			for(int i=0;i<q2.size();i++){
				if(q2.front()<head){
					q2_left.push(q2.front());
					q2.pop();
				}
				else{
					q2_right.push(q2.front());
					q2.pop();
				}
			}
			return compare(q1_left,q2_left)&&compare(q1_right,q2_right);
		}
	}
	else{
		return false;
	}
}

int main(){
	int n,m;
	queue<int> q;
	scanf("%d",&n);
	while(n){
	scanf("%d",&m);
	for(int i=0;i<n;i++){
		//generate initial queue
	    int t;
	    scanf("%d",&t);
	    q.push(t);
	}
	for(int i=0;i<m;i++){
		queue<int> q1;
		for(int i=0;i<n;i++){
	        int t;
	        scanf("%d",&t);
	        q1.push(t);
	    }
		if(compare(q,q1)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	scanf("%d",&n);
    }
	return 0;
} 
