#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
// Please add or modify any code whenever needed 
using namespace std;
int f[505][505]  , e[505][505]; // 两种权重 
int dis[505], kk[505]; // 对应两种“最短路径” 
int collected[505];
int n , m , t1 ,t2; // 第一行的四个整数 
int x , y , k1 , k2;
int inf = 9999;
/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/

void init() // 赋初值
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i == j)
           {
               f[i][j] = 0;e[i][j] = 0;
           }
           else
           {
               f[i][j] = inf;
               e[i][j] = inf;
           }
        }
    }
}

void dijkstra(int t1){
	for(int i=0;i<n;i++){
		dis[i]=inf;
		kk[i]=inf;
	}
    dis[t1]=0;
    kk[t1]=0;
     
	while(1){
		int v=-1;
		int min=inf;
		
		for(int j=0;j<n;j++){
			if(collected[j]==0){
				if(dis[j]<min){
					min=dis[j];
					v=j;
				}
			}
		}
		//std::cout<<"v:"<<v<<" "<<min<<std::endl;
		if(v==-1) break;
		collected[v]=1;
		for(int j=v;j<n;j++){
			if(collected[j]==0&&f[v][j]!=inf){
				if(dis[v]+f[v][j]<dis[j]){
					dis[j]=dis[v]+f[v][j];
					kk[j]=kk[v]+e[v][j];
				}
				else if(dis[v]+f[v][j]==dis[j]){
					if(kk[v]+e[v][j]<kk[j]) kk[j]=kk[v]+e[v][j];
				}
			}
		}
	}
}
int main()
{
    cin>>n>>m>>t1>>t2; //t1 起点， t2 终点 
    init();
    for(int i = 1 ; i <= m ; i++)//读入边
    {
        cin>>x>>y>>k1>>k2;
        f[x][y] = k1;f[y][x] = k1;
        e[x][y] = k2;e[y][x] = k2;
    }
    // Your code here
    
    
    //collected[t1]=1;
	dijkstra(t1);
    cout<<dis[t2]<<" "<<kk[t2];
}

