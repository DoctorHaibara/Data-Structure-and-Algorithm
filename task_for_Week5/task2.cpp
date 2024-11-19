#include<iostream>
#include<vector>
#include<stdlib.h>
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

bool isSubStructure(TreeNode* A, TreeNode* B) {
    // You code here
    if(!B&&A){
    	return true;
	}
	else if(!A){
		return false;
	}
    if(A->val==B->val){
    	return isSubStructure(A->left,B->left)||isSubStructure(A->right,B->right);
	}
	else{
		return isSubStructure(A->left,B)||isSubStructure(A->right,B);
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
    printf("A=[3,4,5,1,2], B=[4,1]");
    // 建树
    TreeNode* T1_A = new TreeNode(3);
    TreeNode* T1_2_A = new TreeNode(4);
    TreeNode* T1_3_A = new TreeNode(5);
    TreeNode* T1_4_A = new TreeNode(1);
    TreeNode* T1_5_A = new TreeNode(2);
    T1_A->left=T1_2_A;
    T1_A->right=T1_3_A;
    T1_2_A->left=T1_4_A;
    T1_2_A->right=T1_5_A;
    
    TreeNode* T1_B = new TreeNode(4);
    TreeNode* T1_2_B = new TreeNode(4);
    T1_B->left=T1_2_B;
    
    if (isSubStructure(T1_A, T1_B)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    // 示例2
    printf("A=[3,null,5,1,2], B=[1,2]");
    // 建树
    TreeNode* T2_A = new TreeNode(3);
    TreeNode* T2_2_A = new TreeNode(5);
    //TreeNode* T2_3_A = new TreeNode(5);
    TreeNode* T2_4_A = new TreeNode(1);
    TreeNode* T2_5_A = new TreeNode(2);
    TreeNode* T2_B = new TreeNode(1);
    TreeNode* T2_1_B = new TreeNode(2);
    
    T2_A->left=T2_2_A;
    //T2_A->right=T2_3_A;
    T2_2_A->left=T2_4_A;
    T2_2_A->right=T2_5_A;
    
    T2_B->left=T2_1_B;

    if (isSubStructure(T2_A, T2_B)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

	return 0;
}

