#include <stdio.h>
#include <string.h>
#include<malloc.h>

#define KEYLENGTH 15                   /* �ؼ����ַ�������󳤶� */
typedef char ElementType[KEYLENGTH+1]; /* �ؼ����������ַ��� */
typedef int Index;                     /* ɢ�е�ַ���� */
// You can add or modify any code when needed

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable; /* ɢ�б����� */
struct TblNode {   /* ɢ�б��㶨�� */
    int TableSize; /* �����󳤶� */
    List Heads;    /* ָ������ͷ�������� */
};

Index Hash( ElementType Key, int TableSize )
{
    return (Key[0]-'a')%TableSize;
}


HashTable BuildTable() 
{   // Example input. (Optional: implement an Insert function for this) 
	HashTable H;  int i;
	H = (HashTable)malloc(sizeof(struct TblNode));  
	H->TableSize = 5;
	H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode)); 
	for( i=0; i<H->TableSize; i++ ) {
		H->Heads[i].Data[0] = '\0'; 
		H->Heads[i].Next = NULL;
	}
	Position NewCell;
	NewCell = (Position)malloc(sizeof(struct LNode));  
	strcpy(NewCell->Data, "key");
	NewCell->Next = H->Heads[0].Next;
	H->Heads[0].Next = NewCell;  
	
	NewCell = (Position)malloc(sizeof(struct LNode));  
	strcpy(NewCell->Data, "able");
	NewCell->Next = H->Heads[0].Next;
	H->Heads[0].Next = NewCell;  
	
	NewCell = (Position)malloc(sizeof(struct LNode));  
	strcpy(NewCell->Data, "zero");
	NewCell->Next = H->Heads[0].Next;
	H->Heads[0].Next = NewCell;  
	
	NewCell = (Position)malloc(sizeof(struct LNode));  
	strcpy(NewCell->Data, "bye");
	NewCell->Next = H->Heads[1].Next;
	H->Heads[1].Next = NewCell;  
	
	NewCell = (Position)malloc(sizeof(struct LNode));  
	strcpy(NewCell->Data, "very");
	NewCell->Next = H->Heads[1].Next;
	H->Heads[1].Next = NewCell;  
	
	NewCell = (Position)malloc(sizeof(struct LNode));  
	strcpy(NewCell->Data, "day");
	NewCell->Next = H->Heads[2].Next;
	H->Heads[2].Next = NewCell;  
	return H;
}

int Delete( HashTable H, ElementType Key );

int main()
{
    HashTable H;
    ElementType Key;

    H = BuildTable(); 
    scanf("%s", Key);
    if (Delete(H, Key) == -1)
        printf("ERROR: %s is not found\n", Key);
    else{
    	printf("%s is deleted from list Heads[%d]\n",Key,Delete(H, Key));
	}
        
    return 0;
}

int Delete( HashTable H, ElementType Key )
{ // Your code here 
    //search for the value
	for(int i=0;i<H->TableSize;i++){
		Position Cell=H->Heads[i].Next;
		while(Cell->Next!=NULL){//searching in a list
			if(strcmp(Cell->Data,Key)==0){//data found
				return i;
			}
			else{//data not found
				Cell=Cell->Next;
			}
			
		}
	} 
    return -1;
}

