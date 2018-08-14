// 打印输出链表的倒数第k个数
// 让两个指针指向head,然后一个指针先走k步后两个指针一起走知道先走的那个指针指向空,此时后走的指针指向的就是倒数第k个数
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    int n = 0;
    ListNode* temp = pListHead;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    if (n < k) return NULL;
    int count = 0;
    ListNode* front = pListHead;
    ListNode* back = pListHead;
    while (count < k) {
        front = front->next;
        count++;
    }
    while (front != NULL) {
        front = front->next;
        back = back->next;
    }
    return back;
}