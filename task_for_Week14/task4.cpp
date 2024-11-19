#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
// Note: you can add or modify any code when needed
vector <int> path,g[1005];//path存路，g存联通的点
int visit[1005];//存点的状态，0为未走过，1为走过了
void dfs(int k){
    // Your code here
	if(visit[k]==0){
			path.push_back(k);
			visit[k]=1;
		}
		for(int j=0;j<g[k].size();j++){
			if(visit[g[k][j]]==0){
				//visit(vec[v][j]);
				//visited[vec[v][j]]=1;
				dfs(g[k][j]);
			}
		}
}
int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);  //把与a，b两点联通的点存起来
		g[b].push_back(a);  //链表存储
	}
	dfs(s);
    // Your code here, e.g., print out the results
    if(n!=path.size()){
    	cout<<0;
	}
	else{
		for(int i=0;i<path.size();i++){
			cout<<path[i]<<" ";
		}
		for(int i=path.size()-2;i>=0;i--){
			cout<<path[i]<<" ";
		}
	}
	return 0;
}

