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
	tmp_node->next=new_node;
	new_node->val=val;
	new_node->next=NULL;
}
bool isEmpty(List l){
	if(l->next==NULL){
		return true;
	}
	else{
		return false;
	}
}


int top(List L){
	if(isEmpty(L)) return 0;
	List tmp_node=L;
	while(tmp_node->next->next!=NULL){
		tmp_node=tmp_node->next;
	}
	return tmp_node->val;
}



void pop(List L){
	if(isEmpty(L)) return;
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
   if(head==NULL) cout<<"NULL";
   while (head)
   {
      cout << head->val << ' ';
      head = head->next;
   }
}

List getSamepart(List l1,List l2,List l3){
	while(!isEmpty(l1)&&!isEmpty(l2)){
		//cout<<top(l1)<<" "<<top(l2)<<endl;
		if(top(l1)!=top(l2)){
			if(top(l1)>top(l2)){
		      pop(l1);		
			}
			else{
			 pop(l2);	
			}
		}
		else{
			//cout<<"111"<<endl;
			push(top(l1),l3);
			pop(l1);
			pop(l2);
		}
    }
    
     //traversal_List(l3);
	while(l3->next->next){
		push(top(l3),l2);
		pop(l3);
	}
	/*List tmp_node=l2;
	while(tmp_node->next->next!=NULL){
		tmp_node=tmp_node->next;
	}
	tmp_node->next=NULL;*/
	return l2;
}

/*void insert(int val,List L){
	List tmp_node=L;
	if(val==-1) return;
	while(tmp_node->next!=NULL&&val>tmp_node->next->val){
		if(val==tmp_node->val){
		return;
	}
		tmp_node=tmp_node->next;
	}
	
	
	List new_node=(List)malloc(sizeof(struct ListNode));
	new_node->val=val;
	List l=tmp_node->next;
	tmp_node->next=new_node;
	new_node->next=l; 
}*/

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
		//cout<<"1 ";
		scanf("%d",&n);
		push(n,L1);
	}while(n!=-1);
	
	//pop(L1);
	
		do{
		//cout<<"1 ";
		scanf("%d",&n);
		push(n,L2);
	}while(n!=-1);
	
	//pop(L2);	
	
	traversal_List(getSamepart(L1,L2,L3));
	cout << endl;
}


