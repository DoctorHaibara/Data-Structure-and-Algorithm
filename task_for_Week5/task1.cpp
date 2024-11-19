#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;
// You can add/modify any package or code as you need
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	// 在DEV C++ 如出错 [Error] 'nullptr' was not declared in this scope  参考 https://blog.csdn.net/qq_35030275/article/details/104144352 
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeight(TreeNode* T){
	if(!T->left&&!T->right){
		return 1;
	}
	else if(T->left){
		return getHeight(T->left)+1;
	}
	else if(T->right){
		return getHeight(T->right)+1;
	}
	else{
		return max(getHeight(T->left),getHeight(T->right))+1;
	}
	
}

bool isBalanced(TreeNode* root) {
    // You code here
    int height_l,height_r;
    height_l=getHeight(root->left);
    height_r=getHeight(root->right);
	//cout<<height_l<<" "<<height_r;
	if(abs(height_l-height_r)<=1){
		return true;
	}
	else{
		return false;
	}
    }

int main(){
    // 一个粗暴建树的方式，也可以重新写一个建树函数，输入 [3,9,20,null,null,15,7]，输出树的头结点。
// 	TreeNode* T0 = new TreeNode(0);
//     TreeNode* T1 = new TreeNode(1);
//     TreeNode* T2 = new TreeNode(2);
//     TreeNode* T3 = new TreeNode(3);
//     TreeNode* T4 = new TreeNode(4);
//     TreeNode* T5 = new TreeNode(5);
//     T0->val = 0;
//     T1->val = 1;
//     T2->val = 2;
//     T3->val = 3;
//     T4->val = 4;
//     T5->val = 5;

//     T0->left = T1;
//     T0->right = T2;
//     T1->left = T3;
//     T2->left = T4;
//     T2->right = T5;
// //
// //    this tree like :
// //                    0
// //                1       2
// //              3   N   4   5

    // 示例1
    printf("root=[3,9,20,null,null,15,7]:\n");
    // 建树
    TreeNode* T1 = new TreeNode(3); // 根节点
    TreeNode* T1_1 = new TreeNode(9);
    TreeNode* T2_1 = new TreeNode(20);
    //TreeNode* T3_1 = new TreeNode(NULL);
    //TreeNode* T4_1 = new TreeNode(NULL);
    TreeNode* T5_1 = new TreeNode(15);
    TreeNode* T6_1 = new TreeNode(7);

     T1->left = T1_1;
     T1->right = T2_1;
     T1_1->left = nullptr;
     T1_1->right = nullptr;
     T2_1->left = T5_1;
     T2_1->right = T6_1;
     
    
    if (isBalanced(T1)) {
        printf("true");
    }
    else {
        printf("false");
    }
    
    printf("\n");
    
    // 示例2
    printf("root=[1,2,2,3,3,null,null,4,4]:\n");
    // 建树
    TreeNode* T2 = new TreeNode(1); // 根节点
    TreeNode* T1_2 = new TreeNode(2);
    TreeNode* T2_2 = new TreeNode(2);
    TreeNode* T3_2 = new TreeNode(3);
    TreeNode* T4_2 = new TreeNode(3);
    //TreeNode* T5_2 = new TreeNode(NULL);
    //TreeNode* T6_2 = new TreeNode(NULL);
    TreeNode* T7_2 = new TreeNode(4);
    TreeNode* T8_2 = new TreeNode(4);

     T2->left = T1_2;
     T2->right = T2_2;
     T1_2->left = T3_2;
     T1_2->right = T4_2;
     T2_2->left = nullptr;
     T2_2->right = nullptr;
     T3_2->left = T7_2;
     T3_2->right = T8_2;

    if (isBalanced(T2)) {
        printf("true");
    }
    else {
        printf("false");
    }

	return 0;
}

