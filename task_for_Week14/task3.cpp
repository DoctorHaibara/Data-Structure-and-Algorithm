#include<queue>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
// Note: you can add or modify any code when needed
int city,road,tempf,temps,visited[16],nowi,pass[16],temp;
queue<int>answer;
vector<vector<int> >connect(16);

void visit( int V ){
    printf(" %d", V);
}

bool DFS(vector<vector<int>> vec,int v,void (*visit)(int)){
	bool flag=false;
		if(visited[v]==0){
			flag=true;
			visit(v);
			visited[v]=1;
		}
		for(int j=0;j<vec[v].size();j++){
			if(visited[vec[v][j]]==0){
				//visit(vec[v][j]);
				//visited[vec[v][j]]=1;
				flag=true;
				DFS(vec,vec[v][j],visit);
			}
		}
		return flag;		
}

bool BFS(vector<vector<int>> vec,int v,void (*visit)(int)){
		bool flag=false;
		if(visited[v]==0){
			flag=true;
			answer.push(v);
			visit(v);
			visited[v]=1;
		}
		for(int j=0;j<vec[v].size();j++){
			if(visited[vec[v][j]]==0){
				//visit(vec[v][j]);
				//visited[vec[v][j]]=1;
				flag=true;
				answer.push(vec[v][j]);
			}
		}
		if(!answer.empty()){
			int tmp=answer.front();
			answer.pop(); 
			BFS(vec,tmp,visit);
		}
		
		return flag;	
}
int main(){
	int i,r;
    // 输入结点和边
	scanf("%d%d",&city,&road);
	while(road--){
		scanf("%d%d",&tempf,&temps);
		connect[tempf].push_back(temps);
		connect[temps].push_back(tempf); // 链表存储
	}
	
	for(int i=0;i<connect.size();i++){
		sort(connect[i].begin(),connect[i].end());
	}
    // 输出DFS结果
    // Your code here
    for(int i=0;i<city;i++){
    	if(DFS(connect,i,visit)) cout<<endl;
	}
	memset(visited,0,sizeof(visited));
    // 输出BFS结果
    // Your code here
    for(int i=0;i<city;i++){
    	if(BFS(connect,i,visit)) cout<<endl;
	}
	memset(visited,0,sizeof(visited));
	
	return 0;
}

