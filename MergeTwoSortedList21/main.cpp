#include <iostream>



// Definition for singly-linked list.
struct ListNode
{
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{

    ListNode dummy(0);

    ListNode* current_node = &dummy;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            current_node->next = list1;
            list1 = list1->next;
        }
        else
        {
            current_node->next = list2;
            list2 = list2->next;
        }

        current_node = current_node->next;
    }

    // if current_node at list 1, and it has been exhausted, then pick up
    // remainning part of list 2
    if (list1 == nullptr)
    {
        current_node->next = list2;
    }
    else
    {
        current_node->next = list1;
    }

    current_node = &dummy;
    return current_node->next;

}


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

int main() {


    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);


    ListNode* ret_list = mergeTwoLists( list1,  list2);


    while (ret_list != nullptr)
    {
        std::cout << ret_list->val << " ";
        ret_list = ret_list->next;
    }

    delete list1;
    delete list2;

    return 0;
}