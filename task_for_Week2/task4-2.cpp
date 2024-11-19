#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct ListNode {
	char val;
	struct ListNode *next;
}*List;

void printList(List node) {
	while(node->next != NULL){
		printf("%c", node->next->val);
		node = node->next;
	}
}

char top(List L){
	List tmp_node = L;
	while(tmp_node->next != NULL){
		tmp_node = tmp_node->next;
	}
	return tmp_node->val;
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
	List tmp_node = L;
	if(tmp_node->next==NULL) return;
	while(tmp_node->next->next != NULL){
		tmp_node = tmp_node->next;
	}
	free(tmp_node->next);
	tmp_node->next=NULL;
	return;
}

void push(List L, int new_val){
	List new_node = (List) malloc(sizeof(ListNode));//new List(0);
	new_node->val = new_val;
	List tmp_node = L;
	while(tmp_node->next != NULL){
		tmp_node = tmp_node->next;
	}
	new_node->next = tmp_node->next;
	tmp_node->next = new_node;
}

void Reverse(List L){
	List head,mid,end;
	head=L;
	mid=head->next;
	end=mid->next;
	mid->next=NULL;
	
	while(end->next!=NULL){
		mid=end;
		end=end->next;
		head=head->next;
		mid->next=head;
	}
	end->next=mid;
	L->next=end;
}


List Suffix( List L1, List L2 )
{
	// Your code here
	List l1,l2;
	l1 = (List) malloc(sizeof(ListNode));
	l2 = (List) malloc(sizeof(ListNode));
	l1->next=l2->next=NULL;
	
	while(top(L1)==top(L2)){
		push(l1,top(L1));
		pop(L1);
		pop(L2);
	}
	//printList(l1);
	//Reverse(l1);
	
	while(!isEmpty(l1)){
		push(l2,top(l1));
		pop(l1); 
	}
	return l2;
}

int main()
{
	List L1, L2;
	List P; // ´æ´¢×îÖÕ½á¹û 
	char str1[30], str2[30];
	int i;
	L1 = (List) malloc(sizeof(ListNode));
	L2 = (List) malloc(sizeof(ListNode));
	L1->next = L2->next = NULL; 
	
	scanf("%s", str1);
	scanf("%s", str2);
	for(i = 0; i < strlen(str1); i++)
	{
		push(L1, str1[i]);
	}
	for(i = 0; i < strlen(str2); i++)
	{
		push(L2, str2[i]);
	}
	P = Suffix(L1, L2);
	printList(P);
	return 0;
}

