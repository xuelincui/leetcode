
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


ListNode* reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* forward = curr->next;

    while (curr->next != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = forward;
        forward = curr->next;
    }

    curr->next = prev;

    return curr;
}


int main()
{

    ListNode* list_node = new ListNode(1);

    for (int i = 2; i <= 10; i++)
    {
        insertAtEnd( list_node, i);
    }

    list_node = reverseList(list_node);

    displayList( list_node);

    delete list_node;

    return 0;
}