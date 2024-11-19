#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Note: you can add or delete any code/functions whenever needed

#define MAXSIZE 100
//Example: Huffman���Ľڵ��ࣨ�����ʾ�� (task2������������ʾ��example��������) 
typedef struct Node
{
    char value;               //�����ַ�ֵ   
    int weight;               //����ַ����ֵ�Ƶ�� 
    Node *left,*right;     //�������Һ���
}Node;

void getMinheap(vector<Node*>& vec,int p){
	while(p>1&&vec[p]->weight<vec[p/2]->weight){
		 swap(vec[p],vec[p/2]);
		 p=p/2;
	}
}

Node* deleteMin(vector<Node*>& vec){
	Node* p=vec[1];
	vec[1]=vec[vec.size()-1];
	
	int parent,child;
	parent=1;
	child=2;
	//cout<<"size:"<<vec.size();
	while(child<vec.size()){
		if(child<vec.size()-1&&vec[child]->weight>vec[child+1]->weight){
			child++;
		}
		//cout<<"child:"<<child<<endl;
		swap(vec[parent],vec[child]);
		parent=child;
		child=parent*2;
	}
	vec.pop_back();
	/*cout<<p->value<<" "<<p->weight<<" "<<vec.size()<<endl;
	for(int i=1;i<vec.size();i++){
		cout<<vec[i]->value<<" "<<vec[i]->weight;
	}
	cout<<endl;*/
	return p;
}

void Huffman(vector<Node*>& vec){
	while(vec.size()>2){
		Node* new_node=new Node;
		new_node->value='#';
    	new_node->left=deleteMin(vec);
	    new_node->right=deleteMin(vec);
	    new_node->weight=new_node->left->weight+new_node->right->weight;
	    vec.push_back(new_node);
	    getMinheap(vec,vec.size()-1);
	}
	
}

void printHuffman(Node* root,vector<int>& v){
	if(root){
	        if(root->value!='#') {
	        	//cout<<v.size()*root->weight<<" "; 
				cout<<root->value<<":";
	        	for(int i=0;i<v.size();i++){
	        		cout<<v[i];
				}
				cout<<endl;
			}
			else{
				v.push_back(1);
	        	printHuffman(root->left,v);
	       		v.pop_back();
	       		v.push_back(0);
    	    	printHuffman(root->right,v);
    	    	v.pop_back();
			}
	        
	
	}	
}
int main()
{   
    cout<<"������Ҫ������ַ�,���Կո�������������⣩��"<<endl;
    // Your code here, e.g., handle the input characters 
    vector<Node*> vec;//a vector of the pointer of the nodes
    
    Node* p=nullptr;
    vec.push_back(p);
    
    char ch;
    while((ch=getchar())!='\n'){
    	if(ch!=' '){
    		Node* n=new Node;
    		n->value=ch;
    		n->left=n->right=nullptr;
    		vec.push_back(n);
        }
	}
    cout<<endl<<"������ÿ���ַ���Ӧ��Ƶ�Σ����Կո������"<<endl;
    // Your code here, e.g., handle the input weights and build Huffman trees 
    for(int i=1;i<vec.size();i++){
    	cin>>vec[i]->weight;
    	getMinheap(vec,i);
	}
	/*for(int i=1;i<vec.size();i++){
		cout<<i<<vec[i]->value<<vec[i]->weight<<endl;
	}*/
	
	Huffman(vec);
	Node* root=vec[1];
    cout<<endl<<"��Ӧ��Huffman�������£�"<<endl;
    // Your code here, e.g., print out the Huffman ocde
    vector<int> res;
    printHuffman(root,res);
    return 0;
}

