#include <stdio.h>
#include<math.h>
#include<malloc.h>
#include <iostream>
using namespace std;
// You can add or modify any code when needed

#define MAXTABLESIZE 100000  /* �����ٵ����ɢ�б��� */
typedef int ElementType;     /* �ؼ������������� */
typedef int Index;           /* ɢ�е�ַ���� */
typedef Index Position;      /* ��������λ����ɢ�е�ַ��ͬһ���� */
/* ɢ�е�Ԫ״̬���ͣ��ֱ��Ӧ���кϷ�Ԫ�ء��յ�Ԫ������ɾ��Ԫ�� */
typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell; /* ɢ�б�Ԫ���� */
struct HashEntry{
    ElementType Data; /* ���Ԫ�� */
    EntryType Info;   /* ��Ԫ״̬ */
};

typedef struct TblNode *HashTable; /* ɢ�б����� */
struct TblNode {   /* ɢ�б��㶨�� */
    int TableSize; /* �����󳤶� */
    Cell *Cells;   /* ���ɢ�е�Ԫ���ݵ����� */
};

HashTable BuildTable() 
{
	int M, data;
	scanf("%d",&M);
	HashTable H;
    int i;
    /* ����ɢ�б� */
	H = (struct TblNode *)malloc(sizeof(struct TblNode));
	H->TableSize = M;
    /* ����ɢ�б� Cells */
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




