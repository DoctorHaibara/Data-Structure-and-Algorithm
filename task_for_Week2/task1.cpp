#include <iostream>
#include <stdio.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	// Your code here
	ListNode* head=l1;
	while (head->next)
   {
      head = head->next;
   }
   head->next=l2;
	return l1; 
	return NULL;
}

void traversal_List(ListNode* head)
{
   while (head)
   {
      cout << head->val << ' ';
      head = head->next;
   }
}

int main()
{
	// Ê¾Àı²âÊÔÓÃÀı 1
	ListNode list1_1(1); 
	ListNode list1_2(2);
	
	ListNode list2_1(1);
	ListNode list2_2(3);
	ListNode list2_3(4);
	
	list1_1.next = &list1_2;
	list1_2.next = NULL;
	
	list2_1.next = &list2_2;
	list2_2.next = &list2_3;
	list2_3.next = NULL;

	cout << "list1:";
	traversal_List(&list1_1);
	cout << endl;
	cout << "list2:";
	traversal_List(&list2_1);
	cout << endl;
	
	ListNode* res1 = mergeTwoLists(&list1_1, &list2_1);
	cout << "merged list:"; 
	traversal_List(res1);
	
	// Ê¾Àı²âÊÔÓÃÀı 2
	cout << endl;
	ListNode list1;
	ListNode list2(0);

	cout << "list []";;
	cout << endl;
	cout << "list [0]:";
	cout << endl;
	
	ListNode* res2 = mergeTwoLists(&list1, &list2);
	cout << "merged list:"; 
	traversal_List(res2); // expected: [0 0]; because when cout a NULL Pointer, it would print a 0.
	cout << endl;
}


