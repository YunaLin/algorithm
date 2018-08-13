// 反转链表
ListNode* ReverseList(ListNode* pHead) {
    if (pHead == NULL || pHead ->next == NULL) return pHead;
    ListNode* newHead = pHead; 
    pHead = pHead->next;
    ListNode* temp = pHead;
    // 注意点一
    newHead->next = NULL;
    // 注意点二：括号内判断条件
    while (pHead->next != NULL) {
        temp = pHead->next;
        pHead->next = newHead;
        newHead = pHead;
        pHead = temp;
    }
    // 注意点三
    pHead->next = newHead;
    newHead = pHead;
    return newHead;
}