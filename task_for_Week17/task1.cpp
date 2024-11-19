#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
// Please add or modify any code whenever needed 

struct AdjNode
{
	string data;
	int index;
	AdjNode* next;
};

struct AdjList
{
	AdjNode node;
	bool isvisted;
};

class DAG
{
public:
	DAG();        //初始化
	~DAG();      
	void Topo_Sort();    //输出所有拓扑序列
protected:
	void Topo_Sort(vector<string>& order);  // 你要实现的函数   //递归回溯 或 其它能达到效果的实现方法 
	bool isAcyclic();                          //拓扑排序判断是否为无环图
	void DEL();                               //delete动态分配内存
private:
	struct AdjList* list;                 //邻接表
	int V_num;                            //顶点数
	int *In_degree;                      //各点入度
};


void DAG::DEL()
{
	for (int i = 1; i <= V_num; i++)
	{
		while (list[i].node.next != NULL)
		{
			AdjNode* p = new AdjNode;
			p = list[i].node.next;
			list[i].node.next = p->next;
			delete p;
		}
	}
	delete[]list;
	delete[]In_degree;
}

bool DAG::isAcyclic() 
{
	stack<int>  s;
	int count = 0;
	int *In = new int[V_num + 1];
	for (int i = 1; i <= V_num; i++)
	{
		In[i] = In_degree[i];
	}
	for (int i = 1; i <= V_num; i++)
		if (In[i] == 0) s.push(i);
	while (!s.empty())
	{
		int temp=s.top();
		s.pop();
		count++;
		AdjNode* p = list[temp].node.next;
		while (p != NULL)
		{
			In[p->index]--;
			if (In[p->index] == 0) s.push(p->index);
			p = p->next;
		}
	}
	delete[]In;
	return count == V_num;
}

DAG::DAG()
{
L1:
//	cout << "请输入所有顶点数:";
	cin >> V_num;
	list = new AdjList[V_num + 1];
	In_degree = new int[V_num + 1];
	memset(In_degree, 0, (V_num + 1) * sizeof(int));
//	cout << "请依次输入每个顶点的名称:" << endl;
	for (int i = 1; i <= V_num; i++)
	{
		cin >> list[i].node.data;
		list[i].node.index = i;
		list[i].node.next = NULL;
	}
	for (int i = 1; i <= V_num; i++)
	{
		int size;
//		cout << "请输入第" << i << "个顶点的指向顶点的数量:";
		cin >> size;
		for (int j = 1; j <= size; j++)
		{
			int index;
//			cout << "请输入第" << j << "个邻接点的编号:";
			cin >> index;
			In_degree[index]++;
			AdjNode* p = new AdjNode;
			p->index = index;
			p->next = list[i].node.next;
			list[i].node.next = p;
		}
	}
	if (isAcyclic()) cout << "经拓扑排序检测，输入信息符合无环图" << endl;
	else
	{
		DEL();
		cout << "经拓扑排序检测，输入信息不符合无环图,请重新输入" << endl;
		goto L1;
	}
}

DAG::~DAG()
{
	DEL();
}


void DAG::Topo_Sort()
{
	vector<string>order;
	for (int i = 1; i <= V_num; i++)
	{
		list[i].isvisted = false;
	}
	// 这里调用了你要实现的函数 
	Topo_Sort(order);
}
void DAG::Topo_Sort(vector<string>& order)
{
    for (int i=1;i<=V_num; i++){
        if(!list[i].isvisted&&In_degree[i]==0){
            order.push_back(list[i].node.data);
            list[i].isvisted = true;
            AdjNode* p = list[i].node.next;
            while(p){
                In_degree[p->index]--;
                p=p->next;
            }

            Topo_Sort(order);

            order.pop_back();
            list[i].isvisted=false;
            p=list[i].node.next;
            while(p){
                In_degree[p->index]++;
                p = p->next;
            }
        }
    }

    if(order.size()==V_num){
        for (int i=0;i<order.size();i++){
            cout<<order[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
	DAG graph;
	cout << "该图所有拓扑序列为：" << endl;
	// 这里调用了你要实现的函数 
	graph.Topo_Sort();
	return 0;
}

