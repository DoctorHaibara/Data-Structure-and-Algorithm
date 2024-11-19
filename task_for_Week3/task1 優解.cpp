#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


typedef struct ListNode {
	int val;
	ListNode *next;
}*List;

void push(int val,List L){
	List tmp_node=L;
	while(tmp_node->next){
		tmp_node=tmp_node->next;
	}
	List new_node=(List)malloc(sizeof(struct ListNode));
	new_node->next=NULL;
	tmp_node->next=new_node;
	new_node->val=val;
}

void traversal_List(ListNode* head)
{  
   head=head->next;
   if(!head) cout<<"NULL";
   while (head)
   {
      cout << head->val << ' ';
      head = head->next;
   }
}

List getSamepart(List l1,List l2,List l3){
	l1=l1->next;
	l2=l2->next;
	while(l1&&l2){
		if(l1->val==l2->val){
			push(l1->val,l3);
			l1=l1->next;
			l2=l2->next;
		}
		else if(l1->val<l2->val){
			l1=l1->next;
		}
		else{
			l2=l2->next;
		}
	}
		
	return l3;
}


int main()
{
    List L1,L2,L3;
	L1=(List)malloc(sizeof(struct ListNode));
	L2=(List)malloc(sizeof(struct ListNode));
	L3=(List)malloc(sizeof(struct ListNode));
	L1->val=L2->val=L3->val=0;
	L1->next=L2->next=L3->next=NULL;
	int n;
	do{
		scanf("%d",&n);
		if(n!=-1) push(n,L1);
	}while(n!=-1);
	
		do{
		scanf("%d",&n);
		if(n!=-1) push(n,L2);
	}while(n!=-1);
	
	traversal_List(getSamepart(L1,L2,L3));
	cout << endl;
}


