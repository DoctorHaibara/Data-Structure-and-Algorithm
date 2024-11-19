#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct ListNode{
  int val;
  struct ListNode* next;
}*List;

void push(List L,int n){
	List new_node=(List)malloc(sizeof(ListNode));
	new_node->val=n;
	List l;
	l=L->next;
	L->next=new_node;
	new_node->next=l;
}

int top(List L){
	return L->next->val;
}

bool isEmpty(List L){
	if(L->next==NULL){
		return true;
	}
	else{
		return false;
	}
}

void pop(List L){
	if(isEmpty(L)){
		return;
	}
	List tmp_node=L->next;
	L->next=tmp_node->next;
	free(tmp_node);
}

void printList(List L){
	//cout<<"from top to bottom"<<endl;
	List tmp_node=L->next;
	//if(tmp_node==NULL) cout<<"the list is empty!"<<endl; 
	while(tmp_node!=NULL){
		//cout<<tmp_node->val<<" ";
		tmp_node=tmp_node->next;
	}
	cout<<endl;
}

int main(){
	List l=(List)malloc(sizeof(ListNode));
	l->next=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n/2;i++){
		int t;
		scanf("%d",&t);
		push(l,t);
	}
	printList(l);
	if(n%2==1){
		int t;
		scanf("%d",&t);
	}
	for(int i=0;i<n/2;i++){
		int t;
		scanf("%d",&t);
		if(t==top(l)){
			//cout<<"yes!";
			pop(l);
		}
	}
	printList(l);
	
	if(isEmpty(l)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
}
