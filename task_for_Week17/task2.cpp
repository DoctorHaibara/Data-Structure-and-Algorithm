#include<bits/stdc++.h>
// Please add or modify any code whenever needed 

using namespace std;
typedef long long ll;
const int N=1e5+100;
int in[N],d[N];//������,���ʱ�� 
vector<pair<int,int> >e[N];//��һ���
bool topologicalsort(int n){
	int cn=0;//��¼������������Ķ�����
	queue<int>q;
	// Your code here 
	for(int i=0;i<n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int v=q.front();
		q.pop();
		
		//cout<<v<<" ";
		cn++;
		for(int i=0;i<e[v].size();i++){
				int index=e[v][i].first;
				//cout<<"index:"<<index<<endl;
				if(--in[index]==0){
					q.push(index);
				}
			if(d[index]<d[v]+e[v][i].second) d[index]=d[v]+e[v][i].second;
		}
	}
	if(cn<n) return false;
	else return true;	
} 
int main(){
	int n,m;
	cin>>n>>m;
	int x,y,z;
	while(m--){
		cin>>x>>y>>z;//���� ��ʱ�� 
		in[y]++;
		e[x].push_back({y,z}); 
	} 
	// �����������Ҫʵ�ֵĺ��� 
	if(topologicalsort(n)){
		int ans=0;
		for(int i=0;i<n;i++)
		ans=max(ans,d[i]);
		cout<<ans;
	}else cout<<"Impossible";
	return 0;
}

