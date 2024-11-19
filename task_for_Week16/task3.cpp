#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
// Please add or modify any code whenever needed 
using namespace std;
int N = 1010 , inf = 99999999;
int f[1010][1010];
int dist[1010];
int n , m;
int parent[1010];
int total=0;
int minTotal=inf;
vector<int> MST;
/*
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3
*/
int getMin(){
	int k=0;
	for(int i=1;i<=n;i++){
		if(dist[i]<dist[k]&&dist[i]>0)	k=i;			
	}
	return k;
}

void Prim(int i){
	while(true){
		int v=getMin();
		//cout<<"v:"<<v<<endl;
		if(v==0) break;
		if(v!=i) total+=dist[v];
		//cout<<v<<" "<<total<<endl;
		dist[v]=0;
		
		for(int i=1;i<=n;i++){
			if(f[i][v]!=inf){//йгаз╫с 
				if(dist[i]!=0){
					if(f[i][v]<dist[i]){dist[i]=f[i][v];parent[i]=v;}
				}
			}
		}
		//for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
		//cout<<endl;
	}
}

int main()
{
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
    	dist[i]=inf;
        for(int j = 1 ; j <= n ; j++)
           if(i != j)
             f[i][j] = inf;
    }
    int x , y , z;
    for(int i = 1 ; i <= m ; i++)
    {
        cin>>x>>y>>z;
        f[x][y] = z;
        f[y][x] = z;
    }
    
    /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<f[i][j]<<"\t";
            }
            cout<<endl;
        }
      */  
    // Your code here 
    for(int i=2;i<=n;i++){
    	if(f[1][i]<dist[1]) dist[1]=f[1][i];
	}
	dist[0]=inf;
	//for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    Prim(1);
    for(int i=2;i<=n;i++){
    	if(dist[i]!=0){
			cout<<-1;
			return 0;
		} 
	} 
    cout<<total;
}

