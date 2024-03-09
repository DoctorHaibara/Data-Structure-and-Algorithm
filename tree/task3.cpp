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

int maxPathSum(TreeNode* root,int& num_max) {
    // You code here
    if(!root){
    	return 0;
	}
	else{
			int m1=max(maxPathSum(root->left,num_max),0);
            int m2=max(maxPathSum(root->right,num_max),0);
            //cout<<m1<<" "<<m2<<"->"<<root->val<<endl;
            num_max=max(m1+m2+root->val,num_max);
			return m1+m2+root->val;		
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

    // 示例
    printf("��[-10,9,20,null,null,15,7]");
    // 建树
    TreeNode* T1 = new TreeNode(-10);
    TreeNode* T2 = new TreeNode(9);
    TreeNode* T3 = new TreeNode(20);
    //TreeNode* T4 = new TreeNode(-10);
    //TreeNode* T5 = new TreeNode(9);
    TreeNode* T6 = new TreeNode(15);
    TreeNode* T7 = new TreeNode(7);
    T1->left = T2;
    T1->right = T3;
    //T1->left = T3;
    T3->left = T6;
    T3->right = T7;
    //T7->left = T4;
    //T4->left = T5;
    printf("���·����Ϊ��");
    int num=0;
    int maxSum = maxPathSum(T1,num);
    cout << max(maxSum,num);
	return 0;
}

