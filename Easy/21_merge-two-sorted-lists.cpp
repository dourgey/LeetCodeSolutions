
 #include <cstddef>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
/*
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode merge(-1);
		ListNode* newList = &merge;
		ListNode* p = newList;

		while(l1 != NULL && l2 != NULL){
			if(l1->val > l2->val){
				newList->next = l2;
				l2 = l2->next;
			}
			else{
				newList->next = l1;
				l1 = l1->next;
			}
			newList = newList->next;
		}
		if(l1 == NULL) newList->next = l2;
		else newList->next = l1;
		return p->next;
	}
};
*/
// µ›πÈ–¥∑®
#include <cstddef>

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;
		else if (l1->val > l2->val) {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
		else {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
	}
};
