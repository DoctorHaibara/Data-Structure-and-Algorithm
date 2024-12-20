#include <stdio.h>
#include<math.h>
#include<malloc.h>
#include <iostream>
using namespace std;
// You can add or modify any code when needed

#define MAXTABLESIZE 100000  /* 允许开辟的最大散列表长度 */
typedef int ElementType;     /* 关键词类型用整型 */
typedef int Index;           /* 散列地址类型 */
typedef Index Position;      /* 数据所在位置与散列地址是同一类型 */
/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */
typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell; /* 散列表单元类型 */
struct HashEntry{
    ElementType Data; /* 存放元素 */
    EntryType Info;   /* 单元状态 */
};

typedef struct TblNode *HashTable; /* 散列表类型 */
struct TblNode {   /* 散列表结点定义 */
    int TableSize; /* 表的最大长度 */
    Cell *Cells;   /* 存放散列单元数据的数组 */
};

HashTable BuildTable() 
{
	int M, data;
	scanf("%d",&M);
	HashTable H;
    int i;
    /* 分配散列表 */
	H = (struct TblNode *)malloc(sizeof(struct TblNode));
	H->TableSize = M;
    /* 分配散列表 Cells */
	H->Cells = (Cell *)malloc(sizeof(Cell) * H->TableSize );
    for(i = 0; i < H->TableSize; i++ ){
		scanf("%d",&data);
		if(data == -1) H->Cells[i].Info = Empty;
		else {
			H->Cells[i].Info = Legitimate;
			H->Cells[i].Data = data;
		}
	}
    return H;
}

Position Hash( ElementType Key, int TableSize )
{
    return (Key % TableSize);
}

#define ERROR -1
Position Find( HashTable H, ElementType Key )
{
	// Your code here
	int index=Hash(Key,H->TableSize);
	while(H->Cells[index].Info!=Empty&&H->Cells[index].Data!=Key){
		index=(index+1)%H->TableSize;
		//std::cout<<index<<" "<<H->Cells[index].Data<<std::endl;
	} 
	
	if(H->Cells[index].Info!=Empty&&H->Cells[index].Data!=Key){
		return ERROR;
	}
	else{
		return index;
	}
    
}

int main()
{
    HashTable H;
    ElementType Key;
    Position P;

    H = BuildTable(); 
    scanf("%d", &Key);
    P = Find(H, Key);
    if (P==ERROR)
        printf("ERROR: %d is not found and the table is full.\n", Key);
    else if (H->Cells[P].Info == Legitimate)
        printf("%d is at position %d.\n", Key, P);
    else
        printf("%d is not found.  Position %d is returned.\n", Key, P);
    return 0;
}




