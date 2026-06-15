#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = nullptr;
    }
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Creating cycle: 4 -> 2
    head->next->next->next->next = head->next;

    if (hasCycle(head))
        cout << "Cycle Present" << endl;
    else
        cout << "Cycle Not Present" << endl;

    return 0;
}
