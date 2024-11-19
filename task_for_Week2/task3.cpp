#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct ListNode {
	int val;
	struct ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
}*List;


int _length(List L){
	int count=0;
	List current = L;
	while(current->next!=NULL){
		current=current->next;
		count++;
	}
	return count;
}

List search(List L,int n){
	int count=0;
	List current=L;
	while(count<n){
		current=current->next;
		count++;
	}
	//cout<<current->val<<" "<<count<<" ";
	return current; 
}

void Reverse(List p1,List p2){
	List head,mid,end;
	head=p1;
	mid=head->next;
	end=mid->next;
	
	while(end!=p2){
		head=mid;
		mid=end;
		end=end->next;
		mid->next=head;
	}
	
	p1->next->next=end;
	p1->next=mid;
	
}

void K_Reverse(List L, int K ) {
	// 输入L，操作后，直接改变L，无需返回什么 
    // Your code here
    int length=_length(L);
    for(int i=1;i<length-K;i+=K){
    	Reverse(search(L,i-1),search(L,i+K));
	}
}

/*List K_Reverse(List L, int K ) {
	List current = L;
	List next;
	List prev = NULL;
	int count = 0;
	
	while (current != NULL && count < K){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	
	if(next != NULL){
		L->next = K_Reverse(next, K);
	}
	
	return prev;
}*/

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

void printList(List node) {
	while(node->next != NULL){
		printf("%d ", node->next->val);
		node = node->next;
	}
}

int main()
{
	int n, i, K, input_val;
	List L = new ListNode();
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &input_val);
		push(L, input_val);
	}
	//printList(L);
	scanf("%d", &K);
	K_Reverse(L, K); 
	printList(L);
	return 0;
}

