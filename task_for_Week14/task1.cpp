#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10  /* ��󶥵�����Ϊ10 */
#define INFINITY 65535   /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;      /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;  /* �ߵ�Ȩֵ��Ϊ���� */

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* ������ */
    int Ne;  /* ����   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */
bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

MGraph CreateGraph(); 

void Visit( Vertex V )
{
    printf(" %d", V);
}

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    /* Your code here */
    Visit(V);
    Visited[V]=true;
	for(int i=0;i<7;i++){
		if(Graph->G[V][i]==1&&Visited[i]==false){
			DFS(Graph,i,Visit);
		}
	}
}


int main()
{
    MGraph G;
    Vertex V;

    G = CreateGraph();
    scanf("%d", &V);
    printf("DFS from %d:", V);
    DFS(G, V, Visit);

    return 0;
}

// Example graph
MGraph CreateGraph() 
{
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = 7;
	Graph->Ne = 9;
	for (V=0; V<Graph->Nv; V++)
	{   
		Visited[V] = false;
		for (W=0; W<Graph->Nv; W++)
			Graph->G[V][W] = 0;
	}
	Graph->G[0][3] = 1;
	Graph->G[3][0] = 1;
	Graph->G[0][2] = 1;
	Graph->G[2][0] = 1;
	Graph->G[0][4] = 1;
	Graph->G[4][0] = 1;
	Graph->G[0][4] = 1;
	Graph->G[2][3] = 1;
	Graph->G[3][2] = 1;
	Graph->G[1][3] = 1;
	Graph->G[3][1] = 1;
	Graph->G[1][5] = 1;
	Graph->G[5][1] = 1;
	Graph->G[2][5] = 1;
	Graph->G[5][2] = 1;
	Graph->G[4][5] = 1;
	Graph->G[5][4] = 1;
	Graph->G[5][6] = 1;
	Graph->G[6][5] = 1;
	return Graph;
}


