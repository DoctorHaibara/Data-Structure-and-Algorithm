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
	DAG();        //��ʼ��
	~DAG();      
	void Topo_Sort();    //���������������
protected:
	void Topo_Sort(vector<string>& order);  // ��Ҫʵ�ֵĺ���   //�ݹ���� �� �����ܴﵽЧ����ʵ�ַ��� 
	bool isAcyclic();                          //���������ж��Ƿ�Ϊ�޻�ͼ
	void DEL();                               //delete��̬�����ڴ�
private:
	struct AdjList* list;                 //�ڽӱ�
	int V_num;                            //������
	int *In_degree;                      //�������
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
//	cout << "���������ж�����:";
	cin >> V_num;
	list = new AdjList[V_num + 1];
	In_degree = new int[V_num + 1];
	memset(In_degree, 0, (V_num + 1) * sizeof(int));
//	cout << "����������ÿ�����������:" << endl;
	for (int i = 1; i <= V_num; i++)
	{
		cin >> list[i].node.data;
		list[i].node.index = i;
		list[i].node.next = NULL;
	}
	for (int i = 1; i <= V_num; i++)
	{
		int size;
//		cout << "�������" << i << "�������ָ�򶥵������:";
		cin >> size;
		for (int j = 1; j <= size; j++)
		{
			int index;
//			cout << "�������" << j << "���ڽӵ�ı��:";
			cin >> index;
			In_degree[index]++;
			AdjNode* p = new AdjNode;
			p->index = index;
			p->next = list[i].node.next;
			list[i].node.next = p;
		}
	}
	if (isAcyclic()) cout << "�����������⣬������Ϣ�����޻�ͼ" << endl;
	else
	{
		DEL();
		cout << "�����������⣬������Ϣ�������޻�ͼ,����������" << endl;
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
	// �����������Ҫʵ�ֵĺ��� 
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
	cout << "��ͼ������������Ϊ��" << endl;
	// �����������Ҫʵ�ֵĺ��� 
	graph.Topo_Sort();
	return 0;
}

