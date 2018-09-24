// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
#include <iostream>
#include <map>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

void print(ListNode* pHead) {
    if (pHead == NULL) return;
    while (pHead != NULL) {
        cout << pHead->val << "->";
        pHead = pHead->next;
    }
    cout << "NULL" << endl;
    return;
}

ListNode* deleteDuplication(ListNode* pHead)
{
    if (pHead == NULL || pHead->next == NULL) return pHead;
    ListNode* temp = pHead;
    int n = 0;
    map<int, int> mymap;
    while (temp != NULL) {
        n++;
        mymap.insert(pair<int, int>(temp->val, 0));
        temp = temp->next;
    }
    temp = pHead;
    // 先遍历一遍,存储每个数值是否重复
    while (temp != NULL) {
        if (mymap[temp->val] == 0) {
            mymap[temp->val]++;
        } else if (mymap[temp->val] == 1) {
            mymap[temp->val] = -1;
        } else {}
        temp = temp->next;
    }
    temp = pHead;
    ListNode* todelete = pHead;
    // 开始结点出现重复的处理
    while (temp != NULL) {
        if (mymap[temp->val] == -1) {
            todelete = temp;
            temp = temp->next;
            delete todelete;
            pHead = temp;
        } else {
            break;
        }
    }
    pHead = temp;
    if (pHead == NULL) return pHead;
    // 非开始结点出现重复的处理
    while (temp->next != NULL) {
        if (mymap[temp->next->val] == -1) {
            todelete = temp->next;
            temp->next = todelete->next;
            delete todelete;
        } else {
            temp = temp->next;
        }
    }
    return pHead;
}

int main() {
    ListNode* pHead = NULL;
    ListNode* head = NULL;
    int n,  num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (i == 0) {
            pHead = new ListNode(num);
            head = pHead;
        } else {
            pHead->next = new ListNode(num);
            pHead = pHead->next;
        }
    }
    print(head);
    print(deleteDuplication(head));
    return 0;
}
