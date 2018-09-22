struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if (pHead == NULL) return NULL;
    
}