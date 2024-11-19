#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10  /* 最大顶点数设为10 */
#define INFINITY 65535   /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;      /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;  /* 边的权值设为整型 */

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */
bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

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


