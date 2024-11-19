#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
// Please add or modify any code whenever needed 
using namespace std;
int n,c[110][110],ans[110],max1[110],ma,visited[110];//ans 入度 
set<int,greater<int>>aa[110];//记录路径，并去重、排序
void bfs(int a,int m)//记录路径
{
    int i;
    for(i=1;i<=n;i++){
        if(c[i][a]!=-1&&m-c[i][a]==max1[i])
        {
            bfs(i,max1[i]);
            aa[i].insert(a);
        }
    }
}

void print2()//打印路径
{
    int i;
    set<int>::iterator it;
    for(i=0;i<110;i++)
        if(!aa[i].empty())
            for(it=aa[i].begin();it!=aa[i].end();it++)
                cout<<i<<"->"<<*it<<endl;
}
int main()
{
    queue<int>d;
    int a,b,e,f,g,h,flag=1;
    for(a=0;a<110;a++)
        for(b=0;b<110;b++)
            c[a][b]=-1;
    cin>>n>>b;
    while(b--)
    {
        cin>>e>>f>>g;
        c[e][f]=g;
        ans[f]++;
    }
    for(e=1;e<=n;e++)
        if(ans[e]==0)
            d.push(e);
    
    int count=0;
    while(!d.empty())//拓扑排序
    {
    	// Your code here
        int v=d.front();
		d.pop();
		
		//cout<<v<<" ";
		count++;
		for(int i=1;i<=n;i++){
			if(c[v][i]!=-1){	
			if(--ans[i]==0){
				d.push(i);
			}
			if(max1[i]<max1[v]+c[v][i]) max1[i]=max1[v]+c[v][i];
			if(max1[i]>ma){
				ma=max1[i];
				f=i;
			}
		}
		}
	}	
    
    if(count!=n) flag=false;//检查连通性
    
    
    if(flag)cout<<ma<<endl;
    else cout<<'0'<<endl;
    bfs(f,ma);
    print2();
}

