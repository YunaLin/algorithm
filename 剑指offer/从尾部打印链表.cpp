#include <iostream>
#include <vector>
using namespace std; 

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL) {}
};
// 使用反转链表实现 
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> result;
    if (head == NULL) return result;
    ListNode* newHead = head;
    head = head->next;
    ListNode* temp = head;
    newHead->next = NULL;
    if (temp != NULL) {        
        while (head->next != NULL) {
            temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        head->next = newHead;
        newHead = head;
    }
    while (newHead != NULL) {
        result.push_back(newHead->val);
        newHead = newHead->next;
    }
    return result;
}

int main() {
	ListNode* head = new ListNode(1);
	int n;
	cin >> n;
	int num;
	while (n--) {
		cin >> num;
		head->next = new ListNode(num);
	}
	vector<int> result = printListFromTailToHead(head);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
