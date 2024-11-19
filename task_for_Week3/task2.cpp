#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


typedef struct ListNode {
	int val;
	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
}*List;

void push(int val,List L){
	List tmp_node=L;
	while(tmp_node->next!=NULL){
		tmp_node=tmp_node->next;
	}
	List new_node=(List)malloc(sizeof(struct ListNode));
	new_node->next=NULL;
	tmp_node->next=new_node;
	new_node->val=val;
}

void pop(List L){
	List tmp_node=L;
	while(tmp_node->next->next!=NULL){
		tmp_node=tmp_node->next;
	}
	free(tmp_node->next);
	tmp_node->next=NULL;
}

void traversal_List(ListNode* head)
{  
   head=head->next;
   while (head)
   {
      cout << head->val << ' ';
      head = head->next;
   }
}

void insert(int val,List L){
	List tmp_node=L;
	while(tmp_node->next&&val>=tmp_node->next->val){
	if(val==tmp_node->next->val){
		return;
	}
		tmp_node=tmp_node->next;
	}
	
	
	List new_node=(List)malloc(sizeof(struct ListNode));
	new_node->val=val;
	List l=tmp_node->next;
	tmp_node->next=new_node;
	new_node->next=l; 
}

int main()
{
    List L1,L2;
	L1=(List)malloc(sizeof(struct ListNode));
	L2=(List)malloc(sizeof(struct ListNode));
	L1->next=L2->next=NULL;
	int n;
	do{
		//cout<<"1 ";
		scanf("%d",&n);
		if(n!=-1) push(n,L1);
	}while(n!=-1);
	
	pop(L1);
	
		do{
		//cout<<"1 ";
		scanf("%d",&n);
		if(n!=-1) insert(n,L1);
	}while(n!=-1);	
	
	traversal_List(L1);
	cout << endl;
}


