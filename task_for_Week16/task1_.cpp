#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
const int N=105;
const int inf=0x3f;
int f[N][N],g[N][N],d[N][N];
vector<int> result;

void getG(int i,int j){
	if(d[i][j]){
		cout<<d[i][j]<<" ";
		getG(i,d[i][j]);
		getG(d[i][j],i);
		getG(d[i][j],j);
		getG(j,d[i][j]);
	}
}
int main()
{

	int n,m,i,j,k,x,y,z,p,q;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			f[i][j]=inf;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			g[i][j]=inf;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		z=min(z,g[x][y]);
		f[x][y]=z;
		f[y][x]=z;
		g[x][y]=z;
		g[y][x]=z;
	}
	int ans=inf;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(ans>g[i][k]+g[k][j]+f[i][j]){
					ans=g[i][k]+g[k][j]+f[i][j];
					result.clear();
					result.push_back(i);
					result.push_back(k);
					result.push_back(j);
					result.push_back(d[i][j]);
				}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
					d[i][j]=d[j][i]=k;
				}
	}
	if(ans==inf)
		printf("No solution.\n");
	else
		for(int i=0;i<result.size();i++){
			cout<<result[i]<<" ";
		}
	return 0;
}

