#include <iostream>
#include <queue>
using namespace std;
// You can add or change any code as you need
int num[1005];
queue<int> que;
bool dfs(int start, int end, bool flg) //1�� ������ < �� <= �������� 0�������� >= �� > ������ 
{
	// Your code here
	if(flg){
		if(end-start<=2){
			
			que.push(num[start+1]);
			if(end-start==2) que.push(num[end]);
			que.push(num[start]);
			
			if(num[start]>num[start+1]&&num[start]<=num[end]){
				return  true;
			}
			else{
				return false;
			}
		}
		else{
			int p=start+1;
		    while(num[p]<num[start]){
			    p++;
		    }
	    bool f=dfs(start+1,p-1,flg)&&dfs(p,end,flg);
	    que.push(num[start]);
		return f;
		}
		
    }
    else{
    	if(end-start<=2){
			
			que.push(num[start+1]);
			if(end-start==2) que.push(num[end]);
			que.push(num[start]);
			
			if(num[start]<num[start+1]&&num[start]>=num[end]){
				return  true;
			}
			else{
				return false;
			}
		}
		else{
			int p=start+1;
		    while(num[p]>=num[start]){
			    p++;
		    }
	    bool f=dfs(start+1,p-1,!flg)&&dfs(p,end,!flg);
	    que.push(num[start]);
		return f;
		}
	}
	
} 
void print()  //���������� 
{
	cout << "YES" << endl;
	bool first = true;
	while(!que.empty()){
		if(first)
			first = false;
		else
			cout << " ";
			int top = que.front();
			que.pop();
			cout << top;
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> num[i];	
	if(dfs(1, n, 1)){
		print();
		return 0;
	}
	else {   //������ǵ�һ�֣��ȰѶ�����գ�Ȼ���ܵڶ��� 
		while(!que.empty())
			que.pop();
	}
	if(dfs(1, n, 0)){
		print();
	}
	else{  //���������NO 
		cout << "NO" << endl;
    }
	return 0;
}

