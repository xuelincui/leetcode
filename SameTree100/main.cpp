#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*

Input: p = [1,2,3], q = [1,2,3]
Output: true

*/


bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr )
       return true;

    if (q == nullptr || p == nullptr)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    // p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    // q->left = nullptr;
    q->right = new TreeNode(2);


    std::cout << "Hello, World!" << std::boolalpha <<isSameTree( p,  q)  <<std::endl;

    delete p;
    delete q;

    return 0;
}