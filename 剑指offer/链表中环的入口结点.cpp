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
ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if (pHead == NULL) return NULL;
    map<ListNode*, int> mymap;
    ListNode* temp = pHead;
    int count = 0;
    while (temp != NULL && count < 100) {
        mymap.insert(pair<ListNode*, int>(temp, 0));
        temp = temp->next;
        count++;
    }
    temp = pHead;
    while (temp != NULL) {
        if (mymap[temp] == 1) {
            return temp;
        } else {
            mymap[temp] = 1;
        }
        temp = temp->next;
    }
    return NULL;
}
int main() {
    return 0;
}