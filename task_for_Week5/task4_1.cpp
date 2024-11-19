#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
// You can add/modify any package or code as you need
// Definition for a binary tree node.
struct TreeNode{
   int val;
   TreeNode* left;
   TreeNode* right;	
   bool flag=false;
   TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode* creatTree(int n){
	int t;
	scanf("%d",&t);
	TreeNode* Tree=new TreeNode(t);
	TreeNode* T=Tree;
	while(--n){
		scanf("%d",&t);
		TreeNode* T1=new TreeNode(t);
		while(T->val!=t){
			if(t>T->val){
				if(T->right){
					T=T->right;
				}
				else{
					T->right=T1;
				}
			}
			else{
				if(T->left){
					T=T->left;
				}
				else{
					T->left=T1;
				}
			}
		}
		T=Tree;
	}
	return Tree;
}

void printTree(TreeNode* T){
	if(T){
		printTree(T->left);
		cout<<T->val<<" ";
		printTree(T->right);
	}
}

bool search(int num,TreeNode* T){
	while(T->val!=num&&T){
		if(!T->flag) return false;
		if(T->val>num){
			T=T->left;
		}
		else{
			T=T->right;
		}
    }
	if(!T){//the value does't exist
		return false;
	}
	else{//the value was found
		T->flag=true;
	}
    
    return true;
}

void reset(TreeNode* T){
	if(T){
		reset(T->left);
		T->flag=false;
		reset(T->right);
	}
}

bool check(TreeNode* T,int n){
	int num;
	bool flag=true;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(!search(num,T)) flag=false;
	}
	return flag;	
}

int main(){
	int n,m;
	scanf("%d",&n);
	while(n){
		scanf("%d",&m);
	    	TreeNode* t=creatTree(n);
		    for(int i=0;i<m;i++){
		    	if(check(t,n)){
		    		cout<<"Yes"<<endl;
				}
				else{
					cout<<"No"<<endl;
				}
				reset(t);
			}
			scanf("%d",&n);
    }
	return 0;
} 
