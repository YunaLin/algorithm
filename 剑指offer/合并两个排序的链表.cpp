/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode* head = NULL;
    ListNode* result = NULL;
    // 首先考虑链表为空的情况
    if (pHead1 == NULL) return pHead2;
    if (pHead2 == NULL) return pHead1;
    // 考虑第一个节点
    if (pHead1->val > pHead2->val) {
        head = new ListNode(pHead2->val);
        pHead2 = pHead2->next;
    } else {
        head = new ListNode(pHead1->val);
        pHead1 = pHead1->next;
    }
    result = head;
    while (pHead1 != NULL && pHead2 != NULL) {
        if (pHead1->val > pHead2->val) {
            head->next = new ListNode(pHead2->val);
            pHead2 = pHead2->next;
        } else {
            head->next = new ListNode(pHead1->val);
            pHead1 = pHead1->next;
        }
        head = head->next;
    }
    // 比较后剩下的节点
    while (pHead1 != NULL) {
        head->next = new ListNode(pHead1->val);
        pHead1 = pHead1->next;
        head = head->next;
    }
    while (pHead2 != NULL) {
        head->next = new ListNode(pHead2->val);
        pHead2 = pHead2->next;
        head = head->next;
    }
    return result;
}