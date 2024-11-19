#include <iostream>
#define INF 1000
using namespace std;
char mp[100][100];
int vis[100][100];
int result=INF;
int sx,sy,zx,zy;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int n;
void dfs(int x,int y,int sum,int st){
	if(mp[x][y]=='B'){
		result=min(sum,result);
		return ;
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<n&&!vis[xx][yy]&&mp[xx][yy]!='x'){
			if(st==-1){//start node
				vis[xx][yy]=1;
				//cout<<xx<<" "<<yy<<" "<<sum<<endl;
				dfs(xx,yy,sum,i);
				vis[xx][yy]=0;
			}
			else if(st!=i){//need to take turn
				vis[xx][yy]=1;
				//cout<<xx<<" "<<yy<<" "<<sum<<endl;
				dfs(xx,yy,sum+1,i);
				vis[xx][yy]=0;
			}
			else {
				vis[xx][yy]=1;
				//cout<<xx<<" "<<yy<<" "<<sum<<endl;
				dfs(xx,yy,sum,i);
				vis[xx][yy]=0;
			}
		}
	}

}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++) cin>>mp[i][j];
    }
    for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++)
   			if(mp[i][j]=='A'){
		    	vis[i][j]=1;
   	    		dfs(i,j,0,-1);
   			}
    }
   if(result==INF) cout<<-1<<endl;
   else
   cout<<result<<endl;
   return 0;
}

/*
²Î¿¼ÊäÈë£º 
3
A x B
. . .
x x .


»ò 
6
A . x x x x
. . . . . x
x . x x . x
x . . x x x
x x . . . x
x x x x B x

*/

