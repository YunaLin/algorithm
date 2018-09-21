// struct RandomListNode {
//     int label;
//     struct RandomListNode *next, *random;
//     RandomListNode(int x) :
//             label(x), next(NULL), random(NULL) {
//     }
// };
RandomListNode* Clone(RandomListNode* pHead)
{
    // 从A->B->C先得到A->A'->B->B'->C->C'
    // 然后将random指针就位
    // 最后得到A'->B'->C'
    if (pHead == NULL) return NULL;
    RandomListNode* ptr = pHead;
    while (ptr != NULL) {
        RandomListNode* temp = new RandomListNode(ptr->label);
        temp->next = ptr->next;
        ptr->next = temp;
        ptr = temp->next;
    }
    ptr = pHead;
    while (ptr != NULL) {
        if (ptr->random != NULL)
            ptr->next->random = ptr->random->next;
        ptr = ptr->next->next;
    }
    RandomListNode *pCloneHead = pHead->next;
    RandomListNode *tmp;
    ptr = pHead;
    while(ptr->next) {
        tmp = ptr->next;
        ptr->next =tmp->next;
        ptr = tmp;
    }
    return pCloneHead;
}