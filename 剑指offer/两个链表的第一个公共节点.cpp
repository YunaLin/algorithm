// 可以使用栈来实现,利用栈的后进先出的特点,但是下面这种实现方法能够节省空间

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL || pHead2 == NULL) return NULL;
    int len1 = 0, len2 = 0;
    ListNode* ptr1 = pHead1;
    ListNode* ptr2 = pHead2;
    while (ptr1 != NULL) {
        len1++;
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        len2++;
        ptr2 = ptr2->next;
    }
    ptr1 = pHead1;
    ptr2 = pHead2;
    while (len1 > len2) {
        ptr1 = ptr1->next;
        len1--;
    }
    while (len2 > len1) {
        ptr2 = ptr2->next;
        len2--;
    }
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}