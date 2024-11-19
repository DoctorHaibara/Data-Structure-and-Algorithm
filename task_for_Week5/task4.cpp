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
		cout<<T->val;
		printTree(T->right);
	}
}

bool check(TreeNode* T,TreeNode* t){
	if(t&&T){
	   if(T->val==t->val){
	   	    return check(T->left,t->left)&&check(T->right,t->right);
	   }
	   else{
	   	return false;
	   }	
	}
	else if(!T&&!t){
	    return true;	
	}
	else{
		return false;
	}
}
int main(){
	int n,m;
	scanf("%d",&n);
	while(n){
		scanf("%d",&m);
	    	TreeNode* t=creatTree(n);
		    for(int i=0;i<m;i++){
		    	TreeNode* T=creatTree(n);
		    	if(check(t,T)){
		    		cout<<"Yes"<<endl;
				}
				else{
					cout<<"No"<<endl;
				}
			}
			scanf("%d",&n);
    }
		
	return 0;
} 
