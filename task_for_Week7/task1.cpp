#include<iostream>
#include<vector>
#include<stdlib.h>
#include <cstring>
using namespace std;
// You can add/modify any package or code as you need
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	// åœ¨DEV C++ å¦‚å‡ºé”™ [Error] 'nullptr' was not declared in this scope  å‚è€ƒ https://blog.csdn.net/qq_35030275/article/details/104144352 
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*bool insert(TreeNode* root,TreeNode *newNode){
	TreeNode* left=root->left;
	TreeNode* right=root->right;
	if(left&&right){
		if(!insert(left,newNode))
		    insert(right,newNode);
	}
	else if(left&&!right){
		root->right=newNode;
		return true;
	}
	else if(!left&&!right){
		root->left=newNode;
		return true;
	}
}

TreeNode* createTree(){
	char* s;
	scanf("%s",s);
	int val=atoi(s);
	TreeNode *root=new TreeNode(val);//generate the root node
	while(true){
		if(strcpy(s,"null")==0){
			TreeNode * newNode=new TreeNode();
			insert(root,newNode);
		}
		else{
			int val=atoi(s);
			if(val==-1) break;
			TreeNode * newNode=new TreeNode(val);
			insert(root,newNode);
		}
	}
	
}*/

bool checkSymmetricTree(TreeNode* left,TreeNode* right) {
    // You code here
    if(!left&&!right){
    	return true;
	}
	else if(left&&!right||!left&&right){
		return false;
	}
	else{
	
     if(left->val==right->val){
     	return checkSymmetricTree(left->right,right->left)&&checkSymmetricTree(left->left,right->right);
	 }
	 else{
	 	return false;
	 }
    }
    }

int main(){

     // Ê¾Àý1
    printf("Tree [1, 2, 2, 3, 4, 4, 3]:");
    // ½¨Ê÷, e.g.,
    TreeNode* T1 = new TreeNode(1); // ¸ù½Úµã
    TreeNode* T1_2 = new TreeNode(2);
    TreeNode* T1_3 = new TreeNode(2);
    TreeNode* T1_4 = new TreeNode(3);
    TreeNode* T1_5 = new TreeNode(4);
    TreeNode* T1_6 = new TreeNode(4);
    TreeNode* T1_7 = new TreeNode(3);
    
    T1->left=T1_2;
    T1->right=T1_3;
    T1_2->left=T1_4;
    T1_2->right=T1_5;
    T1_3->left=T1_6;
    T1_3->right=T1_7;
    

    if (checkSymmetricTree(T1_2,T1_3)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    // Ê¾Àý2
    printf("Tree [1, 2, 2, null, 3, null, 3]:");
    // ½¨Ê÷, e.g.,
    TreeNode* T2 = new TreeNode(1); // ¸ù½Úµã
    TreeNode* T2_2 = new TreeNode(2);
    TreeNode* T2_3 = new TreeNode(2);
    //TreeNode* T1_4 = new TreeNode();
    TreeNode* T2_5 = new TreeNode(3);
    //TreeNode* T1_6 = new TreeNode(4);
    TreeNode* T2_7 = new TreeNode(3);
    
    T2->left=T2_2;
    T2->right=T2_3;
    //T1_2->left=T1_4;
    T2_2->right=T2_5;
    //T1_3->left=T1_6;
    T2_3->right=T2_7;
    

    if (checkSymmetricTree(T2_2,T2_3)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

	return 0;
}

