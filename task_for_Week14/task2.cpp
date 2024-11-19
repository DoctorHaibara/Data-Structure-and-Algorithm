#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define MaxVertexNum 10   /* 最大顶点数设为10 */
int count=0;
typedef int Vertex;       /* 用顶点下标表示顶点,为整型 */

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* 邻接点下标 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MaxVertexNum];     /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

LGraph CreateGraph(); 

void Visit( Vertex V )
{
    printf(" %d", V);
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    /* Your code here */
    //vector<Vertex> vec;
    if(count==Graph->Nv) return;
	if(Visited[S]==false){
		Visit(S);
    	Visited[S]=true;
    	count++;
	}
	
    PtrToAdjVNode p=Graph->G[S].FirstEdge;
    while(p){
    	if(Visited[p->AdjV]==false){
    		Visit(p->AdjV);
    		Visited[p->AdjV]=true;
    		count++;
		}
		p=p->Next;
	}
	
	p=Graph->G[S].FirstEdge;
	while(p){
		BFS(Graph,p->AdjV,Visit);
		p=p->Next;
	}
}

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}

// Example graph 
LGraph CreateGraph() 
{
	Vertex V, W;
	LGraph Graph;
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = 7;
	Graph->Ne = 9;
	for (V=0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	PtrToAdjVNode NewNode1;
	NewNode1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode1->AdjV = 3;
	NewNode1->Next = Graph->G[0].FirstEdge;
	Graph->G[0].FirstEdge = NewNode1; 
	PtrToAdjVNode NewNode2;
	NewNode2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode2->AdjV = 0;
	NewNode2->Next = Graph->G[3].FirstEdge;
	Graph->G[3].FirstEdge = NewNode2; 
	
	PtrToAdjVNode NewNode3;
	NewNode3 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode3->AdjV = 2;
	NewNode3->Next = Graph->G[0].FirstEdge;
	Graph->G[0].FirstEdge = NewNode3; 
	PtrToAdjVNode NewNode4;
	NewNode4 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode4->AdjV = 0;
	NewNode4->Next = Graph->G[2].FirstEdge;
	Graph->G[2].FirstEdge = NewNode4; 
	
	PtrToAdjVNode NewNode5;
	NewNode5 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode5->AdjV = 4;
	NewNode5->Next = Graph->G[0].FirstEdge;
	Graph->G[0].FirstEdge = NewNode5; 
	PtrToAdjVNode NewNode6;
	NewNode6 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode6->AdjV = 0;
	NewNode6->Next = Graph->G[4].FirstEdge;
	Graph->G[4].FirstEdge = NewNode6; 
	
	PtrToAdjVNode NewNode7;
	NewNode7 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode7->AdjV = 3;
	NewNode7->Next = Graph->G[2].FirstEdge;
	Graph->G[2].FirstEdge = NewNode7; 
	PtrToAdjVNode NewNode8;
	NewNode8 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode8->AdjV = 2;
	NewNode8->Next = Graph->G[3].FirstEdge;
	Graph->G[3].FirstEdge = NewNode8; 
	
	PtrToAdjVNode NewNode9;
	NewNode9 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode9->AdjV = 3;
	NewNode9->Next = Graph->G[1].FirstEdge;
	Graph->G[1].FirstEdge = NewNode9; 
	PtrToAdjVNode NewNode10;
	NewNode10 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode10->AdjV = 1;
	NewNode10->Next = Graph->G[3].FirstEdge;
	Graph->G[3].FirstEdge = NewNode10; 
	
	PtrToAdjVNode NewNode11;
	NewNode11 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode11->AdjV = 2;
	NewNode11->Next = Graph->G[5].FirstEdge;
	Graph->G[5].FirstEdge = NewNode11; 
	PtrToAdjVNode NewNode12;
	NewNode12 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode12->AdjV = 5;
	NewNode12->Next = Graph->G[2].FirstEdge;
	Graph->G[2].FirstEdge = NewNode12; 
	
	PtrToAdjVNode NewNode13;
	NewNode13 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode13->AdjV = 1;
	NewNode13->Next = Graph->G[5].FirstEdge;
	Graph->G[5].FirstEdge = NewNode13; 
	PtrToAdjVNode NewNode14;
	NewNode14 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode14->AdjV = 5;
	NewNode14->Next = Graph->G[1].FirstEdge;
	Graph->G[1].FirstEdge = NewNode14; 
	
	PtrToAdjVNode NewNode15;
	NewNode15 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode15->AdjV = 4;
	NewNode15->Next = Graph->G[5].FirstEdge;
	Graph->G[5].FirstEdge = NewNode15; 
	PtrToAdjVNode NewNode16;
	NewNode16 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode16->AdjV = 5;
	NewNode16->Next = Graph->G[4].FirstEdge;
	Graph->G[4].FirstEdge = NewNode16; 
	
	PtrToAdjVNode NewNode17;
	NewNode17 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode17->AdjV = 6;
	NewNode17->Next = Graph->G[5].FirstEdge;
	Graph->G[5].FirstEdge = NewNode17; 
	PtrToAdjVNode NewNode18;
	NewNode18 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode18->AdjV = 5;
	NewNode18->Next = Graph->G[6].FirstEdge;
	Graph->G[6].FirstEdge = NewNode18; 
	
	return Graph;
}

