#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;
// You can add/modify any package or code as you need
// Definition for a binary tree node.
typedef struct TreeNode* Position;
typedef Position AVLTree;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	// 在DEV C++ 如出错 [Error] 'nullptr' was not declared in this scope  参考 https://blog.csdn.net/qq_35030275/article/details/104144352 
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int GetHeight(AVLTree T)
{
    int HL,HR,MaxH;
    if(T)
    {
        HL = GetHeight(T->left);
        HR = GetHeight(T ->right);
        MaxH = HL>HR?HL:HR;
        return (MaxH+1);
    }
    else  return 0 ;
}

AVLTree LL(AVLTree A)
{
    AVLTree B = A ->left;
    A ->left = B ->right;
    B ->right = A;
    return B;
}

AVLTree RR(AVLTree A)
{
    AVLTree B = A ->right;
    A ->right = B ->left;
    B ->left = A;
    return B;
}
    

TreeNode* balanceBST(TreeNode* root) {
    // You code here
    //std::cout<<GetHeight(root->right)<<" "<<GetHeight(root->left)<<std::endl;
    if(GetHeight(root->right)>=GetHeight(root->left)+2){ //compare whether is balanced
        //std::cout<<root->val<<" ";
		root=RR(root);
		//std::cout<<root->val<<std::endl;
	}
	else if(GetHeight(root->right)+2<=GetHeight(root->left)){
	    root=LL(root);	 
	}
      return root;
    }

void PrintTree(TreeNode* T,vector<int>& vec,int position){
	if(T){
		vec[position]=T->val;
		PrintTree(T->left,vec,position*2);
		PrintTree(T->right,vec,position*2+1);
	}
}

TreeNode* creatTree(vector<int> val, int idx,int n)
{
    //std::cout<<idx<<"->"<<val[idx]<<std::endl;
	if (val[idx]=='#') return nullptr;

    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
//    TreeNode* node = new TreeNode(val[idx]);
//    cout<<"---"<<val[idx]<<"---"<<idx <<endl;
    node->val = val[idx];

    if (idx*2 <= n)
        node->left = creatTree(val, idx*2,n);
    else
        node->left = nullptr;
    if (idx*2+1 <= n)
        node->right = creatTree(val, idx*2+1,n);
    else
        node->right= nullptr;

    return node;
}

int main(){
    
    vector<int> vec;
    // 示例1
    //printf("print by preOrder\n");
    printf("Tree [1,null,2,null,3,null,4,null,null]:\n");
    // 建树, e.g.,
    //TreeNode* T1 = new TreeNode(1); // 根节点
    vector<int> t1 = {0,1,'#',2,'#','#','#',3,'#','#','#','#','#','#','#',4,'#','#'};
    TreeNode* T1 = creatTree(t1,1,16);
    
	TreeNode* T1_balanced = balanceBST(T1);
    // You should print T1_balanced here
    int height=GetHeight(T1_balanced);
	for(int i=0;i<pow(2,height);i++){
		vec.push_back('#');
	}
    PrintTree(T1_balanced,vec,1);
    for(int i=1;i<pow(2,height);i++){
    	if(vec[i]=='#'){
    		std::cout<<"null ";
		}
		else{
			std::cout<<vec[i]<<" ";
		}
	}
	vec.clear();
    std::cout<<std::endl;
    
    
    
    // 示例2
    printf("Tree [2,1,3]:\n");
    // 建树, e.g.,
    //TreeNode* T2 = new TreeNode(2); // 根节点
    vector<int> t2 = {0,2,1,3};
    TreeNode* T2 = creatTree(t2,1,3);

    TreeNode* T2_balanced = balanceBST(T2);
    // You should print T2_balanced here
    height=GetHeight(T2_balanced);
	for(int i=0;i<pow(2,height);i++){
		vec.push_back('#');
	}
    PrintTree(T2_balanced,vec,1);
    for(int i=1;i<pow(2,height);i++){
    	if(vec[i]=='#'){
    		std::cout<<"null ";
		}
		else{
			std::cout<<vec[i]<<" ";
		}
	}

	return 0;
}


