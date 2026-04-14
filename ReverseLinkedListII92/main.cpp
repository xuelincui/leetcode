
#include <vector>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to display the linked list
void displayList(ListNode* head)
{
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

ListNode* insertAtEnd(ListNode* head, int value)
{
    ListNode* newNode = new ListNode(value);

    if (head == nullptr)
    {
        return newNode;
    }

    ListNode* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    int N = 0;
    ListNode* curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {
        curr = curr->next;
        N++;
    }

    if (N < left || N < right)
        return head;

    curr = head;
    ListNode* prev = nullptr;
    ListNode* forward = curr->next;

    int n = left;
    for (int i = 0; i < n; i++)
    {
        curr = curr->next;
    }

    while (n < right)
    {
        curr->next = prev;
        prev = curr;
        curr = forward;
        forward = curr->next;
        n++;
    }

    curr->next = prev;

    return curr;
}


// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
//
// Example 2://
// Input: head = [5], left = 1, right = 1
// Output: [5]

int main()
{

    ListNode* list_node = new ListNode(1);

    for (int i = 2; i <= 10; i++)
    {
        insertAtEnd( list_node, i);
    }

    list_node = reverseBetween(list_node, 1,3);


    displayList( list_node);

    delete list_node;

    return 0;
}