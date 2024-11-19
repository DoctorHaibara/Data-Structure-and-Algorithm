#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Note: you can add or delete any code/functions whenever needed

const int inf = 0x3f3f3f3f;
int n, m;
string s1[100];
//Example: Huffman树的节点类(数组表示)(task1里给出了链表表示的example，都可以) 
struct node{
	int w;   //权重 
	int p;   //父节点 
	int l; 	 //左孩子 
	int r;   //右孩子 
}ht[4000]; //哈夫曼树                      
struct code{
	string s;  
}hc[64]; // 哈夫曼编码                                      

void Huffman(struct node*ht,int n){
	for(int i=0;i<n-1;i++)
    {
        int w1,w2;
		w1=w2=10000;
		int x1,x2;
        x1=x2=0;
        for(int j=0;j<n+i;j++)      //寻找权值最小的两个结点
        {
            if(ht[j].p==-1&&ht[j].w<w1)
            {
                w2=w1;
                x2=x1;
                w1=ht[j].w;
                x1=j;
            }
            else if(ht[j].p==-1&&ht[j].w<w2)
            {
                w2=ht[j].w;
                x2=j;
            }
        }
        ht[n+i].l=x1;
        ht[n+i].r=x2;
        ht[n+i].w=w1+w2;
        ht[n+i].p=-1;
        ht[x1].p=ht[x2].p=n+i;
	}
}

void getCode(struct node* ht,struct code* hc,int n){
	for(int i=0;i<n;i++){
		int tmp=i;
		int c=tmp;
		while(ht[tmp].p!=-1){
			tmp=ht[tmp].p;
			if(c==ht[tmp].l){
				hc[i].s.push_back(0);
			}
			else{
				hc[i].s.push_back(1);
			}
			c=tmp;
		}
	}
}

int getTotal(struct node* ht,struct code* hc,int n){
	int total=0;
	Huffman(ht,n);
	getCode(ht,hc,n);
	for(int i=0;i<n;i++){
		total+=hc[i].s.length()*ht[i].w;
		//cout<<hc[i].s.length()<<" "<<ht[i].w<<endl;
	}
	return total;
}

bool isPreffix(struct code* hc,int n){
	string::size_type idx;
	//for(int i=0;i<n;i++) cout<<hc[i].s<<endl;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(hc[i].s.length()>hc[j].s.length()){
				auto res=mismatch(hc[j].s.begin(),hc[j].s.end(),hc[i].s.begin());
				if(res.first==hc[j].s.end()){//is preffix
				//cout<<j<<" "<<hc[j].s<<" "<<i<<" "<<hc[i].s<<endl;
					return true;
				}
			}
			else{
				auto res=mismatch(hc[i].s.begin(),hc[i].s.end(),hc[j].s.begin());
				if(res.first==hc[i].s.end()){//is preffix
				//cout<<i<<" "<<hc[i].s<<" "<<j<<" "<<hc[j].s<<endl;
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
    int i;
    char ch;
    string str;
	cin >> n;
	// Your code here, e.g., input the characters and their frequencies, build Huffman tree if needed 
    
	for(int i=0;i<n;i++){
    	cin>>ch;
    	cin>>ht[i].w;
    	ht[i].p=ht[i].l=ht[i].r=-1;
	}
	
	int total=getTotal(ht,hc,n);
	//cout<<"total:"<<total<<endl;
	cin >> m;
	while(m--) {
		// Your code here, e.g., input the tested code and check if it is or not is a correct Huffman code
		int check_total=0;
		for(int i=0;i<n;i++){
			cin>>ch;
			cin>>hc[i].s;
			check_total+=hc[i].s.length()*ht[i].w;
		}
		bool f=isPreffix(hc,n);
		if(check_total==total&&!f){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

