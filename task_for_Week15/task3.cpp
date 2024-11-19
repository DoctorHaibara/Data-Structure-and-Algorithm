#include<stdio.h>
#include<stack>
#include<iostream>
#include<cstring> 
#define INF 10000000
using namespace std;
// Please add or modify any code whenever needed 
#define MAXV 505
int G[MAXV][MAXV];
double dist[MAXV];
int pre[MAXV];
bool vis[MAXV] = {false};
int N,M;
int S,E;

void Dijkstra(int start)
{
	// Your code here
	dist[start]=1;
	while(1){
	int v=-1;
	double max=0;
	for(int i=0;i<=N;i++){//search for the max node not visited
		if(vis[i]==false){
			if(dist[i]>max){
				max=dist[i];
				v=i;
			}
		}
	}
	if(v==-1) break;
	vis[v]=true;
	for(int i=v+1;i<=N;i++){
		if(!vis[i]){
			if(dist[i]<dist[v]*(100-G[v][i])*0.01){
				dist[i]=dist[v]*(100-G[v][i])*0.01;
			}
		}
	}
	}
}


int main()
{

	scanf("%d %d",&N,&M);
	
	int V1,V2,L;
	/*初始化*/
	memset(dist, 0, sizeof(dist));
	memset(pre, -1, sizeof(pre));
	memset(G, -1, sizeof(G));
	/*初始化*/
	for(int i=0; i<M; ++i)
	{
		scanf("%d %d %d",&V1,&V2,&L);
		G[i][i] = 0;
		G[V1][V2] = L;
		G[V2][V1] = L;
	}
	scanf("%d %d",&S,&E);
	// Your code here
	Dijkstra(S);
	printf("%.8lf",100/dist[E]);
//	find(E);
	
	return 0;
}

